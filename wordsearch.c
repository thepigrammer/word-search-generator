#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>

// Definition for linked list node.
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

    // Create an array of NULL ListNode pointers on the heap for the hash table of letters.
    ListNode** letters = malloc(sizeof(ListNode*)* 50);
    for (int i = 0; i < 50; i++) {
        letters[i] = NULL;
    }

    // Create an array of chars on the heap to hold the word.
    unsigned int wordSize = 4;
    char* word = malloc(sizeof(char) * 4);
    if (word == NULL) {
        printf("Error: malloc() returned NULL.");
        return 1;
    }

    // wordLength will be incremented for every char received from the user.
    unsigned int wordLength = 0;

    // Prompt user and receive first char of word.
    printf("Enter a word with at most %u characters: ", length);
    char letter = getchar();
    
    // Put received char into word and take another. Repeat until user presses Enter.
    for (unsigned int i = 0; letter != '\n'; i++) {

        // Double the size of the word array if the amomunt of characters goes over the current size.
        if (i > wordSize) {
            word = realloc(word, sizeof(char) * (wordSize * 2));
            if (word == NULL) {
                printf("Error: realloc() returned NULL.");
                return 2;
            }
            wordSize *= 2;
        }

        word[i] = letter;
        wordLength++;
        letter = getchar();
    }

    // Call right() to store the word in the hash table as individual letters with their grid coordinates.
    right(letters, word, wordLength, length, height);
    
    // Space allocated for word is no longer needed.
    free(word);

    // Create variables used for linked list traversal and node freeing.
    ListNode* node;
    ListNode* freeing;

    // Go through every row, based on height.
    for (unsigned int row = 0; row < height; row++) {

        // Go through every column, based on length, for every row.
        for (unsigned int column = 0; column < length; column++) {

            // Store index of hash table array that could hold a node for the current grid coordinate.
            unsigned int hashIndex = hash(column, row);

            // Begin at the first node of the linked list at hashIndex.
            node = letters[hashIndex];

            // If there is no list at hashIndex, then there is no letter stored for current coordinate.
            if (node == NULL) {

                // Print a random letter.
                printf("%c ", 'A' + (rand() % 26));
            }

            // If there is only one node in the list at hashIndex...
            else if (node->next == NULL) {

                // If the node is for the current coordinate...
                if (node->column == column && node->row == row) {

                    // Print the letter held in the node.
                    printf("%c ", toupper(node->letter));

                    // Free the node and set hashIndex to NULL to signal no list left.
                    free(letters[hashIndex]);
                    letters[hashIndex] == NULL;
                }

                // If the node is not for the current coordinate, then there is no letter stored here.
                else {

                    // Print a random letter.
                    printf("%c ", 'A' + (rand() % 26));
                }

            // Else, there are at least two nodes in the list at listIndex.
            }
            else {

                // If the first node is for the current coordinate...
                if (node->column == column && node->row == row) {

                    // Print the letter in the node.
                    printf("%c ", toupper(node->letter));

                    // Set the start of hashIndex's list to the node after the old starting node.
                    letters[hashIndex] = node->next;

                    // Free the current coordinate's node.
                    free(node);
                }

                // Else, there could be a node for the current coordinate after the first node.
                else {

                    // Move through the list, checking the coordinates of the next node before moving to it.
                    while (node->next != NULL && !(node->next->column == column && node->next->row == row)) {
                        node = node->next;
                    }

                    // If the current node is the end of the list, then there was no letter stored for current coordinate.
                    if (node->next == NULL) {

                        // Print a random letter.
                        printf("%c ", 'A' + (rand() % 26));
                    }

                    // Else, the next node must be for the current coordinate.
                    else {

                        // Print the letter in the next node.
                        printf("%c ", toupper(node->next->letter));

                        // Store the next node for freeing.
                        freeing = node->next;

                        // Set the current node's next field to point to the node after the current coordinate's node.
                        node->next = freeing->next;

                        // Free the current coordinate's node.
                        free(freeing);
                    }
                }
            }
        }

        // Move to next line after each row is printed.
        printf("\n");
    }

    // Free the hash table's array.
    free(letters);
    
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

    return true;
}