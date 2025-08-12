#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct listNode {
    unsigned int row;
    unsigned int column;
    char letter;
    struct listNode* next;
} ListNode;

unsigned int hash(unsigned int column, unsigned int row);

bool right(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height);

int main(void) {
    
    // Set the random seed based on time.
    srand(time(NULL));

    // Get the grid length and height from user.
    unsigned int length;
    unsigned int height;
    printf("Enter the length: ");
    scanf("%u", &length);
    printf("Enter the height: ");
    scanf("%u", &height);
    getchar();

    // Make an array for a hash table.
    ListNode** letters = malloc(sizeof(ListNode*)* 50);
    for (int i = 0; i < 50; i++) {
        letters[i] = NULL;
    }

    // Get a word from the user.
    unsigned int wordSize = 4;
    char* word = malloc(sizeof(char) * 4);
    if (word == NULL) {
        printf("Error: malloc() returned NULL.");
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
                printf("Error: realloc() returned NULL.");
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

    right(letters, word, wordLength, length, height);
    
    // Print the grid.
    ListNode* node;
    ListNode* freeing;
    for (unsigned int row = 0; row < height; row++) {
        for (unsigned int column = 0; column < length; column++) {
            unsigned int hashIndex = hash(column, row);
            node = letters[hashIndex];
            if (node == NULL) {
                printf("%c ", 'A' + (rand() % 26));
            }
            else if (node->next == NULL) {
                if (node->column == column && node->row == row) {
                    printf("%c ", toupper(node->letter));
                    free(letters[hashIndex]);
                    letters[hashIndex] == NULL;
                }
                else {
                    printf("%c ", 'A' + (rand() % 26));
                }
            }
            else {
                if (node->column == column && node->row == row) {
                    printf("%c ", toupper(node->letter));
                    letters[hashIndex] = node->next;
                    free(node);
                }
                else {
                    while (node->next != NULL && !(node->next->column != column && node->next->row != row)) {
                        node = node->next;
                    }
                    if (node->next == NULL) {
                        printf("%c ", 'A' + (rand() % 26));
                    }
                    else {
                        printf("%c ", toupper(node->next->letter));
                        freeing = node->next;
                        node->next = freeing->next;
                        free(freeing);
                    }
                }
            }
        }
        printf("\n");
    }
    return 0;
}

unsigned int hash(unsigned int column, unsigned int row) {
    return (column + row) % 50;
}

bool right(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height) {
    if (wordLength > length) {
        return false;
    }
    
    unsigned int row = rand() % height;
    unsigned int column;

    if (wordLength < length) {
        column = rand() % (length - wordLength + 1);
    }
    else {
        column = 0;
    }

    ListNode* node;
    bool spotTaken = false;

    for (unsigned int i = 0; i < wordLength && spotTaken == false; i++) {
        node = letters[hash(column + i, row)];
        while (node != NULL && spotTaken == false) {
            if (!(node->column == column && node->row == row) || node->letter == word[i]) {
                node = node->next;
            }
            else {
                spotTaken = true;
            }
        }
    }

    if (spotTaken == true) {
        return false;
    }

    unsigned int hashIndex;
    for (unsigned int i = 0; i < wordLength; i++) {
        hashIndex = hash(column + i, row);
        node = letters[hashIndex];
        if (node == NULL) {
            letters[hashIndex] = malloc(sizeof(ListNode));
            if (letters[hashIndex] == NULL) {
                printf("Error: malloc() returned NULL.");
                return false;
            }
            letters[hashIndex]->column = column + i;
            letters[hashIndex]->row = row;
            letters[hashIndex]->letter = word[i];
            letters[hashIndex]->next = NULL;
        }
        else {
            while (node->next != NULL) {
                node = node->next;
            }
            node->next = malloc(sizeof(ListNode));
            node = node->next;
            if (node == NULL) {
                printf("Error: malloc() returned NULL.");
                return false;
            }
            node->column = column + i;
            node->row = row;
            node->letter = word[i];
            node->next = NULL;
        }
    }

    return 1;
}