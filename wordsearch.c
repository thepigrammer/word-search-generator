#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main(void) {

    // Get the grid length and height from user.
    unsigned int length;
    unsigned int height;
    printf("Enter the length: ");
    scanf("%u", &length);
    printf("Enter the height: ");
    scanf("%u", &height);
    getchar();

    // Get a word from the user.
    unsigned int wordSize = 4;
    char *word = malloc(sizeof(char) * 4);
    if (word == NULL) {
        printf("Error: malloc returned NULL.");
        return 1;
    }

    unsigned int wordLength = 0;
    unsigned int i = 0;
    printf("Enter a word with at most %u characters: ", length);
    char letter = getchar();
    
    while (letter != '\n') {
        if (i == wordSize) {
            word = realloc(word, sizeof(char) * (wordSize * 2));
            if (word == NULL) {
                printf("Error: realloc returned NULL.");
                return 2;
            }
            wordSize *= 2;
        }
        word[i] = letter;
        wordLength++;
        i++;
        letter = getchar();
    }
    word[i] = '\0';

    // Set the random seed based on time.
    srand(time(NULL));

    // Store the row and column to put the word at.
    unsigned int wordRow = rand() % height;
    unsigned int wordColumn;
    if (length - wordLength != 0) {
        wordColumn = rand() % (length - wordLength + 1);
    }
    else {
        wordColumn = 0;
    }
        
    
    // Print the randomized grid.
    unsigned int wordIndex = 0;
    for (unsigned int i = 0; i < height; i++) {
        for (unsigned int j = 0; j < length; j++) {
            if (i == wordRow && wordIndex < wordLength && j == wordColumn + wordIndex) {
                printf("%c ", toupper(word[wordIndex]));
                wordIndex++;
            }
            else {
            printf("%c ", 'A' + (rand() % 26));
            }
        }
        printf("\n");
    }
}