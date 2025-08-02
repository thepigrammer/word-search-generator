#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main(void) {

    // Get the grid length and height from user.
    int length;
    int height;
    printf("Enter the length: ");
    scanf("%i", &length);
    printf("Enter the height: ");
    scanf("%i", &height);

    // Get a word from user to include in grid.
    char word[length + 1];
    printf("Enter a word with at most %i characters: ", length);
    scanf("%s", word);

    // Store the length of the word.
    int wordLength = 0;
    while (word[wordLength] != '\0') {
        wordLength++;
    }

    // Set the random seed based on time.
    srand(time(NULL));

    // Store the row and column to put the word at.
    int wordRow = rand() % height;
    int wordColumn;
    if (length - wordLength != 0) {
        wordColumn = rand() % (length - wordLength + 1);
    }
    else {
        wordColumn = 0;
    }
        
    
    // Print the randomized grid.
    int wordIndex = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < length; j++) {
            if (i == wordRow && wordIndex < wordLength && j == wordColumn + wordIndex) {
                printf("%c", toupper(word[wordIndex]));
                wordIndex++;
            }
            else {
            printf("%c", 'A' + (rand() % 26));
            }
        }
        printf("\n");
    }
}