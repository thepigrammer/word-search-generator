#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    // Get the length and width from user.
    int length;
    int height;
    printf("Enter the length: ");
    scanf("%i", &length);
    printf("Enter the height: ");
    scanf("%i", &height);

    // Set the random seed based on time for character generation.
    srand(time(NULL));
    
    // Print the word search.
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < length; j++) {
            printf("%c", 'A' + (rand() % 26));
        }
        printf("\n");
    }
}