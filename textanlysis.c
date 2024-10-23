
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int characters;
	int words;
	int sentences;
	int syllables;
	double readability;
}properties;

/* Function prototypes (provided by examiner) */
void printTextProperties(properties);
int getCharacterCount(char* text, char character);
int getNumberOfWords(char* text);
int getNumberOfSentences(char* text);
int getNumberOfSyllablesInWord(char* word);
int getNumberOfSyllables(char* text);
properties getTextProperties(char* text);

/* Main function (provided by examiner) */
int main(void)
{
	// Simple test sentences
	char easy[] = "No one said; it would. be easy! AaEe IiOoUu?";

	// William Lyon Phelps: The Pleasure of Books
	char bookSpeech[] =
		"A borrowed book is like a guest in the house; it must be treated with punctiliousness, with a certain considerate formality. "
		"You must see that it sustains no damage; it must not suffer while under your roof. "
		"You cannot leave it carelessly, you cannot mark it, you cannot turn down the pages, you cannot use it familiarly. "
		"And then, some day, although this is seldom done, you really ought to return it.";

	// Determine text properties
	properties easyProperties = getTextProperties(easy);
	properties bookProperties = getTextProperties(bookSpeech);

	// Display results
	printf("\nTest string \"%s\":\n", easy);
	printTextProperties(easyProperties);

	printf("\nWilliam Lyon Phelps, The Pleasure of Books:\n");
	printTextProperties(bookProperties);

	getchar();
	return 0;
}

/* Print properties to the console (provided by examiner) */
void printTextProperties(properties textProperties)
{
	printf("Characters  : %d\n", textProperties.characters);
	printf("Words       : %d\n", textProperties.words);
	printf("Sentences   : %d\n", textProperties.sentences);
	printf("Syllables   : %d\n", textProperties.syllables);
	printf("Readability : %.1f out of 100\n", textProperties.readability);
}
int getCharacterCount(char* text, char character) {
	int count = 0;
	int length = strlen(text);
	for (int i = 0;i < length;i++)
	{
		if (text[i] == character)
		{
			count++;
		}
	}
	return count;
}

int getNumberOfWords(char* text) {
	int count = getCharacterCount(text, ' ');
	return count + 1;
}

int getNumberOfSentences(char* text) {
	return getCharacterCount(text, '.') + getCharacterCount(text, ';') + getCharacterCount(text, '!') + getCharacterCount(text, '?');
}

int getNumberOfSyllablesInWord(char* word) {
	int length = strlen(word);
	if (length <= 3)
		return 1;
	else
		return getCharacterCount(word, 'a') + getCharacterCount(word, 'A')
		+ getCharacterCount(word, 'e') + getCharacterCount(word, 'E')
		+ getCharacterCount(word, 'i') + getCharacterCount(word, 'I')
		+ getCharacterCount(word, 'o') + getCharacterCount(word, 'O')
		+ getCharacterCount(word, 'u') + getCharacterCount(word, 'U');
}

int getNumberOfSyllables(char* text) {
	int count=0;
	int length = strlen(text);
	char* copy;
	char* word;
	copy = (char*)malloc((length + 1) * sizeof(char));
	if (copy == NULL)
		exit(EXIT_FAILURE);

	strcpy(copy, text);
	word = strtok(copy," ");
	while (word != NULL)
	{
		count += getNumberOfSyllablesInWord(word);
		word = strtok(NULL, " ");
	}
	free(copy);
	return count;
}


properties getTextProperties(char* text) {
	properties result;
	
	result.characters = (int)strlen(text);
	result.words = getNumberOfWords(text);
	result.sentences = getNumberOfSentences(text);
	result.syllables = getNumberOfSyllables(text);
	result.readability = 206.835 - 1.015 * result.words / (double)result.sentences - 84.6 * result.syllables / (double)result.words;
	return result;
}

