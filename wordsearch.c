#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int length;
    int height;
    printf("Enter the length: ");
    scanf("%i", &length);
    printf("Enter the height: ");
    scanf("%i", &height);

    srand(time(NULL));
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < length; j++) {
            printf("%c", 'A' + (rand() % 26));
        }
        printf("\n");
    }
}