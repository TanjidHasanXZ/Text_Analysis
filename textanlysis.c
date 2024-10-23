#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int characters;
    int words;
    int sentences;
    int syllables;
    double readability;
} properties;

/* Function prototypes */
void printTextProperties(properties);
int getCharacterCount(const char* text, char character);
int getNumberOfWords(const char* text);
int getNumberOfSentences(const char* text);
int getNumberOfSyllablesInWord(const char* word);
int getNumberOfSyllables(const char* text);
properties getTextProperties(const char* text);

/* Main function  */
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

int getCharacterCount(const char* text, char character) {
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == character) {
            count++;
        }
    }
    return count;
}

int getNumberOfWords(const char* text) {
    int count = 0;
    int inWord = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == ' ' || text[i] == '\n' || text[i] == '\t') {
            inWord = 0;
        }
        else if (!inWord) {
            inWord = 1;
            count++;
        }
    }
    return count;
}

int getNumberOfSentences(const char* text) {
    return getCharacterCount(text, '.') + getCharacterCount(text, ';') +
        getCharacterCount(text, '!') + getCharacterCount(text, '?');
}

int getNumberOfSyllablesInWord(const char* word) {
    int count = 0;
    int length = strlen(word);

    if (length <= 3) {
        return 1;  // Heuristic: short words are likely to have just 1 syllable
    }

    for (int i = 0; word[i] != '\0'; i++) {
        if (strchr("aeiouAEIOU", word[i])) {
            count++;
        }
    }
    return count > 0 ? count : 1;  // Ensure that every word has at least one syllable
}

int getNumberOfSyllables(const char* text) {
    int syllableCount = 0;
    char* copy = strdup(text);  // Allocate memory and duplicate the text

    if (copy == NULL) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }

    char* word = strtok(copy, " ");
    while (word != NULL) {
        syllableCount += getNumberOfSyllablesInWord(word);
        word = strtok(NULL, " ");
    }

    free(copy);  // Free the duplicated string
    return syllableCount;
}

properties getTextProperties(const char* text) {
    properties result;

    result.characters = (int)strlen(text);
    result.words = getNumberOfWords(text);
    result.sentences = getNumberOfSentences(text);
    result.syllables = getNumberOfSyllables(text);

    result.readability = 206.835 - 1.015 * (double)result.words / result.sentences
        - 84.6 * (double)result.syllables / result.words;
    return result;
}
