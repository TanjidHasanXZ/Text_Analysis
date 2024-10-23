# Text Analysis

This project involves implementing an approximation of the **Flesch Reading Ease Score (FRES)** by fulfilling specific requirements.

## Flesch Reading Ease Score (FRES) Formula:
FRES = 206.835 - 1.015 * (Number of words / Number of sentences) - 84.6 * (Number of syllables / Number of words)


The formula evaluates text readability based on word, sentence, and syllable counts.

## Project Requirements

### Data Type

#### Requirement 1:
- Declare a structure containing four `int` variables and a `double` variable. The identifiers must match the usage in the provided function `printTextProperties()`.

#### Requirement 2:
- Define a data type called `properties` as an alias for the structure declared above.

### Statistical Analysis

#### Requirement 3:
- Implement `getCharacterCount()` which returns the number of occurrences of a specific character in a string.  
  Example: `getCharacterCount("challenge", 'e')` returns `2` (since the character 'e' occurs twice).

#### Requirement 4:
- Implement `getNumberOfWords()` which returns an estimation of the number of words in a string. Assume that words are separated by a blank space (`' '`). This function should use `getCharacterCount()`.

#### Requirement 5:
- Implement `getNumberOfSentences()` which returns an estimation of the number of sentences in a string. Sentences are assumed to end with the characters period (`.`), semicolon (`;`), exclamation mark (`!`), or question mark (`?`). This function should use `getCharacterCount()`.

#### Requirement 6:
- Implement `getNumberOfSyllablesInWord()` which returns an estimation of the number of syllables in a word, following these rules:
  - Words containing ≤ 3 characters have 1 syllable.
  - For words longer than 3 characters, the number of syllables corresponds to the number of vowels (`a, e, i, o, u`) in the word.

#### Requirement 7:
- Implement `getNumberOfSyllables()` which returns an estimation of the number of syllables in a string. You should:
  - Create a copy of the string.
  - Get a pointer to the first word in the copy using `strtok(copy, " ")`.
  - Continue getting the next words by calling `strtok(NULL, " ")` until no words remain.
  - Call `getNumberOfSyllablesInWord()` for each word to determine the syllable count.

#### Requirement 8:
- Implement `getTextProperties()` which returns a structure of type `properties` containing the following statistical values of the string passed to the function:
  - Number of characters
  - Number of words
  - Number of sentences
  - Number of syllables
  - Flesch Reading Ease Score (calculated using the formula above)

### Quality

#### Requirement 9:
- Exit the application with the value `EXIT_FAILURE` if memory allocation fails.

#### Requirement 10:
- Ensure there are no memory leaks in the program.

#### Requirement 11:
- Ensure that values in arrays passed to a function as an argument cannot be modified by the function.

---

## Expected Console Output

Below is an example of the expected console output based on the test cases provided in the `main()` function:

**Test String**: `"No one said; it would. be easy! AaEe IiOoUu?"`

**Test String**: `"William Lyon Phelps, The Pleasure of Books:"`


---

## Notes

- The FRES score gives a readability value between 0 and 100. Lower values correspond to more difficult texts.
- Use the functions implemented above to calculate the respective values required for the FRES formula.

---

