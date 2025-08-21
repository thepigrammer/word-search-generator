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
bool checkRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int* row, unsigned int* column);
bool rightMiddleRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool rightMiddleLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool rightMiddleMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool rightTopRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool rightTopLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool rightTopMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool rightBottomRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool rightBottomLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool rightBottomMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool left(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height);
bool checkLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int* row, unsigned int* column);
bool leftMiddleRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool leftMiddleLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool leftMiddleMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool leftTopRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool leftTopLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool leftTopMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool leftBottomRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool leftBottomLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool leftBottomMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool down(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height);
bool checkDown(ListNode** letters, char* word, unsigned int wordLength, unsigned int* row, unsigned int* column);
bool downMiddleRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool downMiddleLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool downMiddleMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool downTopRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool downTopLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool downTopMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool downBottomRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool downBottomLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool downBottomMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool up(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height);
bool checkUp(ListNode** letters, char* word, unsigned int wordLength, unsigned int* row, unsigned int* column);
bool upMiddleRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool upMiddleLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool upMiddleMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool upTopRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool upTopLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool upTopMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool upBottomRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool upBottomLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool upBottomMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool up_right(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height);
bool checkUp_right(ListNode** letters, char* word, unsigned int wordLength, unsigned int* row, unsigned int* column);
bool up_rightMiddleRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool up_rightMiddleLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool up_rightMiddleMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool up_rightTopRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool up_rightTopLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool up_rightTopMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool up_rightBottomRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool up_rightBottomLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool up_rightBottomMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool up_left(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height);
bool checkUp_left(ListNode** letters, char* word, unsigned int wordLength, unsigned int* row, unsigned int* column);
bool up_leftMiddleRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool up_leftMiddleLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool up_leftMiddleMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool up_leftTopRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool up_leftTopLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool up_leftTopMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool up_leftBottomRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool up_leftBottomLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool up_leftBottomMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool down_right(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height);
bool checkDown_right(ListNode** letters, char* word, unsigned int wordLength, unsigned int* row, unsigned int* column);
bool down_rightMiddleRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool down_rightMiddleLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool down_rightMiddleMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool down_rightTopRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool down_rightTopLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool down_rightTopMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool down_rightBottomRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool down_rightBottomLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool down_rightBottomMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool down_left(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height);
bool checkDown_left(ListNode** letters, char* word, unsigned int wordLength, unsigned int* row, unsigned int* column);
bool down_leftMiddleRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool down_leftMiddleLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool down_leftMiddleMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool down_leftTopRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool down_leftTopLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool down_leftTopMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool down_leftBottomRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool down_leftBottomLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
bool down_leftBottomMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);


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

            word[i] = toupper(letter);
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

        // Make an array with an element for each possible direction, with each element initialized to 0.
        int functions[8] = {0};

        // Store each direction's number in the array in random order.
        int index;
        for (int i = 1; i <= 8; i++) {
            index = rand();

            // While the potential element has already been used to store a direction's number, search for another.
            while (functions[index % 8] != 0) {
                index++;
            }

            functions[index % 8] = i;
        }

        // Create variables for storing direction function pointer and whether the call to it failed.
        bool (*function)(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height);
        bool failed = true;

        // Go through functions array, calling the function at element until word is placed or all directions tried.
        for (int i = 0; failed && i < 8; i++) {
            switch (functions[i]) {
                case 1:
                    function = right;
                    break;
                case 2:
                    function = left;
                    break;
                case 3:
                    function = down;
                    break;
                case 4:
                    function = up;
                    break;
                case 5:
                    function = up_right;
                    break;
                case 6:
                    function = up_left;
                    break;
                case 7:
                    function = down_right;
                    break;
                case 8:
                    function = down_left;
                    break;
            }

            // Call function to store the word in the hash table as individual letters with their grid coordinates.
            // If function returns true, indicate that the word was placed.
            if (function(letters, word, wordLength, length, height)) {
                failed = false;
            }
        }

        // If failed is still true after all directions were checked, word was not placed.
        if (failed) {
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

    // Randomly define variable to hold function pointer of one of 9 searching algorithms.
    bool (*function)(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
    int random = rand() % 9;
    switch (random) {
        case 0:
            function = rightMiddleRight;
            break;
        case 1:
            function = rightMiddleLeft;
            break;
        case 2:
            function = rightMiddleMiddle;
            break;
        case 3:
            function = rightTopRight;
            break;
        case 4:
            function = rightTopLeft;
            break;
        case 5:
            function = rightTopMiddle;
            break;
        case 6:
            function = rightBottomRight;
            break;
        case 7:
            function = rightBottomLeft;
            break;
        case 8:
            function = rightBottomMiddle;
            break;
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

        // If letter already has a node, it was changed to lowercase by check function; continue to next letter.
        if (word[i] == tolower(word[i])) {
            continue;
        }

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
        letters[hashIndex]->letter = word[i];

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

// Checks whether a word will fit facing right from the given coordinates.
bool checkRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int* row, unsigned int* column) {

    // Declare variable to signal whether the checked spot is taken and for node traversal.
    bool spotTaken = false;
    ListNode* node;

    // Go through every letter in the word to detect if its potential grid spot is already taken.
    for (unsigned int i = 0; i < wordLength && spotTaken == false; i++) {

        // Start at the first node of the hash table chain that the potential coordinates could already be in.
        node = letters[hash(*column + i, *row)];

        // Go through the linked list, searching for a node that already holds the coordinates.
        while (node != NULL) {

            // If current node does not hold the coordinates, move to the next node.
            if (!(node->column == *column + i && node->row == *row)) {
                node = node->next;
            }
            
            // Else if the node does hold the coordinates but the letter is the same, that works; move to next letter.
            else if (node->letter == word[i]) {

                // Mark that the letter does not need to have a node created in hash table later if word fits.
                word[i] = tolower(word[i]);

                break;
            }

            // Else, the potential spot is already taken by another letter.
            else {

                // Reset the word's letters if any were changed to lowercase.
                for (unsigned int j = 0; j < wordLength; j++) {
                    if (word[j] != toupper(word[j])) {
                        word[j] = toupper(word[j]);
                    }
                }

                spotTaken = true;
                break;
            }
        }
    }

    // Return whether or not the spot is available.
    return !spotTaken;
}

// Checks for a spot where word can be placed facing right, starting from middle row and rightmost column.
// Affects the row and column variables during execution.
// Returns true if a spot was found, and returns false otherwise.
bool rightMiddleRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the middle row of the grid.
    *row = (height - 1) / 2;

    // Set column to rightmost one such that the rest of the word will definitely fit placed to the right.
    *column = length - wordLength;

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

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkRight(letters, word, wordLength, &dispRow, column)) {
                spotFound = true;
                break;
            }

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

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkRight(letters, word, wordLength, &dispRow, column)) {
                spotFound = true;
                break;
            }

            // If rightmost potential column was checked and loop was not broken, there is no spot for word on the row.
            if (*column == length - wordLength) {
                break;
            }

            // Move column to the right by one.
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

    // Initialize column as the middle one.
    *column = (length - 1) / 2;

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
        while (*column + abs(displace2) < length) {

            // If displace2 is negative, take it away from middle column to get current checking column.
            if (displace2 < 0) {
                dispCol = *column - (unsigned int)(displace2 * -1);
            }

            // Else, displace2 is positive and is added to middle column.
            else {
                dispCol = *column + (unsigned int)displace2;
            }

            // If the word is not too long for the column position and function returns true...
            if (dispCol + wordLength <= length && checkRight(letters, word, wordLength, &dispRow, &dispCol)) {

                // The spot is available, and passed row and column values are for that spot.
                spotFound = true;
                *column = dispCol;
                break;
            }

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

// Checks for a spot where word can be placed facing right, starting from top row and rightmost column.
bool rightTopRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the top row of the grid.
    *row = 0;

    // Set column to rightmost one such that the rest of the word will definitely fit placed to the right.
    *column = length - wordLength;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row, starting from top row until last.
    while (*row < height) {
       
        // Check every column starting from current column to column 0.
        while (true) {

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkRight(letters, word, wordLength, row, column)) {
                spotFound = true;
                break;
            }

            // If column 0 was checked and loop was not broken, there is no spot for word on the row.
            if (*column == 0) {
                break;
            }

            // Move column to the left by one.
            (*column)--;
        }

        // If a spot for the word was found, break from loop.
        if (spotFound) {
            break;
        }
        
        // Reset column to the rightmost possible one for word since changing rows, then move to next row down.
        *column = length - wordLength;
        (*row)++;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed facing right, starting from top row and leftmost column.
bool rightTopLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the top row of the grid.
    *row = 0;

    // Initialize column as the leftmost one.
    *column = 0;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row, starting from top row until last.
    while (*row < height) {
       
        // Check every column going to the right until word is too long or a spot is found.
        while (true) {

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkRight(letters, word, wordLength, row, column)) {
                spotFound = true;
                break;
            }

            // If rightmost potential column was checked and loop was not broken, there is no spot for word on the row.
            if (*column == length - wordLength) {
                break;
            }

            // Move column to the right by one.
            (*column)++;
        }

        // If a spot for the word was found, break from loop.
        if (spotFound) {
            break;
        }
        
        // Reset column to leftmost one since changing rows, then move to next row down.
        *column = 0;
        (*row)++;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed facing right, starting from top row and middle column.
bool rightTopMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the top row of the grid.
    *row = 0;

    // Initialize column as the middle one.
    *column = (length - 1) / 2;

    // Declare displacement variables for column.
    int displace2 = 0;
    unsigned int dispCol;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row, starting from top row until last.
    while (*row < height) {
       
        // Check every column starting from middle and alternating outward.
        while (*column + abs(displace2) < length) {

            // If displace2 is negative, take it away from middle column to get current checking column.
            if (displace2 < 0) {
                dispCol = *column - (unsigned int)(displace2 * -1);
            }

            // Else, displace2 is positive and is added to middle column.
            else {
                dispCol = *column + (unsigned int)displace2;
            }

            // If the word is not too long for the column position and function returns true...
            if (dispCol + wordLength <= length && checkRight(letters, word, wordLength, row, &dispCol)) {

                // The spot is available, and passed row and column values are for that spot.
                spotFound = true;
                *column = dispCol;
                break;
            }

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

        // If a spot for the word was found, break from loop.
        if (spotFound) {
            break;
        }
        
        // Reset column to middle one and displace2 to 0 since changing rows, then move to next row down.
        *column = (length - 1) / 2;
        displace2 = 0;
        (*row)++;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed facing right, starting from bottom row and rightmost column.
bool rightBottomRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the bottom row of the grid.
    *row = height - 1;

    // Set column to rightmost one such that the rest of the word will definitely fit placed to the right.
    *column = length - wordLength;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row, starting from bottom row until top.
    while (true) {
       
        // Check every column starting from current column to column 0.
        while (true) {

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkRight(letters, word, wordLength, row, column)) {
                spotFound = true;
                break;
            }

            // If column 0 was checked and loop was not broken, there is no spot for word on the row.
            if (*column == 0) {
                break;
            }

            // Move column to the left by one.
            (*column)--;
        }

        // If a spot for the word was found or the top row was checked, break from loop.
        if (spotFound || *row == 0) {
            break;
        }
        
        // Reset column to the rightmost possible one for word since changing rows, then move to next row up.
        *column = length - wordLength;
        (*row)--;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed facing right, starting from bottom row and leftmost column.
bool rightBottomLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the bottom row of the grid.
    *row = height - 1;

    // Initialize column as the leftmost one.
    *column = 0;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row, starting from bottom row until top.
    while (true) {
       
        // Check every column going to the right until word is too long or a spot is found.
        while (true) {

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkRight(letters, word, wordLength, row, column)) {
                spotFound = true;
                break;
            }

            // If rightmost potential column was checked and loop was not broken, there is no spot for word on the row.
            if (*column == length - wordLength) {
                break;
            }

            // Move column to the right by one.
            (*column)++;
        }

        // If a spot for the word was found or the top row was checked, break from loop.
        if (spotFound || *row == 0) {
            break;
        }
        
        // Reset column to the first one since changing rows, then move to next row up.
        *column = 0;
        (*row)--;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed facing right, starting from bottom row and middle column.
bool rightBottomMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the bottom row of the grid.
    *row = height - 1;

    // Initialize column as the middle one.
    *column = (length - 1) / 2;

    // Declare displacement variables for column.
    int displace2 = 0;
    unsigned int dispCol;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row, starting from bottom row until top.
    while (true) {
       
        // Check every column starting from middle and alternating outward.
        while (*column + abs(displace2) < length) {

            // If displace2 is negative, take it away from middle column to get current checking column.
            if (displace2 < 0) {
                dispCol = *column - (unsigned int)(displace2 * -1);
            }

            // Else, displace2 is positive and is added to middle column.
            else {
                dispCol = *column + (unsigned int)displace2;
            }

            // If the word is not too long for the column position and function returns true...
            if (dispCol + wordLength <= length && checkRight(letters, word, wordLength, row, &dispCol)) {

                // The spot is available, and passed row and column values are for that spot.
                spotFound = true;
                *column = dispCol;
                break;
            }

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
        
        // If a spot for the word was found or the top row was checked, break from loop.
        if (spotFound || *row == 0) {
            break;
        }
        
        // Reset column to middle one and displace2 to 0 since changing rows, then move to next row up.
        *column = (length - 1) / 2;
        displace2 = 0;
        (*row)--;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}


// Function for putting a word on the grid in the left-facing (backwards) direction.
bool left(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height) {

    // If the word is longer than the length of the grid, then it cannot be placed horizontally.
    if (wordLength > length) {
        return false;
    }

    // Declare row and column variables.
    unsigned int row, column;

    // Randomly define variable to hold function pointer of one of 9 searching algorithms.
    bool (*function)(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
    int random = rand() % 9;
    switch (random) {
        case 0:
            function = leftMiddleRight;
            break;
        case 1:
            function = leftMiddleLeft;
            break;
        case 2:
            function = leftMiddleMiddle;
            break;
        case 3:
            function = leftTopRight;
            break;
        case 4:
            function = leftTopLeft;
            break;
        case 5:
            function = leftTopMiddle;
            break;
        case 6:
            function = leftBottomRight;
            break;
        case 7:
            function = leftBottomLeft;
            break;
        case 8:
            function = leftBottomMiddle;
            break;
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

        // If letter already has a node, it was changed to lowercase by check function; continue to next letter.
        if (word[i] == tolower(word[i])) {
            continue;
        }

        // Store the index of the hash table chain for the letter's coordinates.
        hashIndex = hash(column - i, row);

        // Store the first node of the chain.
        node = letters[hashIndex];

        // Make the new node, and set the array's element to point to it.
        letters[hashIndex] = malloc(sizeof(ListNode));
        if (letters[hashIndex] == NULL) {
            printf("Error: malloc() returned NULL.\n");
            return false;
        }

        // Set the values of the node with the coordinates and letter.
        letters[hashIndex]->column = column - i;
        letters[hashIndex]->row = row;
        letters[hashIndex]->letter = word[i];

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

// Checks whether a word will fit facing left from the given coordinates.
bool checkLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int* row, unsigned int* column) {

    // Declare variable to signal whether the checked spot is taken and for node traversal.
    bool spotTaken = false;
    ListNode* node;

    // Go through every letter in the word to detect if its potential grid spot is already taken.
    for (unsigned int i = 0; i < wordLength && spotTaken == false; i++) {

        // Start at the first node of the hash table chain that the potential coordinates could already be in.
        node = letters[hash(*column - i, *row)];

        // Go through the linked list, searching for a node that already holds the coordinates.
        while (node != NULL) {

            // If current node does not hold the coordinates, move to the next node.
            if (!(node->column == *column - i && node->row == *row)) {
                node = node->next;
            }
            
            // Else if the node does hold the coordinates but the letter is the same, that works; move to next letter.
            else if (node->letter == word[i]) {

                // Mark that the letter does not need to have a node created in hash table later if word fits.
                word[i] = tolower(word[i]);

                break;
            }

            // Else, the potential spot is already taken by another letter.
            else {

                // Reset the word's letters if any were changed to lowercase.
                for (unsigned int j = 0; j < wordLength; j++) {
                    if (word[j] != toupper(word[j])) {
                        word[j] = toupper(word[j]);
                    }
                }

                spotTaken = true;
                break;
            }
        }
    }

    // Return whether or not the spot is available.
    return !spotTaken;
}

// Checks for a spot where word can be placed facing left, starting from middle row and rightmost column.
bool leftMiddleRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the middle row of the grid.
    *row = (height - 1) / 2;

    // Set column to rightmost one.
    *column = length - 1;

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
        
        // Check every column starting from rightmost column to leftmost potential column.
        while (true) {

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkLeft(letters, word, wordLength, &dispRow, column)) {
                spotFound = true;
                break;
            }

            // If word will be too long going to left or column 0 was checked, there is no spot for word on the row.
            if (wordLength - 1 == *column || *column == 0) {
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

        // Reset column to the rightmost one since changing rows.
        *column = length - 1;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed facing left, starting from middle row and leftmost column.
bool leftMiddleLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {
    
    // Initialize row as the middle row of the grid.
    *row = (height - 1) / 2;

    // Initialize column as the leftmost one that word could fit at.
    *column = wordLength - 1;

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
        
        // Check every column going to the right until last column.
        while (true) {

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkLeft(letters, word, wordLength, &dispRow, column)) {
                spotFound = true;
                break;
            }

            // If rightmost column was checked and loop was not broken, there is no spot for word on the row.
            if (*column == length - 1) {
                break;
            }

            // Move column to the right by one.
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

        // Reset column to leftmost possible since changing rows.
        *column = wordLength - 1;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed facing left, starting from middle row and middle column.
bool leftMiddleMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {
    
    // Initialize row as the middle row of the grid.
    *row = (height - 1) / 2;

    // Initialize column as the middle one.
    *column = (length - 1) / 2;

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
        while (*column + abs(displace2) < length) {

            // If displace2 is negative, take it away from middle column to get current checking column.
            if (displace2 < 0) {
                dispCol = *column - (unsigned int)(displace2 * -1);
            }

            // Else, displace2 is positive and is added to middle column.
            else {
                dispCol = *column + (unsigned int)displace2;
            }

            // If the word is not too long for the column position and function returns true...
            if (dispCol + 1 >= wordLength && checkLeft(letters, word, wordLength, &dispRow, &dispCol)) {

                // The spot is available, and passed row and column values are for that spot.
                spotFound = true;
                *column = dispCol;
                break;
            }

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

        // Reset displace2 to 0 since changing rows.
        displace2 = 0;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed facing left, starting from top row and rightmost column.
bool leftTopRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the top row of the grid.
    *row = 0;

    // Set column to rightmost one.
    *column = length - 1;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row, starting from top row until last.
    while (*row < height) {
       
        // Check every column starting from rightmost column to leftmost potential column.
        while (true) {

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkLeft(letters, word, wordLength, row, column)) {
                spotFound = true;
                break;
            }

            // If word will be too long going to left or column 0 was checked, there is no spot for word on the row.
            if (wordLength - 1 == *column || *column == 0) {
                break;
            }

            // Move column to the left by one.
            (*column)--;
        }

        // If a spot for the word was found, break from loop.
        if (spotFound) {
            break;
        }
        
        // Reset column to the rightmost one since changing rows, then move to next row down.
        *column = length - 1;
        (*row)++;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed facing left, starting from top row and leftmost column.
bool leftTopLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the top row of the grid.
    *row = 0;

    // Initialize column as the leftmost one that word could fit at.
    *column = wordLength - 1;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row, starting from top row until last.
    while (*row < height) {
       
        // Check every column going to the right until last column.
        while (true) {

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkLeft(letters, word, wordLength, row, column)) {
                spotFound = true;
                break;
            }

            // If rightmost column was checked and loop was not broken, there is no spot for word on the row.
            if (*column == length - 1) {
                break;
            }

            // Move column to the right by one.
            (*column)++;
        }

        // If a spot for the word was found, break from loop.
        if (spotFound) {
            break;
        }
        
        // Reset column to leftmost possible since changing rows, then move to next row down.
        *column = wordLength - 1;
        (*row)++;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed facing left, starting from top row and middle column.
bool leftTopMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the top row of the grid.
    *row = 0;

    // Initialize column as the middle one.
    *column = (length - 1) / 2;

    // Declare displacement variables for column.
    int displace2 = 0;
    unsigned int dispCol;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row, starting from top row until last.
    while (*row < height) {
       
        // Check every column starting from middle and alternating outward.
        while (*column + abs(displace2) < length) {

            // If displace2 is negative, take it away from middle column to get current checking column.
            if (displace2 < 0) {
                dispCol = *column - (unsigned int)(displace2 * -1);
            }

            // Else, displace2 is positive and is added to middle column.
            else {
                dispCol = *column + (unsigned int)displace2;
            }

            // If the word is not too long for the column position and function returns true...
            if (dispCol + 1 >= wordLength && checkLeft(letters, word, wordLength, row, &dispCol)) {

                // The spot is available, and passed row and column values are for that spot.
                spotFound = true;
                *column = dispCol;
                break;
            }

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

        // If a spot for the word was found, break from loop.
        if (spotFound) {
            break;
        }
        
        // Reset displace2 to 0 since changing rows, then move to next row down.
        displace2 = 0;
        (*row)++;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed facing left, starting from bottom row and rightmost column.
bool leftBottomRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the bottom row of the grid.
    *row = height - 1;

    // Set column to rightmost one.
    *column = length - 1;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row, starting from bottom row until top.
    while (true) {
       
        // Check every column starting from rightmost column to leftmost potential column.
        while (true) {

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkLeft(letters, word, wordLength, row, column)) {
                spotFound = true;
                break;
            }

            // If word will be too long going to left or column 0 was checked, there is no spot for word on the row.
            if (wordLength - 1 == *column || *column == 0) {
                break;
            }

            // Move column to the left by one.
            (*column)--;
        }

        // If a spot for the word was found or the top row was checked, break from loop.
        if (spotFound || *row == 0) {
            break;
        }
        
        // Reset column to the rightmost one since changing rows, then move to next row up.
        *column = length - 1;
        (*row)--;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed facing left, starting from bottom row and leftmost column.
bool leftBottomLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the bottom row of the grid.
    *row = height - 1;

    // Initialize column as the leftmost one that word could fit at.
    *column = wordLength - 1;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row, starting from bottom row until top.
    while (true) {
       
        // Check every column going to the right until last column.
        while (true) {

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkLeft(letters, word, wordLength, row, column)) {
                spotFound = true;
                break;
            }

            // If rightmost column was checked and loop was not broken, there is no spot for word on the row.
            if (*column == length - 1) {
                break;
            }

            // Move column to the right by one.
            (*column)++;
        }

        // If a spot for the word was found or the top row was checked, break from loop.
        if (spotFound || *row == 0) {
            break;
        }
        
        // Reset column to leftmost possible since changing rows, then move to next row up.
        *column = wordLength - 1;
        (*row)--;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed facing left, starting from bottom row and middle column.
bool leftBottomMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the bottom row of the grid.
    *row = height - 1;

    // Initialize column as the middle one.
    *column = (length - 1) / 2;

    // Declare displacement variables for column.
    int displace2 = 0;
    unsigned int dispCol;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row, starting from bottom row until top.
    while (true) {
       
        // Check every column starting from middle and alternating outward.
        while (*column + abs(displace2) < length) {

            // If displace2 is negative, take it away from middle column to get current checking column.
            if (displace2 < 0) {
                dispCol = *column - (unsigned int)(displace2 * -1);
            }

            // Else, displace2 is positive and is added to middle column.
            else {
                dispCol = *column + (unsigned int)displace2;
            }

            // If the word is not too long for the column position and function returns true...
            if (dispCol + 1 >= wordLength && checkLeft(letters, word, wordLength, row, &dispCol)) {

                // The spot is available, and passed row and column values are for that spot.
                spotFound = true;
                *column = dispCol;
                break;
            }

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
        
        // If a spot for the word was found or the top row was checked, break from loop.
        if (spotFound || *row == 0) {
            break;
        }
        
        // Reset displace2 to 0 since changing rows, then move to next row up.
        displace2 = 0;
        (*row)--;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}


// Function for putting a word on the grid going down.
bool down(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height) {

    // If the word is longer than the height of the grid, then it cannot be placed vertically.
    if (wordLength > height) {
        return false;
    }

    // Declare row and column variables.
    unsigned int row, column;

    // Randomly define variable to hold function pointer of one of 9 searching algorithms.
    bool (*function)(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
    int random = rand() % 9;
    switch (random) {
        case 0:
            function = downMiddleRight;
            break;
        case 1:
            function = downMiddleLeft;
            break;
        case 2:
            function = downMiddleMiddle;
            break;
        case 3:
            function = downTopRight;
            break;
        case 4:
            function = downTopLeft;
            break;
        case 5:
            function = downTopMiddle;
            break;
        case 6:
            function = downBottomRight;
            break;
        case 7:
            function = downBottomLeft;
            break;
        case 8:
            function = downBottomMiddle;
            break;
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

        // If letter already has a node, it was changed to lowercase by check function; continue to next letter.
        if (word[i] == tolower(word[i])) {
            continue;
        }

        // Store the index of the hash table chain for the letter's coordinates.
        hashIndex = hash(column, row + i);

        // Store the first node of the chain.
        node = letters[hashIndex];

        // Make the new node, and set the array's element to point to it.
        letters[hashIndex] = malloc(sizeof(ListNode));
        if (letters[hashIndex] == NULL) {
            printf("Error: malloc() returned NULL.\n");
            return false;
        }

        // Set the values of the node with the coordinates and letter.
        letters[hashIndex]->column = column;
        letters[hashIndex]->row = row + i;
        letters[hashIndex]->letter = word[i];

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

// Checks whether a word will fit going down from the given coordinates.
bool checkDown(ListNode** letters, char* word, unsigned int wordLength, unsigned int* row, unsigned int* column) {

    // Declare variable to signal whether the checked spot is taken and for node traversal.
    bool spotTaken = false;
    ListNode* node;

    // Go through every letter in the word to detect if its potential grid spot is already taken.
    for (unsigned int i = 0; i < wordLength && spotTaken == false; i++) {

        // Start at the first node of the hash table chain that the potential coordinates could already be in.
        node = letters[hash(*column, *row + i)];

        // Go through the linked list, searching for a node that already holds the coordinates.
        while (node != NULL) {

            // If current node does not hold the coordinates, move to the next node.
            if (!(node->column == *column && node->row == *row + i)) {
                node = node->next;
            }
            
            // Else if the node does hold the coordinates but the letter is the same, that works; move to next letter.
            else if (node->letter == word[i]) {

                // Mark that the letter does not need to have a node created in hash table later if word fits.
                word[i] = tolower(word[i]);

                break;
            }

            // Else, the potential spot is already taken by another letter.
            else {

                // Reset the word's letters if any were changed to lowercase.
                for (unsigned int j = 0; j < wordLength; j++) {
                    if (word[j] != toupper(word[j])) {
                        word[j] = toupper(word[j]);
                    }
                }

                spotTaken = true;
                break;
            }
        }
    }

    // Return whether or not the spot is available.
    return !spotTaken;
}

// Checks for a spot where word can be placed going down, starting from middle row and rightmost column.
bool downMiddleRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the middle row of the grid.
    *row = (height - 1) / 2;

    // Set column to rightmost one.
    *column = length - 1;

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
        
        // Only check current row if the word is not too long to fit from row.
        if (dispRow + wordLength <= height) {

            // Check every column starting from rightmost column to leftmost column.
            while (true) {

                // If function returns true, the spot is available, and passed row and column values are for that spot.
                if (checkDown(letters, word, wordLength, &dispRow, column)) {
                    spotFound = true;
                    break;
                }

                // If column 0 was checked, there is no spot for word on the row.
                if (*column == 0) {
                    break;
                }

                // Move column to the left by one.
                (*column)--;
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

        // Reset column to the rightmost one since changing rows.
        *column = length - 1;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going down, starting from middle row and leftmost column.
bool downMiddleLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {
    
    // Initialize row as the middle row of the grid.
    *row = (height - 1) / 2;

    // Initialize column as the leftmost one.
    *column = 0;

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
        
        // Only check current row if the word is not too long to fit from row.
        if (dispRow + wordLength <= height) {

            // Check every column going to the right until last column.
            while (true) {

                // If function returns true, the spot is available, and passed row and column values are for that spot.
                if (checkDown(letters, word, wordLength, &dispRow, column)) {
                    spotFound = true;
                    break;
                }

                // If rightmost column was checked and loop was not broken, there is no spot for word on the row.
                if (*column == length - 1) {
                    break;
                }

                // Move column to the right by one.
                (*column)++;
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

        // Reset column to leftmost since changing rows.
        *column = 0;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going down, starting from middle row and middle column.
bool downMiddleMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {
    
    // Initialize row as the middle row of the grid.
    *row = (height - 1) / 2;

    // Initialize column as the middle one.
    *column = (length - 1) / 2;

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
        
        // Only check current row if the word is not too long to fit from row.
        if (dispRow + wordLength <= height) {

            // Check every column starting from middle and alternating outward.
            while (*column + abs(displace2) < length) {

                // If displace2 is negative, take it away from middle column to get current checking column.
                if (displace2 < 0) {
                    dispCol = *column - (unsigned int)(displace2 * -1);
                }

                // Else, displace2 is positive and is added to middle column.
                else {
                    dispCol = *column + (unsigned int)displace2;
                }

                // If function returns true, the spot is available, and passed row and column values are for that spot.
                if (checkDown(letters, word, wordLength, &dispRow, &dispCol)) {
                    spotFound = true;
                    *column = dispCol;
                    break;
                }

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

        // Reset displace2 to 0 since changing rows.
        displace2 = 0;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going down, starting from top row and rightmost column.
bool downTopRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the top row of the grid.
    *row = 0;

    // Set column to rightmost one.
    *column = length - 1;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row starting at top until word is longer than space left going down.
    while (height - *row >= wordLength) {
       
        // Check every column starting from rightmost column to leftmost.
        while (true) {

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkDown(letters, word, wordLength, row, column)) {
                spotFound = true;
                break;
            }

            // If column 0 was checked, there is no spot for word on the row.
            if (*column == 0) {
                break;
            }

            // Move column to the left by one.
            (*column)--;
        }

        // If a spot for the word was found, break from loop.
        if (spotFound) {
            break;
        }
        
        // Reset column to the rightmost one since changing rows, then move to next row down.
        *column = length - 1;
        (*row)++;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going down, starting from top row and leftmost column.
bool downTopLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the top row of the grid.
    *row = 0;

    // Initialize column as the leftmost one.
    *column = 0;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row starting at top until word is longer than space left going down.
    while (height - *row >= wordLength) {
       
        // Check every column going to the right until last column.
        while (true) {

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkDown(letters, word, wordLength, row, column)) {
                spotFound = true;
                break;
            }

            // If rightmost column was checked and loop was not broken, there is no spot for word on the row.
            if (*column == length - 1) {
                break;
            }

            // Move column to the right by one.
            (*column)++;
        }

        // If a spot for the word was found, break from loop.
        if (spotFound) {
            break;
        }
        
        // Reset column to leftmost since changing rows, then move to next row down.
        *column = 0;
        (*row)++;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going down, starting from top row and middle column.
bool downTopMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the top row of the grid.
    *row = 0;

    // Initialize column as the middle one.
    *column = (length - 1) / 2;

    // Declare displacement variables for column.
    int displace2 = 0;
    unsigned int dispCol;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row starting at top until word is longer than space left going down.
    while (height - *row >= wordLength) {
       
        // Check every column starting from middle and alternating outward.
        while (*column + abs(displace2) < length) {

            // If displace2 is negative, take it away from middle column to get current checking column.
            if (displace2 < 0) {
                dispCol = *column - (unsigned int)(displace2 * -1);
            }

            // Else, displace2 is positive and is added to middle column.
            else {
                dispCol = *column + (unsigned int)displace2;
            }

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkDown(letters, word, wordLength, row, &dispCol)) {
                spotFound = true;
                *column = dispCol;
                break;
            }

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

        // If a spot for the word was found, break from loop.
        if (spotFound) {
            break;
        }
        
        // Reset displace2 to 0 since changing rows, then move to next row down.
        displace2 = 0;
        (*row)++;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going down, starting from bottom row and rightmost column.
bool downBottomRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the lowest row of the grid where word is not too long.
    *row = height - wordLength;

    // Set column to rightmost one.
    *column = length - 1;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row, starting from bottom row until top.
    while (true) {
       
        // Check every column starting from rightmost column to leftmost.
        while (true) {

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkDown(letters, word, wordLength, row, column)) {
                spotFound = true;
                break;
            }

            // If column 0 was checked, there is no spot for word on the row.
            if (*column == 0) {
                break;
            }

            // Move column to the left by one.
            (*column)--;
        }

        // If a spot for the word was found or the top row was checked, break from loop.
        if (spotFound || *row == 0) {
            break;
        }
        
        // Reset column to the rightmost one since changing rows, then move to next row up.
        *column = length - 1;
        (*row)--;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going down, starting from bottom row and leftmost column.
bool downBottomLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the lowest row of the grid where word is not too long.
    *row = height - wordLength;

    // Initialize column as the leftmost one.
    *column = 0;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row, starting from bottom row until top.
    while (true) {
       
        // Check every column going to the right until last column.
        while (true) {

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkDown(letters, word, wordLength, row, column)) {
                spotFound = true;
                break;
            }

            // If rightmost column was checked and loop was not broken, there is no spot for word on the row.
            if (*column == length - 1) {
                break;
            }

            // Move column to the right by one.
            (*column)++;
        }

        // If a spot for the word was found or the top row was checked, break from loop.
        if (spotFound || *row == 0) {
            break;
        }
        
        // Reset column to leftmost since changing rows, then move to next row up.
        *column = 0;
        (*row)--;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going down, starting from bottom row and middle column.
bool downBottomMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the lowest row of the grid where word is not too long.
    *row = height - wordLength;

    // Initialize column as the middle one.
    *column = (length - 1) / 2;

    // Declare displacement variables for column.
    int displace2 = 0;
    unsigned int dispCol;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row, starting from bottom row until top.
    while (true) {
       
        // Check every column starting from middle and alternating outward.
        while (*column + abs(displace2) < length) {

            // If displace2 is negative, take it away from middle column to get current checking column.
            if (displace2 < 0) {
                dispCol = *column - (unsigned int)(displace2 * -1);
            }

            // Else, displace2 is positive and is added to middle column.
            else {
                dispCol = *column + (unsigned int)displace2;
            }

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkDown(letters, word, wordLength, row, &dispCol)) {
                spotFound = true;
                *column = dispCol;
                break;
            }

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
        
        // If a spot for the word was found or the top row was checked, break from loop.
        if (spotFound || *row == 0) {
            break;
        }
        
        // Reset displace2 to 0 since changing rows, then move to next row up.
        displace2 = 0;
        (*row)--;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}


// Function for putting a word on the grid going up.
bool up(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height) {

    // If the word is longer than the height of the grid, then it cannot be placed vertically.
    if (wordLength > height) {
        return false;
    }

    // Declare row and column variables.
    unsigned int row, column;

    // Randomly define variable to hold function pointer of one of 9 searching algorithms.
    bool (*function)(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
    int random = rand() % 9;
    switch (random) {
        case 0:
            function = upMiddleRight;
            break;
        case 1:
            function = upMiddleLeft;
            break;
        case 2:
            function = upMiddleMiddle;
            break;
        case 3:
            function = upTopRight;
            break;
        case 4:
            function = upTopLeft;
            break;
        case 5:
            function = upTopMiddle;
            break;
        case 6:
            function = upBottomRight;
            break;
        case 7:
            function = upBottomLeft;
            break;
        case 8:
            function = upBottomMiddle;
            break;
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

        // If letter already has a node, it was changed to lowercase by check function; continue to next letter.
        if (word[i] == tolower(word[i])) {
            continue;
        }

        // Store the index of the hash table chain for the letter's coordinates.
        hashIndex = hash(column, row - i);

        // Store the first node of the chain.
        node = letters[hashIndex];

        // Make the new node, and set the array's element to point to it.
        letters[hashIndex] = malloc(sizeof(ListNode));
        if (letters[hashIndex] == NULL) {
            printf("Error: malloc() returned NULL.\n");
            return false;
        }

        // Set the values of the node with the coordinates and letter.
        letters[hashIndex]->column = column;
        letters[hashIndex]->row = row - i;
        letters[hashIndex]->letter = word[i];

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

// Checks whether a word will fit going up from the given coordinates.
bool checkUp(ListNode** letters, char* word, unsigned int wordLength, unsigned int* row, unsigned int* column) {

    // Declare variable to signal whether the checked spot is taken and for node traversal.
    bool spotTaken = false;
    ListNode* node;

    // Go through every letter in the word to detect if its potential grid spot is already taken.
    for (unsigned int i = 0; i < wordLength && spotTaken == false; i++) {

        // Start at the first node of the hash table chain that the potential coordinates could already be in.
        node = letters[hash(*column, *row - i)];

        // Go through the linked list, searching for a node that already holds the coordinates.
        while (node != NULL) {

            // If current node does not hold the coordinates, move to the next node.
            if (!(node->column == *column && node->row == *row - i)) {
                node = node->next;
            }
            
            // Else if the node does hold the coordinates but the letter is the same, that works; move to next letter.
            else if (node->letter == word[i]) {

                // Mark that the letter does not need to have a node created in hash table later if word fits.
                word[i] = tolower(word[i]);

                break;
            }

            // Else, the potential spot is already taken by another letter.
            else {

                // Reset the word's letters if any were changed to lowercase.
                for (unsigned int j = 0; j < wordLength; j++) {
                    if (word[j] != toupper(word[j])) {
                        word[j] = toupper(word[j]);
                    }
                }

                spotTaken = true;
                break;
            }
        }
    }

    // Return whether or not the spot is available.
    return !spotTaken;
}

// Checks for a spot where word can be placed going up, starting from middle row and rightmost column.
bool upMiddleRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the middle row of the grid.
    *row = (height - 1) / 2;

    // Set column to rightmost one.
    *column = length - 1;

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
        
        // Only check current row if the word is not too long to fit from row.
        if (dispRow + 1 >= wordLength) {

            // Check every column starting from rightmost column to leftmost column.
            while (true) {

                // If function returns true, the spot is available, and passed row and column values are for that spot.
                if (checkUp(letters, word, wordLength, &dispRow, column)) {
                    spotFound = true;
                    break;
                }

                // If column 0 was checked, there is no spot for word on the row.
                if (*column == 0) {
                    break;
                }

                // Move column to the left by one.
                (*column)--;
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

        // Reset column to the rightmost one since changing rows.
        *column = length - 1;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going up, starting from middle row and leftmost column.
bool upMiddleLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {
    
    // Initialize row as the middle row of the grid.
    *row = (height - 1) / 2;

    // Initialize column as the leftmost one.
    *column = 0;

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
        
        // Only check current row if the word is not too long to fit from row.
        if (dispRow + 1 >= wordLength) {

            // Check every column going to the right until last column.
            while (true) {

                // If function returns true, the spot is available, and passed row and column values are for that spot.
                if (checkUp(letters, word, wordLength, &dispRow, column)) {
                    spotFound = true;
                    break;
                }

                // If rightmost column was checked and loop was not broken, there is no spot for word on the row.
                if (*column == length - 1) {
                    break;
                }

                // Move column to the right by one.
                (*column)++;
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

        // Reset column to leftmost since changing rows.
        *column = 0;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going up, starting from middle row and middle column.
bool upMiddleMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {
    
    // Initialize row as the middle row of the grid.
    *row = (height - 1) / 2;

    // Initialize column as the middle one.
    *column = (length - 1) / 2;

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
        
        // Only check current row if the word is not too long to fit from row.
        if (dispRow + 1 >= wordLength) {

            // Check every column starting from middle and alternating outward.
            while (*column + abs(displace2) < length) {

                // If displace2 is negative, take it away from middle column to get current checking column.
                if (displace2 < 0) {
                    dispCol = *column - (unsigned int)(displace2 * -1);
                }

                // Else, displace2 is positive and is added to middle column.
                else {
                    dispCol = *column + (unsigned int)displace2;
                }

                // If function returns true, the spot is available, and passed row and column values are for that spot.
                if (checkUp(letters, word, wordLength, &dispRow, &dispCol)) {
                    spotFound = true;
                    *column = dispCol;
                    break;
                }

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

        // Reset displace2 to 0 since changing rows.
        displace2 = 0;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going up, starting from top row and rightmost column.
bool upTopRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the highest row of the grid where word's length can fit.
    *row = wordLength - 1;

    // Set column to rightmost one.
    *column = length - 1;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row starting at top until last row.
    while (*row < height) {
       
        // Check every column starting from rightmost column to leftmost.
        while (true) {

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkUp(letters, word, wordLength, row, column)) {
                spotFound = true;
                break;
            }

            // If column 0 was checked, there is no spot for word on the row.
            if (*column == 0) {
                break;
            }

            // Move column to the left by one.
            (*column)--;
        }

        // If a spot for the word was found, break from loop.
        if (spotFound) {
            break;
        }
        
        // Reset column to the rightmost one since changing rows, then move to next row down.
        *column = length - 1;
        (*row)++;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going up, starting from top row and leftmost column.
bool upTopLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the highest row of the grid where word's length can fit.
    *row = wordLength - 1;

    // Initialize column as the leftmost one.
    *column = 0;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row starting at top until last row.
    while (*row < height) {
       
        // Check every column going to the right until last column.
        while (true) {

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkUp(letters, word, wordLength, row, column)) {
                spotFound = true;
                break;
            }

            // If rightmost column was checked and loop was not broken, there is no spot for word on the row.
            if (*column == length - 1) {
                break;
            }

            // Move column to the right by one.
            (*column)++;
        }

        // If a spot for the word was found, break from loop.
        if (spotFound) {
            break;
        }
        
        // Reset column to leftmost since changing rows, then move to next row down.
        *column = 0;
        (*row)++;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going up, starting from top row and middle column.
bool upTopMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the highest row of the grid where word's length can fit.
    *row = wordLength - 1;

    // Initialize column as the middle one.
    *column = (length - 1) / 2;

    // Declare displacement variables for column.
    int displace2 = 0;
    unsigned int dispCol;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row starting at top until last row.
    while (*row < height) {
       
        // Check every column starting from middle and alternating outward.
        while (*column + abs(displace2) < length) {

            // If displace2 is negative, take it away from middle column to get current checking column.
            if (displace2 < 0) {
                dispCol = *column - (unsigned int)(displace2 * -1);
            }

            // Else, displace2 is positive and is added to middle column.
            else {
                dispCol = *column + (unsigned int)displace2;
            }

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkUp(letters, word, wordLength, row, &dispCol)) {
                spotFound = true;
                *column = dispCol;
                break;
            }

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

        // If a spot for the word was found, break from loop.
        if (spotFound) {
            break;
        }
        
        // Reset displace2 to 0 since changing rows, then move to next row down.
        displace2 = 0;
        (*row)++;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going up, starting from bottom row and rightmost column.
bool upBottomRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the last row of the grid.
    *row = height - 1;

    // Set column to rightmost one.
    *column = length - 1;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row, starting from bottom row until word's length cannot fit.
    while (*row + 1 >= wordLength) {
       
        // Check every column starting from rightmost column to leftmost.
        while (true) {

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkUp(letters, word, wordLength, row, column)) {
                spotFound = true;
                break;
            }

            // If column 0 was checked, there is no spot for word on the row.
            if (*column == 0) {
                break;
            }

            // Move column to the left by one.
            (*column)--;
        }

        // If a spot for the word was found, break from loop.
        if (spotFound) {
            break;
        }
        
        // Reset column to the rightmost one since changing rows, then move to next row up.
        *column = length - 1;
        (*row)--;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going up, starting from bottom row and leftmost column.
bool upBottomLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the last row of the grid.
    *row = height - 1;

    // Initialize column as the leftmost one.
    *column = 0;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row, starting from bottom row until word's length cannot fit.
    while (*row + 1 >= wordLength) {
       
        // Check every column going to the right until last column.
        while (true) {

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkUp(letters, word, wordLength, row, column)) {
                spotFound = true;
                break;
            }

            // If rightmost column was checked and loop was not broken, there is no spot for word on the row.
            if (*column == length - 1) {
                break;
            }

            // Move column to the right by one.
            (*column)++;
        }

        // If a spot for the word was found, break from loop.
        if (spotFound) {
            break;
        }
        
        // Reset column to leftmost since changing rows, then move to next row up.
        *column = 0;
        (*row)--;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going up, starting from bottom row and middle column.
bool upBottomMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the last row of the grid.
    *row = height - 1;

    // Initialize column as the middle one.
    *column = (length - 1) / 2;

    // Declare displacement variables for column.
    int displace2 = 0;
    unsigned int dispCol;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row, starting from bottom row until word's length cannot fit.
    while (*row + 1 >= wordLength) {
       
        // Check every column starting from middle and alternating outward.
        while (*column + abs(displace2) < length) {

            // If displace2 is negative, take it away from middle column to get current checking column.
            if (displace2 < 0) {
                dispCol = *column - (unsigned int)(displace2 * -1);
            }

            // Else, displace2 is positive and is added to middle column.
            else {
                dispCol = *column + (unsigned int)displace2;
            }

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkUp(letters, word, wordLength, row, &dispCol)) {
                spotFound = true;
                *column = dispCol;
                break;
            }

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
        
        // If a spot for the word was found, break from loop.
        if (spotFound) {
            break;
        }
        
        // Reset displace2 to 0 since changing rows, then move to next row up.
        displace2 = 0;
        (*row)--;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}


// Function for putting a word on the grid going diagonally up and right.
bool up_right(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height) {

    // If the word is longer than the length or height of the grid, then it cannot be placed diagonally.
    if (wordLength > length || wordLength > height) {
        return false;
    }

    // Declare row and column variables.
    unsigned int row, column;

    // Randomly define variable to hold function pointer of one of 9 searching algorithms.
    bool (*function)(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
    int random = rand() % 9;
    switch (random) {
        case 0:
            function = up_rightMiddleRight;
            break;
        case 1:
            function = up_rightMiddleLeft;
            break;
        case 2:
            function = up_rightMiddleMiddle;
            break;
        case 3:
            function = up_rightTopRight;
            break;
        case 4:
            function = up_rightTopLeft;
            break;
        case 5:
            function = up_rightTopMiddle;
            break;
        case 6:
            function = up_rightBottomRight;
            break;
        case 7:
            function = up_rightBottomLeft;
            break;
        case 8:
            function = up_rightBottomMiddle;
            break;
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

        // If letter already has a node, it was changed to lowercase by check function; continue to next letter.
        if (word[i] == tolower(word[i])) {
            continue;
        }

        // Store the index of the hash table chain for the letter's coordinates.
        hashIndex = hash(column + i, row - i);

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
        letters[hashIndex]->row = row - i;
        letters[hashIndex]->letter = word[i];

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

// Checks whether a word will fit going diagonally up and right from the given coordinates.
bool checkUp_right(ListNode** letters, char* word, unsigned int wordLength, unsigned int* row, unsigned int* column) {

    // Declare variable to signal whether the checked spot is taken and for node traversal.
    bool spotTaken = false;
    ListNode* node;

    // Go through every letter in the word to detect if its potential grid spot is already taken.
    for (unsigned int i = 0; i < wordLength && spotTaken == false; i++) {

        // Start at the first node of the hash table chain that the potential coordinates could already be in.
        node = letters[hash(*column + i, *row - i)];

        // Go through the linked list, searching for a node that already holds the coordinates.
        while (node != NULL) {

            // If current node does not hold the coordinates, move to the next node.
            if (!(node->column == *column + i && node->row == *row - i)) {
                node = node->next;
            }
            
            // Else if the node does hold the coordinates but the letter is the same, that works; move to next letter.
            else if (node->letter == word[i]) {

                // Mark that the letter does not need to have a node created in hash table later if word fits.
                word[i] = tolower(word[i]);

                break;
            }

            // Else, the potential spot is already taken by another letter.
            else {

                // Reset the word's letters if any were changed to lowercase.
                for (unsigned int j = 0; j < wordLength; j++) {
                    if (word[j] != toupper(word[j])) {
                        word[j] = toupper(word[j]);
                    }
                }

                spotTaken = true;
                break;
            }
        }
    }

    // Return whether or not the spot is available.
    return !spotTaken;
}

// Checks for a spot where word can be placed going diagonally up and right, starting from middle row and rightmost column.
bool up_rightMiddleRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the middle row of the grid.
    *row = (height - 1) / 2;

    // Set column to rightmost one where word's length can fit.
    *column = length - wordLength;

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
        
        // Only check current row if the word is not too long to fit from row.
        if (dispRow + 1 >= wordLength) {

            // Check every column starting from rightmost column to leftmost column.
            while (true) {

                // If function returns true, the spot is available, and passed row and column values are for that spot.
                if (checkUp_right(letters, word, wordLength, &dispRow, column)) {
                    spotFound = true;
                    break;
                }

                // If column 0 was checked, there is no spot for word on the row.
                if (*column == 0) {
                    break;
                }

                // Move column to the left by one.
                (*column)--;
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

        // Reset column to the rightmost possible for word's length since changing rows.
        *column = length - wordLength;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going diagonally up and right, starting from middle row and leftmost column.
bool up_rightMiddleLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {
    
    // Initialize row as the middle row of the grid.
    *row = (height - 1) / 2;

    // Initialize column as the leftmost one.
    *column = 0;

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
        
        // Only check current row if the word is not too long to fit from row.
        if (dispRow + 1 >= wordLength) {

            // Check every column going to the right until word cannot fit.
            while (!(length - *column < wordLength)) {

                // If function returns true, the spot is available, and passed row and column values are for that spot.
                if (checkUp_right(letters, word, wordLength, &dispRow, column)) {
                    spotFound = true;
                    break;
                }

                // Move column to the right by one.
                (*column)++;
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

        // Reset column to leftmost since changing rows.
        *column = 0;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going diagonally up and right, starting from middle row and middle column.
bool up_rightMiddleMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {
    
    // Initialize row as the middle row of the grid.
    *row = (height - 1) / 2;

    // Initialize column as the middle one.
    *column = (length - 1) / 2;

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
        
        // Only check current row if the word is not too long to fit from row.
        if (dispRow + 1 >= wordLength) {

            // Check every column starting from middle and alternating outward.
            while (*column + abs(displace2) < length) {

                // If displace2 is negative, take it away from middle column to get current checking column.
                if (displace2 < 0) {
                    dispCol = *column - (unsigned int)(displace2 * -1);
                }

                // Else, displace2 is positive and is added to middle column.
                else {
                    dispCol = *column + (unsigned int)displace2;
                }

                // If word fits and function returns true, the spot is available, and passed row and column values are for that spot.
                if (dispCol <= length - wordLength && checkUp_right(letters, word, wordLength, &dispRow, &dispCol)) {
                    spotFound = true;
                    *column = dispCol;
                    break;
                }

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

        // Reset displace2 to 0 since changing rows.
        displace2 = 0;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going diagonally up and right, starting from top row and rightmost column.
bool up_rightTopRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the highest row of the grid where word's length can fit.
    *row = wordLength - 1;

    // Set column to rightmost one where word's length can fit.
    *column = length - wordLength;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row starting at top until last row.
    while (*row < height) {
       
        // Check every column starting from rightmost column to leftmost.
        while (true) {

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkUp_right(letters, word, wordLength, row, column)) {
                spotFound = true;
                break;
            }

            // If column 0 was checked, there is no spot for word on the row.
            if (*column == 0) {
                break;
            }

            // Move column to the left by one.
            (*column)--;
        }

        // If a spot for the word was found, break from loop.
        if (spotFound) {
            break;
        }
        
        // Reset column to rightmost where word could fit since changing rows, then move to next row down.
        *column = length - wordLength;
        (*row)++;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going diagonally up and right, starting from top row and leftmost column.
bool up_rightTopLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the highest row of the grid where word's length can fit.
    *row = wordLength - 1;

    // Initialize column as the leftmost one.
    *column = 0;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row starting at top until last row.
    while (*row < height) {
       
        // Check every column going to the right until word cannot fit.
        while (!(length - *column < wordLength)) {

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkUp_right(letters, word, wordLength, row, column)) {
                spotFound = true;
                break;
            }

            // Move column to the right by one.
            (*column)++;
        }

        // If a spot for the word was found, break from loop.
        if (spotFound) {
            break;
        }
        
        // Reset column to leftmost since changing rows, then move to next row down.
        *column = 0;
        (*row)++;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going diagonally up and right, starting from top row and middle column.
bool up_rightTopMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the highest row of the grid where word's length can fit.
    *row = wordLength - 1;

    // Initialize column as the middle one.
    *column = (length - 1) / 2;

    // Declare displacement variables for column.
    int displace2 = 0;
    unsigned int dispCol;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row starting at top until last row.
    while (*row < height) {
       
        // Check every column starting from middle and alternating outward.
        while (*column + abs(displace2) < length) {

            // If displace2 is negative, take it away from middle column to get current checking column.
            if (displace2 < 0) {
                dispCol = *column - (unsigned int)(displace2 * -1);
            }

            // Else, displace2 is positive and is added to middle column.
            else {
                dispCol = *column + (unsigned int)displace2;
            }

            // If word fits and function returns true, the spot is available, and passed row and column values are for that spot.
            if (dispCol <= length - wordLength && checkUp_right(letters, word, wordLength, row, &dispCol)) {
                spotFound = true;
                *column = dispCol;
                break;
            }

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

        // If a spot for the word was found, break from loop.
        if (spotFound) {
            break;
        }
        
        // Reset displace2 to 0 since changing rows, then move to next row down.
        displace2 = 0;
        (*row)++;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going diagonally up and right, starting from bottom row and rightmost column.
bool up_rightBottomRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the last row of the grid.
    *row = height - 1;

    // Set column to rightmost one where word's length can fit.
    *column = length - wordLength;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row, starting from bottom row until word's length cannot fit.
    while (*row + 1 >= wordLength) {
       
        // Check every column starting from rightmost column to leftmost.
        while (true) {

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkUp_right(letters, word, wordLength, row, column)) {
                spotFound = true;
                break;
            }

            // If column 0 was checked, there is no spot for word on the row.
            if (*column == 0) {
                break;
            }

            // Move column to the left by one.
            (*column)--;
        }

        // If a spot for the word was found, break from loop.
        if (spotFound) {
            break;
        }
        
        // Reset column to rightmost where word fits since changing rows, then move to next row up.
        *column = length - wordLength;
        (*row)--;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going diagonally up and right, starting from bottom row and leftmost column.
bool up_rightBottomLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the last row of the grid.
    *row = height - 1;

    // Initialize column as the leftmost one.
    *column = 0;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row, starting from bottom row until word's length cannot fit.
    while (*row + 1 >= wordLength) {
       
        // Check every column going to the right until word cannot fit.
            while (!(length - *column < wordLength)) {

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkUp_right(letters, word, wordLength, row, column)) {
                spotFound = true;
                break;
            }

            // Move column to the right by one.
            (*column)++;
        }

        // If a spot for the word was found, break from loop.
        if (spotFound) {
            break;
        }
        
        // Reset column to leftmost since changing rows, then move to next row up.
        *column = 0;
        (*row)--;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going diagonally up and right, starting from bottom row and middle column.
bool up_rightBottomMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the last row of the grid.
    *row = height - 1;

    // Initialize column as the middle one.
    *column = (length - 1) / 2;

    // Declare displacement variables for column.
    int displace2 = 0;
    unsigned int dispCol;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row, starting from bottom row until word's length cannot fit.
    while (*row + 1 >= wordLength) {
       
        // Check every column starting from middle and alternating outward.
        while (*column + abs(displace2) < length) {

            // If displace2 is negative, take it away from middle column to get current checking column.
            if (displace2 < 0) {
                dispCol = *column - (unsigned int)(displace2 * -1);
            }

            // Else, displace2 is positive and is added to middle column.
            else {
                dispCol = *column + (unsigned int)displace2;
            }

            // If word fits and function returns true, the spot is available, and passed row and column values are for that spot.
            if (dispCol <= length - wordLength && checkUp_right(letters, word, wordLength, row, &dispCol)) {
                spotFound = true;
                *column = dispCol;
                break;
            }

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
        
        // If a spot for the word was found, break from loop.
        if (spotFound) {
            break;
        }
        
        // Reset displace2 to 0 since changing rows, then move to next row up.
        displace2 = 0;
        (*row)--;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}


// Function for putting a word on the grid going diagonally up and left.
bool up_left(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height) {

    // If the word is longer than the length or height of the grid, then it cannot be placed diagonally.
    if (wordLength > length || wordLength > height) {
        return false;
    }

    // Declare row and column variables.
    unsigned int row, column;

    // Randomly define variable to hold function pointer of one of 9 searching algorithms.
    bool (*function)(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
    int random = rand() % 9;
    switch (random) {
        case 0:
            function = up_leftMiddleRight;
            break;
        case 1:
            function = up_leftMiddleLeft;
            break;
        case 2:
            function = up_leftMiddleMiddle;
            break;
        case 3:
            function = up_leftTopRight;
            break;
        case 4:
            function = up_leftTopLeft;
            break;
        case 5:
            function = up_leftTopMiddle;
            break;
        case 6:
            function = up_leftBottomRight;
            break;
        case 7:
            function = up_leftBottomLeft;
            break;
        case 8:
            function = up_leftBottomMiddle;
            break;
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

        // If letter already has a node, it was changed to lowercase by check function; continue to next letter.
        if (word[i] == tolower(word[i])) {
            continue;
        }

        // Store the index of the hash table chain for the letter's coordinates.
        hashIndex = hash(column - i, row - i);

        // Store the first node of the chain.
        node = letters[hashIndex];

        // Make the new node, and set the array's element to point to it.
        letters[hashIndex] = malloc(sizeof(ListNode));
        if (letters[hashIndex] == NULL) {
            printf("Error: malloc() returned NULL.\n");
            return false;
        }

        // Set the values of the node with the coordinates and letter.
        letters[hashIndex]->column = column - i;
        letters[hashIndex]->row = row - i;
        letters[hashIndex]->letter = word[i];

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

// Checks whether a word will fit going diagonally up and left from the given coordinates.
bool checkUp_left(ListNode** letters, char* word, unsigned int wordLength, unsigned int* row, unsigned int* column) {

    // Declare variable to signal whether the checked spot is taken and for node traversal.
    bool spotTaken = false;
    ListNode* node;

    // Go through every letter in the word to detect if its potential grid spot is already taken.
    for (unsigned int i = 0; i < wordLength && spotTaken == false; i++) {

        // Start at the first node of the hash table chain that the potential coordinates could already be in.
        node = letters[hash(*column - i, *row - i)];

        // Go through the linked list, searching for a node that already holds the coordinates.
        while (node != NULL) {

            // If current node does not hold the coordinates, move to the next node.
            if (!(node->column == *column - i && node->row == *row - i)) {
                node = node->next;
            }
            
            // Else if the node does hold the coordinates but the letter is the same, that works; move to next letter.
            else if (node->letter == word[i]) {

                // Mark that the letter does not need to have a node created in hash table later if word fits.
                word[i] = tolower(word[i]);

                break;
            }

            // Else, the potential spot is already taken by another letter.
            else {

                // Reset the word's letters if any were changed to lowercase.
                for (unsigned int j = 0; j < wordLength; j++) {
                    if (word[j] != toupper(word[j])) {
                        word[j] = toupper(word[j]);
                    }
                }

                spotTaken = true;
                break;
            }
        }
    }

    // Return whether or not the spot is available.
    return !spotTaken;
}

// Checks for a spot where word can be placed going diagonally up and left, starting from middle row and rightmost column.
bool up_leftMiddleRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the middle row of the grid.
    *row = (height - 1) / 2;

    // Set column to rightmost one.
    *column = length - 1;

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
        
        // Only check current row if the word is not too long to fit from row.
        if (dispRow + 1 >= wordLength) {

            // Check every column starting from rightmost column to leftmost column where word could fit.
            while (wordLength - 1 <= *column) {

                // If function returns true, the spot is available, and passed row and column values are for that spot.
                if (checkUp_left(letters, word, wordLength, &dispRow, column)) {
                    spotFound = true;
                    break;
                }

                // Move column to the left by one.
                (*column)--;
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

        // Reset column to rightmost since changing rows.
        *column = length - 1;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going diagonally up and left, starting from middle row and leftmost column.
bool up_leftMiddleLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {
    
    // Initialize row as the middle row of the grid.
    *row = (height - 1) / 2;

    // Initialize column as the leftmost one that word could fit at.
    *column = wordLength - 1;

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
        
        // Only check current row if the word is not too long to fit from row.
        if (dispRow + 1 >= wordLength) {

            // Check every column going to the right.
            while (*column < length) {

                // If function returns true, the spot is available, and passed row and column values are for that spot.
                if (checkUp_left(letters, word, wordLength, &dispRow, column)) {
                    spotFound = true;
                    break;
                }

                // Move column to the right by one.
                (*column)++;
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

        // Reset column to leftmost where word could fit since changing rows.
        *column = wordLength - 1;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going diagonally up and left, starting from middle row and middle column.
bool up_leftMiddleMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {
    
    // Initialize row as the middle row of the grid.
    *row = (height - 1) / 2;

    // Initialize column as the middle one.
    *column = (length - 1) / 2;

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
        
        // Only check current row if the word is not too long to fit from row.
        if (dispRow + 1 >= wordLength) {

            // Check every column starting from middle and alternating outward.
            while (*column + abs(displace2) < length) {

                // If displace2 is negative, take it away from middle column to get current checking column.
                if (displace2 < 0) {
                    dispCol = *column - (unsigned int)(displace2 * -1);
                }

                // Else, displace2 is positive and is added to middle column.
                else {
                    dispCol = *column + (unsigned int)displace2;
                }

                // If word fits and function returns true, the spot is available, and passed row and column values are for that spot.
                if (dispCol >= wordLength - 1 && checkUp_left(letters, word, wordLength, &dispRow, &dispCol)) {
                    spotFound = true;
                    *column = dispCol;
                    break;
                }

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

        // Reset displace2 to 0 since changing rows.
        displace2 = 0;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going diagonally up and left, starting from top row and rightmost column.
bool up_leftTopRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the highest row of the grid where word's length can fit.
    *row = wordLength - 1;

    // Set column to rightmost one.
    *column = length - 1;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row starting at top until last row.
    while (*row < height) {
       
        // Check every column starting from rightmost column to leftmost where word could fit.
        while (wordLength - 1 <= *column) {

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkUp_left(letters, word, wordLength, row, column)) {
                spotFound = true;
                break;
            }

            // Move column to the left by one.
            (*column)--;
        }

        // If a spot for the word was found, break from loop.
        if (spotFound) {
            break;
        }
        
        // Reset column to rightmost since changing rows, then move to next row down.
        *column = length - 1;
        (*row)++;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going diagonally up and left, starting from top row and leftmost column.
bool up_leftTopLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the highest row of the grid where word's length can fit.
    *row = wordLength - 1;

    // Initialize column as the leftmost one that word could fit at.
    *column = wordLength - 1;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row starting at top until last row.
    while (*row < height) {
       
        // Check every column going to the right until last one.
        while (*column < length) {

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkUp_left(letters, word, wordLength, row, column)) {
                spotFound = true;
                break;
            }

            // Move column to the right by one.
            (*column)++;
        }

        // If a spot for the word was found, break from loop.
        if (spotFound) {
            break;
        }
        
        // Reset column to leftmost where word could fit since changing rows, then move to next row down.
        *column = wordLength - 1;
        (*row)++;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going diagonally up and left, starting from top row and middle column.
bool up_leftTopMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the highest row of the grid where word's length can fit.
    *row = wordLength - 1;

    // Initialize column as the middle one.
    *column = (length - 1) / 2;

    // Declare displacement variables for column.
    int displace2 = 0;
    unsigned int dispCol;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row starting at top until last row.
    while (*row < height) {
       
        // Check every column starting from middle and alternating outward.
        while (*column + abs(displace2) < length) {

            // If displace2 is negative, take it away from middle column to get current checking column.
            if (displace2 < 0) {
                dispCol = *column - (unsigned int)(displace2 * -1);
            }

            // Else, displace2 is positive and is added to middle column.
            else {
                dispCol = *column + (unsigned int)displace2;
            }

            // If word fits and function returns true, the spot is available, and passed row and column values are for that spot.
            if (dispCol >= wordLength - 1 && checkUp_left(letters, word, wordLength, row, &dispCol)) {
                spotFound = true;
                *column = dispCol;
                break;
            }

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

        // If a spot for the word was found, break from loop.
        if (spotFound) {
            break;
        }
        
        // Reset displace2 to 0 since changing rows, then move to next row down.
        displace2 = 0;
        (*row)++;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going diagonally up and left, starting from bottom row and rightmost column.
bool up_leftBottomRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the last row of the grid.
    *row = height - 1;

    // Set column to rightmost one.
    *column = length - 1;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row, starting from bottom row until word's length cannot fit.
    while (*row + 1 >= wordLength) {
       
        // Check every column starting from rightmost column to leftmost column where word could fit.
        while (wordLength - 1 <= *column) {

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkUp_left(letters, word, wordLength, row, column)) {
                spotFound = true;
                break;
            }

            // Move column to the left by one.
            (*column)--;
        }

        // If a spot for the word was found, break from loop.
        if (spotFound) {
            break;
        }
        
        // Reset column to rightmost since changing rows, then move to next row up.
        *column = length - 1;
        (*row)--;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going diagonally up and left, starting from bottom row and leftmost column.
bool up_leftBottomLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the last row of the grid.
    *row = height - 1;

    // Initialize column as the leftmost one that word could fit at.
    *column = wordLength - 1;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row, starting from bottom row until word's length cannot fit.
    while (*row + 1 >= wordLength) {
    
        // Check every column going to the right until last one.
        while (*column < length) {

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkUp_left(letters, word, wordLength, row, column)) {
                spotFound = true;
                break;
            }

            // Move column to the right by one.
            (*column)++;
        }

        // If a spot for the word was found, break from loop.
        if (spotFound) {
            break;
        }
        
        // Reset column to leftmost where word could fit since changing rows, then move to next row up.
        *column = wordLength - 1;
        (*row)--;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going diagonally up and left, starting from bottom row and middle column.
bool up_leftBottomMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the last row of the grid.
    *row = height - 1;

    // Initialize column as the middle one.
    *column = (length - 1) / 2;

    // Declare displacement variables for column.
    int displace2 = 0;
    unsigned int dispCol;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row, starting from bottom row until word's length cannot fit.
    while (*row + 1 >= wordLength) {
       
        // Check every column starting from middle and alternating outward.
        while (*column + abs(displace2) < length) {

            // If displace2 is negative, take it away from middle column to get current checking column.
            if (displace2 < 0) {
                dispCol = *column - (unsigned int)(displace2 * -1);
            }

            // Else, displace2 is positive and is added to middle column.
            else {
                dispCol = *column + (unsigned int)displace2;
            }

            // If word fits and function returns true, the spot is available, and passed row and column values are for that spot.
            if (dispCol >= wordLength - 1 && checkUp_left(letters, word, wordLength, row, &dispCol)) {
                spotFound = true;
                *column = dispCol;
                break;
            }

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
        
        // If a spot for the word was found, break from loop.
        if (spotFound) {
            break;
        }
        
        // Reset displace2 to 0 since changing rows, then move to next row up.
        displace2 = 0;
        (*row)--;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}


// Function for putting a word on the grid going diagonally down and right.
bool down_right(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height) {

    // If the word is longer than the height of the grid, then it cannot be placed vertically.
    if (wordLength > height) {
        return false;
    }

    // Declare row and column variables.
    unsigned int row, column;

    // Randomly define variable to hold function pointer of one of 9 searching algorithms.
    bool (*function)(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
    int random = rand() % 9;
    switch (random) {
        case 0:
            function = down_rightMiddleRight;
            break;
        case 1:
            function = down_rightMiddleLeft;
            break;
        case 2:
            function = down_rightMiddleMiddle;
            break;
        case 3:
            function = down_rightTopRight;
            break;
        case 4:
            function = down_rightTopLeft;
            break;
        case 5:
            function = down_rightTopMiddle;
            break;
        case 6:
            function = down_rightBottomRight;
            break;
        case 7:
            function = down_rightBottomLeft;
            break;
        case 8:
            function = down_rightBottomMiddle;
            break;
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

        // If letter already has a node, it was changed to lowercase by check function; continue to next letter.
        if (word[i] == tolower(word[i])) {
            continue;
        }

        // Store the index of the hash table chain for the letter's coordinates.
        hashIndex = hash(column + i, row + i);

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
        letters[hashIndex]->row = row + i;
        letters[hashIndex]->letter = word[i];

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

// Checks whether a word will fit going diagonally down and right from the given coordinates.
bool checkDown_right(ListNode** letters, char* word, unsigned int wordLength, unsigned int* row, unsigned int* column) {

    // Declare variable to signal whether the checked spot is taken and for node traversal.
    bool spotTaken = false;
    ListNode* node;

    // Go through every letter in the word to detect if its potential grid spot is already taken.
    for (unsigned int i = 0; i < wordLength && spotTaken == false; i++) {

        // Start at the first node of the hash table chain that the potential coordinates could already be in.
        node = letters[hash(*column + i, *row + i)];

        // Go through the linked list, searching for a node that already holds the coordinates.
        while (node != NULL) {

            // If current node does not hold the coordinates, move to the next node.
            if (!(node->column == *column + i && node->row == *row + i)) {
                node = node->next;
            }
            
            // Else if the node does hold the coordinates but the letter is the same, that works; move to next letter.
            else if (node->letter == word[i]) {

                // Mark that the letter does not need to have a node created in hash table later if word fits.
                word[i] = tolower(word[i]);

                break;
            }

            // Else, the potential spot is already taken by another letter.
            else {

                // Reset the word's letters if any were changed to lowercase.
                for (unsigned int j = 0; j < wordLength; j++) {
                    if (word[j] != toupper(word[j])) {
                        word[j] = toupper(word[j]);
                    }
                }

                spotTaken = true;
                break;
            }
        }
    }

    // Return whether or not the spot is available.
    return !spotTaken;
}

// Checks for a spot where word can be placed going diagonally down and right, starting from middle row and rightmost column.
bool down_rightMiddleRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the middle row of the grid.
    *row = (height - 1) / 2;

    // Set column to rightmost one where word's length can fit.
    *column = length - wordLength;

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
        
        // Only check current row if the word is not too long to fit from row.
        if (dispRow + wordLength <= height) {

            // Check every column starting from rightmost column to leftmost column.
            while (true) {

                // If function returns true, the spot is available, and passed row and column values are for that spot.
                if (checkDown_right(letters, word, wordLength, &dispRow, column)) {
                    spotFound = true;
                    break;
                }

                // If column 0 was checked, there is no spot for word on the row.
                if (*column == 0) {
                    break;
                }

                // Move column to the left by one.
                (*column)--;
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

        // Reset column to the rightmost one where word could fit since changing rows.
        *column = length - wordLength;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going diagonally down and right, starting from middle row and leftmost column.
bool down_rightMiddleLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {
    
    // Initialize row as the middle row of the grid.
    *row = (height - 1) / 2;

    // Initialize column as the leftmost one.
    *column = 0;

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
        
        // Only check current row if the word is not too long to fit from row.
        if (dispRow + wordLength <= height) {

            // Check every column going to the right until word cannot fit.
            while (!(length - *column < wordLength)) {

                // If function returns true, the spot is available, and passed row and column values are for that spot.
                if (checkDown_right(letters, word, wordLength, &dispRow, column)) {
                    spotFound = true;
                    break;
                }

                // Move column to the right by one.
                (*column)++;
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

        // Reset column to leftmost since changing rows.
        *column = 0;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going diagonally down and right, starting from middle row and middle column.
bool down_rightMiddleMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {
    
    // Initialize row as the middle row of the grid.
    *row = (height - 1) / 2;

    // Initialize column as the middle one.
    *column = (length - 1) / 2;

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
        
        // Only check current row if the word is not too long to fit from row.
        if (dispRow + wordLength <= height) {

            // Check every column starting from middle and alternating outward.
            while (*column + abs(displace2) < length) {

                // If displace2 is negative, take it away from middle column to get current checking column.
                if (displace2 < 0) {
                    dispCol = *column - (unsigned int)(displace2 * -1);
                }

                // Else, displace2 is positive and is added to middle column.
                else {
                    dispCol = *column + (unsigned int)displace2;
                }

                // If word fits and function returns true, the spot is available, and passed row and column values are for that spot.
                if (dispCol <= length - wordLength && checkDown_right(letters, word, wordLength, &dispRow, &dispCol)) {
                    spotFound = true;
                    *column = dispCol;
                    break;
                }

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

        // Reset displace2 to 0 since changing rows.
        displace2 = 0;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going diagonally down and right, starting from top row and rightmost column.
bool down_rightTopRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the top row of the grid.
    *row = 0;

    // Set column to rightmost one where word's length can fit.
    *column = length - wordLength;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row starting at top until word is longer than space left going down.
    while (height - *row >= wordLength) {
       
        // Check every column starting from rightmost column to leftmost.
        while (true) {

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkDown_right(letters, word, wordLength, row, column)) {
                spotFound = true;
                break;
            }

            // If column 0 was checked, there is no spot for word on the row.
            if (*column == 0) {
                break;
            }

            // Move column to the left by one.
            (*column)--;
        }

        // If a spot for the word was found, break from loop.
        if (spotFound) {
            break;
        }
        
        // Reset column to rightmost one where word could fit since changing rows, then move to next row down.
        *column = length - wordLength;
        (*row)++;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going diagonally down and right, starting from top row and leftmost column.
bool down_rightTopLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the top row of the grid.
    *row = 0;

    // Initialize column as the leftmost one.
    *column = 0;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row starting at top until word is longer than space left going down.
    while (height - *row >= wordLength) {
    
        // Check every column going to the right until word cannot fit.
        while (!(length - *column < wordLength)) {

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkDown_right(letters, word, wordLength, row, column)) {
                spotFound = true;
                break;
            }

            // Move column to the right by one.
            (*column)++;
        }

        // If a spot for the word was found, break from loop.
        if (spotFound) {
            break;
        }
        
        // Reset column to leftmost since changing rows, then move to next row down.
        *column = 0;
        (*row)++;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going diagonally down and right, starting from top row and middle column.
bool down_rightTopMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the top row of the grid.
    *row = 0;

    // Initialize column as the middle one.
    *column = (length - 1) / 2;

    // Declare displacement variables for column.
    int displace2 = 0;
    unsigned int dispCol;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row starting at top until word is longer than space left going down.
    while (height - *row >= wordLength) {
       
        // Check every column starting from middle and alternating outward.
        while (*column + abs(displace2) < length) {

            // If displace2 is negative, take it away from middle column to get current checking column.
            if (displace2 < 0) {
                dispCol = *column - (unsigned int)(displace2 * -1);
            }

            // Else, displace2 is positive and is added to middle column.
            else {
                dispCol = *column + (unsigned int)displace2;
            }

            // If word fits and function returns true, the spot is available, and passed row and column values are for that spot.
            if (dispCol <= length - wordLength && checkDown_right(letters, word, wordLength, row, &dispCol)) {
                spotFound = true;
                *column = dispCol;
                break;
            }

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

        // If a spot for the word was found, break from loop.
        if (spotFound) {
            break;
        }
        
        // Reset displace2 to 0 since changing rows, then move to next row down.
        displace2 = 0;
        (*row)++;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going diagonally down and right, starting from bottom row and rightmost column.
bool down_rightBottomRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the lowest row of the grid where word is not too long.
    *row = height - wordLength;

    // Set column to rightmost one where word's length can fit.
    *column = length - wordLength;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row, starting from bottom row until top.
    while (true) {
       
        // Check every column starting from rightmost column to leftmost.
        while (true) {

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkDown_right(letters, word, wordLength, row, column)) {
                spotFound = true;
                break;
            }

            // If column 0 was checked, there is no spot for word on the row.
            if (*column == 0) {
                break;
            }

            // Move column to the left by one.
            (*column)--;
        }

        // If a spot for the word was found or the top row was checked, break from loop.
        if (spotFound || *row == 0) {
            break;
        }
        
        // Reset column to the rightmost one where word could fit since changing rows, then move to next row up.
        *column = length - wordLength;
        (*row)--;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going diagonally down and right, starting from bottom row and leftmost column.
bool down_rightBottomLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the lowest row of the grid where word is not too long.
    *row = height - wordLength;

    // Initialize column as the leftmost one.
    *column = 0;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row, starting from bottom row until top.
    while (true) {
    
        // Check every column going to the right until word cannot fit.
        while (!(length - *column < wordLength)) {

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkDown_right(letters, word, wordLength, row, column)) {
                spotFound = true;
                break;
            }

            // Move column to the right by one.
            (*column)++;
        }

        // If a spot for the word was found or the top row was checked, break from loop.
        if (spotFound || *row == 0) {
            break;
        }
        
        // Reset column to leftmost since changing rows, then move to next row up.
        *column = 0;
        (*row)--;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going diagonally down and right, starting from bottom row and middle column.
bool down_rightBottomMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the lowest row of the grid where word is not too long.
    *row = height - wordLength;

    // Initialize column as the middle one.
    *column = (length - 1) / 2;

    // Declare displacement variables for column.
    int displace2 = 0;
    unsigned int dispCol;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row, starting from bottom row until top.
    while (true) {
       
        // Check every column starting from middle and alternating outward.
        while (*column + abs(displace2) < length) {

            // If displace2 is negative, take it away from middle column to get current checking column.
            if (displace2 < 0) {
                dispCol = *column - (unsigned int)(displace2 * -1);
            }

            // Else, displace2 is positive and is added to middle column.
            else {
                dispCol = *column + (unsigned int)displace2;
            }

            // If word fits and function returns true, the spot is available, and passed row and column values are for that spot.
            if (dispCol <= length - wordLength && checkDown_right(letters, word, wordLength, row, &dispCol)) {
                spotFound = true;
                *column = dispCol;
                break;
            }

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
        
        // If a spot for the word was found or the top row was checked, break from loop.
        if (spotFound || *row == 0) {
            break;
        }
        
        // Reset displace2 to 0 since changing rows, then move to next row up.
        displace2 = 0;
        (*row)--;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}


// Function for putting a word on the grid going diagonally down and left.
bool down_left(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height) {

    // If the word is longer than the height of the grid, then it cannot be placed vertically.
    if (wordLength > height) {
        return false;
    }

    // Declare row and column variables.
    unsigned int row, column;

    // Randomly define variable to hold function pointer of one of 9 searching algorithms.
    bool (*function)(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column);
    int random = rand() % 9;
    switch (random) {
        case 0:
            function = down_leftMiddleRight;
            break;
        case 1:
            function = down_leftMiddleLeft;
            break;
        case 2:
            function = down_leftMiddleMiddle;
            break;
        case 3:
            function = down_leftTopRight;
            break;
        case 4:
            function = down_leftTopLeft;
            break;
        case 5:
            function = down_leftTopMiddle;
            break;
        case 6:
            function = down_leftBottomRight;
            break;
        case 7:
            function = down_leftBottomLeft;
            break;
        case 8:
            function = down_leftBottomMiddle;
            break;
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

        // If letter already has a node, it was changed to lowercase by check function; continue to next letter.
        if (word[i] == tolower(word[i])) {
            continue;
        }

        // Store the index of the hash table chain for the letter's coordinates.
        hashIndex = hash(column - i, row + i);

        // Store the first node of the chain.
        node = letters[hashIndex];

        // Make the new node, and set the array's element to point to it.
        letters[hashIndex] = malloc(sizeof(ListNode));
        if (letters[hashIndex] == NULL) {
            printf("Error: malloc() returned NULL.\n");
            return false;
        }

        // Set the values of the node with the coordinates and letter.
        letters[hashIndex]->column = column - i;
        letters[hashIndex]->row = row + i;
        letters[hashIndex]->letter = word[i];

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

// Checks whether a word will fit going diagonally down and left from the given coordinates.
bool checkDown_left(ListNode** letters, char* word, unsigned int wordLength, unsigned int* row, unsigned int* column) {

    // Declare variable to signal whether the checked spot is taken and for node traversal.
    bool spotTaken = false;
    ListNode* node;

    // Go through every letter in the word to detect if its potential grid spot is already taken.
    for (unsigned int i = 0; i < wordLength && spotTaken == false; i++) {

        // Start at the first node of the hash table chain that the potential coordinates could already be in.
        node = letters[hash(*column - i, *row + i)];

        // Go through the linked list, searching for a node that already holds the coordinates.
        while (node != NULL) {

            // If current node does not hold the coordinates, move to the next node.
            if (!(node->column == *column - i && node->row == *row + i)) {
                node = node->next;
            }
            
            // Else if the node does hold the coordinates but the letter is the same, that works; move to next letter.
            else if (node->letter == word[i]) {

                // Mark that the letter does not need to have a node created in hash table later if word fits.
                word[i] = tolower(word[i]);

                break;
            }

            // Else, the potential spot is already taken by another letter.
            else {

                // Reset the word's letters if any were changed to lowercase.
                for (unsigned int j = 0; j < wordLength; j++) {
                    if (word[j] != toupper(word[j])) {
                        word[j] = toupper(word[j]);
                    }
                }

                spotTaken = true;
                break;
            }
        }
    }

    // Return whether or not the spot is available.
    return !spotTaken;
}

// Checks for a spot where word can be placed going diagonally down and left, starting from middle row and rightmost column.
bool down_leftMiddleRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the middle row of the grid.
    *row = (height - 1) / 2;

    // Set column to rightmost one.
    *column = length - 1;

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
        
        // Only check current row if the word is not too long to fit from row.
        if (dispRow + wordLength <= height) {

            // Check every column starting from rightmost column to leftmost column where word could fit.
            while (wordLength - 1 <= *column) {

                // If function returns true, the spot is available, and passed row and column values are for that spot.
                if (checkDown_left(letters, word, wordLength, &dispRow, column)) {
                    spotFound = true;
                    break;
                }

                // Move column to the left by one.
                (*column)--;
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

        // Reset column to the rightmost one since changing rows.
        *column = length - 1;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going diagonally down and left, starting from middle row and leftmost column.
bool down_leftMiddleLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {
    
    // Initialize row as the middle row of the grid.
    *row = (height - 1) / 2;

    // Initialize column as the leftmost one that word could fit at.
    *column = wordLength - 1;

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
        
        // Only check current row if the word is not too long to fit from row.
        if (dispRow + wordLength <= height) {

            // Check every column going to the right until last one.
            while (*column < length) {

                // If function returns true, the spot is available, and passed row and column values are for that spot.
                if (checkDown_left(letters, word, wordLength, &dispRow, column)) {
                    spotFound = true;
                    break;
                }

                // Move column to the right by one.
                (*column)++;
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

        // Reset column to leftmost where word could fit since changing rows.
        *column = wordLength - 1;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going diagonally down and left, starting from middle row and middle column.
bool down_leftMiddleMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {
    
    // Initialize row as the middle row of the grid.
    *row = (height - 1) / 2;

    // Initialize column as the middle one.
    *column = (length - 1) / 2;

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
        
        // Only check current row if the word is not too long to fit from row.
        if (dispRow + wordLength <= height) {

            // Check every column starting from middle and alternating outward.
            while (*column + abs(displace2) < length) {

                // If displace2 is negative, take it away from middle column to get current checking column.
                if (displace2 < 0) {
                    dispCol = *column - (unsigned int)(displace2 * -1);
                }

                // Else, displace2 is positive and is added to middle column.
                else {
                    dispCol = *column + (unsigned int)displace2;
                }

                // If word fits and function returns true, the spot is available, and passed row and column values are for that spot.
                if (dispCol >= wordLength - 1 && checkDown_left(letters, word, wordLength, &dispRow, &dispCol)) {
                    spotFound = true;
                    *column = dispCol;
                    break;
                }

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

        // Reset displace2 to 0 since changing rows.
        displace2 = 0;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going diagonally down and left, starting from top row and rightmost column.
bool down_leftTopRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the top row of the grid.
    *row = 0;

    // Set column to rightmost one.
    *column = length - 1;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row starting at top until word is longer than space left going down.
    while (height - *row >= wordLength) {
       
        // Check every column starting from rightmost column to leftmost where word could fit.
        while (wordLength - 1 <= *column) {

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkDown_left(letters, word, wordLength, row, column)) {
                spotFound = true;
                break;
            }

            // Move column to the left by one.
            (*column)--;
        }

        // If a spot for the word was found, break from loop.
        if (spotFound) {
            break;
        }
        
        // Reset column to rightmost one since changing rows, then move to next row down.
        *column = length - 1;
        (*row)++;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going diagonally down and left, starting from top row and leftmost column.
bool down_leftTopLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the top row of the grid.
    *row = 0;

    // Initialize column as the leftmost one that word could fit at.
    *column = wordLength - 1;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row starting at top until word is longer than space left going down.
    while (height - *row >= wordLength) {
    
        // Check every column going to the right until last row.
        while (*column < length) {

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkDown_left(letters, word, wordLength, row, column)) {
                spotFound = true;
                break;
            }

            // Move column to the right by one.
            (*column)++;
        }

        // If a spot for the word was found, break from loop.
        if (spotFound) {
            break;
        }
        
        // Reset column to leftmost where word could fit since changing rows, then move to next row down.
        *column = wordLength - 1;
        (*row)++;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going diagonally down and left, starting from top row and middle column.
bool down_leftTopMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the top row of the grid.
    *row = 0;

    // Initialize column as the middle one.
    *column = (length - 1) / 2;

    // Declare displacement variables for column.
    int displace2 = 0;
    unsigned int dispCol;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row starting at top until word is longer than space left going down.
    while (height - *row >= wordLength) {
       
        // Check every column starting from middle and alternating outward.
        while (*column + abs(displace2) < length) {

            // If displace2 is negative, take it away from middle column to get current checking column.
            if (displace2 < 0) {
                dispCol = *column - (unsigned int)(displace2 * -1);
            }

            // Else, displace2 is positive and is added to middle column.
            else {
                dispCol = *column + (unsigned int)displace2;
            }

            // If word fits and function returns true, the spot is available, and passed row and column values are for that spot.
                if (dispCol >= wordLength - 1 && checkDown_left(letters, word, wordLength, row, &dispCol)) {
                spotFound = true;
                *column = dispCol;
                break;
            }

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

        // If a spot for the word was found, break from loop.
        if (spotFound) {
            break;
        }
        
        // Reset displace2 to 0 since changing rows, then move to next row down.
        displace2 = 0;
        (*row)++;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going diagonally down and left, starting from bottom row and rightmost column.
bool down_leftBottomRight(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the lowest row of the grid where word is not too long.
    *row = height - wordLength;

    // Set column to rightmost one.
    *column = length - 1;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row, starting from bottom row until top.
    while (true) {
       
        // Check every column starting from rightmost column to leftmost where word could fit.
        while (wordLength - 1 <= *column) {

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkDown_left(letters, word, wordLength, row, column)) {
                spotFound = true;
                break;
            }

            // Move column to the left by one.
            (*column)--;
        }

        // If a spot for the word was found or the top row was checked, break from loop.
        if (spotFound || *row == 0) {
            break;
        }
        
        // Reset column to the rightmost one since changing rows, then move to next row up.
        *column = length - 1;
        (*row)--;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going diagonally down and left, starting from bottom row and leftmost column.
bool down_leftBottomLeft(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the lowest row of the grid where word is not too long.
    *row = height - wordLength;

    // Initialize column as the leftmost one that word could fit at.
    *column = wordLength - 1;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row, starting from bottom row until top.
    while (true) {
    
        // Check every column going to the right until last one.
        while (*column < length) {

            // If function returns true, the spot is available, and passed row and column values are for that spot.
            if (checkDown_left(letters, word, wordLength, row, column)) {
                spotFound = true;
                break;
            }

            // Move column to the right by one.
            (*column)++;
        }

        // If a spot for the word was found or the top row was checked, break from loop.
        if (spotFound || *row == 0) {
            break;
        }
        
        // Reset column to leftmost where word could fit since changing rows, then move to next row up.
        *column = wordLength - 1;
        (*row)--;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

// Checks for a spot where word can be placed going diagonally down and left, starting from bottom row and middle column.
bool down_leftBottomMiddle(ListNode** letters, char* word, unsigned int wordLength, unsigned int length, unsigned int height, unsigned int* row, unsigned int* column) {

    // Initialize row as the lowest row of the grid where word is not too long.
    *row = height - wordLength;

    // Initialize column as the middle one.
    *column = (length - 1) / 2;

    // Declare displacement variables for column.
    int displace2 = 0;
    unsigned int dispCol;

    // Declare variable to signal whether a spot for the word has been found.
    bool spotFound = false;

    // Check every row, starting from bottom row until top.
    while (true) {
       
        // Check every column starting from middle and alternating outward.
        while (*column + abs(displace2) < length) {

            // If displace2 is negative, take it away from middle column to get current checking column.
            if (displace2 < 0) {
                dispCol = *column - (unsigned int)(displace2 * -1);
            }

            // Else, displace2 is positive and is added to middle column.
            else {
                dispCol = *column + (unsigned int)displace2;
            }

            // If word fits and function returns true, the spot is available, and passed row and column values are for that spot.
                if (dispCol >= wordLength - 1 && checkDown_left(letters, word, wordLength, row, &dispCol)) {
                spotFound = true;
                *column = dispCol;
                break;
            }

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
        
        // If a spot for the word was found or the top row was checked, break from loop.
        if (spotFound || *row == 0) {
            break;
        }
        
        // Reset displace2 to 0 since changing rows, then move to next row up.
        displace2 = 0;
        (*row)--;
    }

    // If no spot was found during the check, word cannot be placed anywhere, return false.
    if (spotFound == false) {
        return false;
    }

    return true;
}

