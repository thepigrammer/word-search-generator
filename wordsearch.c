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
        printf("Error: malloc() returned NULL.\n");
        return 1;
    }

    // Set first char of word to know if user immediately pressed Enter without typing a word.
    word[0] = '\0';

    printf("Type all words, pressing Enter after each one. Input a '.' to mark the end of the words list.\n");

    // Keep getting words from user; loop will break once user enters "." as first char of word.
    while (true) {

        // wordLength will be incremented for every char received from the user.
        unsigned int wordLength = 0;

        // Receive first char of word.
        char letter = getchar();
        
        // Put received char into word and take another. Repeat until user presses Enter.
        for (unsigned int i = 0; letter != '\n'; i++) {

            // Double the size of the word array if the amomunt of characters goes over the current size.
            if (i > wordSize) {
                word = realloc(word, sizeof(char) * (wordSize * 2));
                if (word == NULL) {
                    printf("Error: realloc() returned NULL.\n");
                    return 2;
                }
                wordSize *= 2;
            }

            word[i] = letter;
            wordLength++;
            letter = getchar();
        }

        // If user pressed Enter without typing anything, restart the loop.
        if (word[0] == '\0') {
            continue;
        }

        // If user entered "." as the word, break out of the loop to stop receiving words.
        if (word[0] == '.') {
            break;
        }

        // Call right() to store the word in the hash table as individual letters with their grid coordinates.
        // If right() returns false, indicate that the word could not be placed.
        if (!right(letters, word, wordLength, length, height)) {
            printf("Word could not be placed on the grid.\n");
        }

        word[0] = '\0';
    }
    
    // Space allocated for word is no longer needed.
    free(word);

    // Create variables used for linked list traversal and node freeing.
    ListNode* node;
    ListNode* freeing;

    // Print the word search grid.
    // Go through every row, based on height.
    for (unsigned int row = 0; row < height; row++) {

        // Go through every column, based on length, for every row.
        for (unsigned int column = 0; column < length; column++) {

            // Store index of hash table array that could hold a node for the current grid coordinates.
            unsigned int hashIndex = hash(column, row);

            // Begin at the first node of the linked list at hashIndex.
            node = letters[hashIndex];

            // If there is no list at hashIndex, then there is no letter stored for current coordinates.
            if (node == NULL) {

                // Print a random letter.
                printf("%c ", 'A' + (rand() % 26));
            }

            // If there is only one node in the list at hashIndex...
            else if (node->next == NULL) {

                // If the node is for the current coordinates...
                if (node->column == column && node->row == row) {

                    // Print the letter held in the node.
                    printf("%c ", node->letter);

                    // Free the node and set hashIndex to NULL to signal no list left.
                    free(letters[hashIndex]);
                    letters[hashIndex] == NULL;
                }

                // If the node is not for the current coordinates, then there is no letter stored here.
                else {

                    // Print a random letter.
                    printf("%c ", 'A' + (rand() % 26));
                }

            // Else, there are at least two nodes in the list at listIndex.
            }
            else {

                // If the first node is for the current coordinates...
                if (node->column == column && node->row == row) {

                    // Print the letter in the node.
                    printf("%c ", node->letter);

                    // Set the start of hashIndex's list to the node after the old starting node.
                    letters[hashIndex] = node->next;

                    // Free the current coordinates' node.
                    free(node);
                }

                // Else, there could be a node for the current coordinates after the first node.
                else {

                    // Move through the list, checking the coordinates of the next node before moving to it.
                    while (node->next != NULL && !(node->next->column == column && node->next->row == row)) {
                        node = node->next;
                    }

                    // If the current node is the end of the list, then there was no letter stored for current coordinates.
                    if (node->next == NULL) {

                        // Print a random letter.
                        printf("%c ", 'A' + (rand() % 26));
                    }

                    // Else, the next node must be for the current coordinates.
                    else {

                        // Print the letter in the next node.
                        printf("%c ", node->next->letter);

                        // Store the next node for freeing.
                        freeing = node->next;

                        // Set the current node's next field to point to the node after the current coordinates' node.
                        node->next = freeing->next;

                        // Free the current coordinates' node.
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

// Hash function for hash table of letters.
unsigned int hash(unsigned int column, unsigned int row) {
    return (column + row) % 50;
}

// Function for putting a word on the grid (AKA in the hash table) in the right-facing direction.
// Returns true if the word was successfully placed or false if it was not.
bool right(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height) {

    // If the word is longer than the length of the grid, then it cannot be placed horizontally.
    if (wordLength > length) {
        return false;
    }
    
    // Declare row and column variables, setting the row to a random row on the grid.
    unsigned int row = rand() % height;
    unsigned int column;

    // If the word is shorter than the length of each row...
    if (wordLength < length) {

        // Choose a random column to start the word at, such that the rest will definitely fit placed to the right.
        column = rand() % (length - wordLength + 1);
    }

    // Else, the word is the length of the grid, and must start at the first column to take up the entire row.
    else {
        column = 0;
    }

    // Declare variables for traversing hash table and detecting if a spot on the grid is already taken.
    ListNode* node;
    bool spotTaken = false;

    // Go through every letter in the word to detect if its potential grid spot is already taken.
    for (unsigned int i = 0; i < wordLength && spotTaken == false; i++) {

        // Start at the first node of the hash table chain that the potential coordinates could already be in.
        node = letters[hash(column + i, row)];

        // Go through the linked list, searching for a node that already holds the coordinates.
        while (node != NULL) {
            
            // If current node does not hold the coordinates, move to the next node.
            if (!(node->column == column + i && node->row == row)) {
                node = node->next;
            }
            
            // Else if the node does hold the coordinates but the letter is the same, that works; move to next letter.
            else if (node->letter == toupper(word[i])) {
                break;
            }

            // Else, the potential spot is already taken by another letter.
            else {
                spotTaken = true;
                break;
            }
        }
    }

    // If a grid spot was already taken, word could not be placed.
    if (spotTaken == true) {
        return false;
    }

    // Word can be placed; make a variable to store the return value of the hash function to avoid unnecessary calls.
    unsigned int hashIndex;

    // Go through each letter of the word and store it in the hash table, along with its coordinates.
    for (unsigned int i = 0; i < wordLength; i++) {

        // Store the index of the hash table chain for the letter's coordinates.
        hashIndex = hash(column + i, row);

        // Store the first node of the chain.
        node = letters[hashIndex];

        // Make the new node, and set the array's element to point to it.
        letters[hashIndex] = malloc(sizeof(ListNode));
        if (letters[hashIndex] == NULL) {
            printf("Error: malloc() returned NULL.\n");
            return false;
        }

        // Set the values of the node with the coordinates and letter.
        letters[hashIndex]->column = column + i;
        letters[hashIndex]->row = row;
        letters[hashIndex]->letter = toupper(word[i]);

        // If there was no existing linked list at the index, set next to NULL.
        if (node == NULL) {
            letters[hashIndex]->next = NULL;
        }
        
        // Else, there was already a list at the index, so the new node points to the old starting node.
        else {
            letters[hashIndex]->next = node;
        }
    }

    // Return true to signal that the word was successfully placed in the hash table.
    return true;
}