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
bool rightMiddleRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool rightMiddleLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool rightMiddleMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);

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

    // Declare row and column variables.
    unsigned int row, column;

    // Randomly define variable to hold function pointer of one of 6 searching algorithms.
    bool (*function)(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
    int random = rand() % 3;
    switch (random) {
        case 0:
            function = rightMiddleRight;
            break;
        case 1:
            function = rightMiddleLeft;
            break;
        case 2:
            function = rightMiddleMiddle;
    }

    // Check for spot and set row and column; if returns false, no spot found for word.
    if (!function(letters, word, wordLength, length, height, &row, &column)) {
        return false;
    }

    // Word can be placed; make a variable to store the return value of the hash function to avoid unnecessary calls.
    unsigned int hashIndex;

    // Go through each letter of the word and store it in the hash table, along with its coordinates.
    ListNode* node;
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

// Checks for a spot where word can be placed facing right, starting from middle row and rightmost column.
// Affects the row and column variables during execution.
// Returns true if a spot was found, and returns false otherwise.
bool rightMiddleRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the middle row of the grid.
    *row = (height - 1) / 2;

    // If the word is shorter than the length of each row...
    if (wordLength < length) {

        // Set column to rightmost one such that the rest of the word will definitely fit placed to the right.
        *column = length - wordLength;
    }

    // Else, the word is the length of the grid, and must start at the first column to take up the entire row.
    else {
        *column = 0;
    }

    // Declare variables for traversing hash table and detecting if a spot on the grid is already taken.
    ListNode* node;
    bool spotTaken = false;

    // Declare variables for holding displacement from middle row and the current row being checked.
    int displace = 0;
    unsigned int dispRow;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row, starting from middle row then alternating outward checks.
    while (*row + displace < height) {

        // If displace is negative, take it away from middle row to get current checking row.
        if (displace < 0) {
            dispRow = *row - (unsigned int)(displace * -1);
        }

        // Else, displace is positive and is added to middle row.
        else {
            dispRow = *row + (unsigned int)displace;
        }
        
        // Check every column starting from current column to column 0.
        while (true) {

            // Go through every letter in the word to detect if its potential grid spot is already taken.
            for (unsigned int i = 0; i < wordLength && spotTaken == false; i++) {

                // Start at the first node of the hash table chain that the potential coordinates could already be in.
                node = letters[hash(*column + i, dispRow)];

                // Go through the linked list, searching for a node that already holds the coordinates.
                while (node != NULL) {

                    // If current node does not hold the coordinates, move to the next node.
                    if (!(node->column == *column + i && node->row == dispRow)) {
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

            // If no grid spots were taken, a spot for word was found and loop is over.
            if (spotTaken == false) {
                spotFound = true;
                break;
            }

            // Reset spotTaken for next check.
            spotTaken = false;

            // If column 0 was checked and loop was not broken, there is no spot for word on the row.
            if (*column == 0) {
                break;
            }

            // Move column to the left by one.
            (*column)--;
        }

        // If a spot for the word was found, set row to the row that the spot was found in and break from loop.
        if (spotFound) {
            *row = dispRow;
            break;
        }

        // If the row is the middle, increment displace.
        if (displace == 0) {
            displace++;
        }
        
        // Else if the displacement is negative, flip to positive and increment.
        else if (displace < 0) {
            displace = (displace * -1) + 1;
        }

        // Else if the displacement is positive and flipping to negative would be in bounds, flip to negative.
        else if ((unsigned int)(displace) <= *row) {
            displace *= -1;
        }

        // Else, the displacement would be out of bounds, all rows checked and loop complete.
        else {
            break;
        }

        // Reset column to the rightmost possible one for word since changing rows.
        *column = length - wordLength;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed facing right, starting from middle row and leftmost column.
bool rightMiddleLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {
    
    // Initialize row as the middle row of the grid.
    *row = (height - 1) / 2;

    // Initialize column as the leftmost one.
    *column = 0;

    // Declare variables for traversing hash table and detecting if a spot on the grid is already taken.
    ListNode* node;
    bool spotTaken = false;

    // Declare variables for holding displacement from middle row and the current row being checked.
    int displace = 0;
    unsigned int dispRow;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row, starting from middle row then alternating outward checks.
    while (*row + displace < height) {

        // If displace is negative, take it away from middle row to get current checking row.
        if (displace < 0) {
            dispRow = *row - (unsigned int)(displace * -1);
        }

        // Else, displace is positive and is added to middle row.
        else {
            dispRow = *row + (unsigned int)displace;
        }
        
        // Check every column going to the right until word is too long or a spot is found.
        while (true) {

            // Go through every letter in the word to detect if its potential grid spot is already taken.
            for (unsigned int i = 0; i < wordLength && spotTaken == false; i++) {

                // Start at the first node of the hash table chain that the potential coordinates could already be in.
                node = letters[hash(*column + i, dispRow)];

                // Go through the linked list, searching for a node that already holds the coordinates.
                while (node != NULL) {

                    // If current node does not hold the coordinates, move to the next node.
                    if (!(node->column == *column + i && node->row == dispRow)) {
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

            // If no grid spots were taken, a spot for word was found and loop is over.
            if (spotTaken == false) {
                spotFound = true;
                break;
            }

            // Reset spotTaken for next check.
            spotTaken = false;

            // If rightmost potential column was checked and loop was not broken, there is no spot for word on the row.
            if (*column == length - wordLength) {
                break;
            }

            // Move column to the left by one.
            (*column)++;
        }

        // If a spot for the word was found, set row to the row that the spot was found in and break from loop.
        if (spotFound) {
            *row = dispRow;
            break;
        }

        // If the row is the middle, increment displace.
        if (displace == 0) {
            displace++;
        }
        
        // Else if the displacement is negative, flip to positive and increment.
        else if (displace < 0) {
            displace = (displace * -1) + 1;
        }

        // Else if the displacement is positive and flipping to negative would be in bounds, flip to negative.
        else if ((unsigned int)(displace) <= *row) {
            displace *= -1;
        }

        // Else, the displacement would be out of bounds, all rows checked and loop complete.
        else {
            break;
        }

        // Reset column to leftmost since changing rows.
        *column = 0;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed facing right, starting from middle row and middle column.
bool rightMiddleMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {
    
    // Initialize row as the middle row of the grid.
    *row = (height - 1) / 2;

    // Initialize column as the leftmost one.
    *column = (length - 1) / 2;

    // Declare variables for traversing hash table and detecting if a spot on the grid is already taken.
    ListNode* node;
    bool spotTaken = false;

    // Declare variables for holding displacement from middle row and the current row being checked.
    int displace = 0;
    unsigned int dispRow;

    // Declare displacement variables for column.
    int displace2 = 0;
    unsigned int dispCol;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row, starting from middle row then alternating outward checks.
    while (*row + abs(displace) < height) {

        // If displace is negative, take it away from middle row to get current checking row.
        if (displace < 0) {
            dispRow = *row - (unsigned int)(displace * -1);
        }

        // Else, displace is positive and is added to middle row.
        else {
            dispRow = *row + (unsigned int)displace;
        }
        
        // Check every column starting from middle and alternating outward.
        while (true) {

            // If displace2 is negative, take it away from middle column to get current checking column.
            if (displace2 < 0) {
                dispCol = *column - (unsigned int)(displace2 * -1);
            }

            // Else, displace2 is positive and is added to middle column.
            else {
                dispCol = *column + (unsigned int)displace2;
            }

            // If the word is not too long for the column position...
            if (dispCol + wordLength <= length) {

                // Go through every letter in the word to detect if its potential grid spot is already taken.
                for (unsigned int i = 0; i < wordLength && spotTaken == false; i++) {

                    // Start at the first node of the hash table chain that the potential coordinates could already be in.
                    node = letters[hash(dispCol + i, dispRow)];

                    // Go through the linked list, searching for a node that already holds the coordinates.
                    while (node != NULL) {

                        // If current node does not hold the coordinates, move to the next node.
                        if (!(node->column == dispCol + i && node->row == dispRow)) {
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
            }

            // Else, the word cannot fit for current dispCol, so signal that word cannot be placed.
            else {
                spotTaken = true;
            }

            // If no grid spots were taken, a spot for word was found and loop is over.
            if (spotTaken == false) {
                *column = dispCol;
                spotFound = true;
                break;
            }

            // Reset spotTaken for next check.
            spotTaken = false;

            // If the column is the middle, increment displace2.
            if (displace2 == 0) {
                displace2++;
            }
            
            // Else if the displacement is negative, flip to positive and increment.
            else if (displace2 < 0) {
                displace2 = (displace2 * -1) + 1;
            }

            // Else if the displacement is positive and flipping to negative would be in bounds, flip to negative.
            else if ((unsigned int)(displace2) <= *column) {
                displace2 *= -1;
            }

            // Else, the displacement would be out of bounds, all columns checked and loop complete.
            else {
                break;
            }
        }

        // If a spot for the word was found, set row to the row that the spot was found in and break from loop.
        if (spotFound) {
            *row = dispRow;
            break;
        }

        // If the row is the middle, increment displace.
        if (displace == 0) {
            displace++;
        }
        
        // Else if the displacement is negative, flip to positive and increment.
        else if (displace < 0) {
            displace = (displace * -1) + 1;
        }

        // Else if the displacement is positive and flipping to negative would be in bounds, flip to negative.
        else if ((unsigned int)(displace) <= *row) {
            displace *= -1;
        }

        // Else, the displacement would be out of bounds, all rows checked and loop complete.
        else {
            break;
        }

        // Reset column to middle and displace2 to 0 since changing rows.
        *column = (length - 1) / 2;
        displace2 = 0;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}