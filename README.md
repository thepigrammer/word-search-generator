### USAGE OVERVIEW

#### Generates a word search as terminal output given a length and height for the board followed by words to include in the board. 
- The program asks whether or not the board should expand to fit words that cannot be placed. If enabled, this feature will grow both the length and height by 1 until the word can be placed.
- Words could be placed in one of eight directions, chosen at random.
- Word can overlap with other words if the letters are the same.
- To avoid predictability, the program uses randomness to decide where a word will be placed.
- The program will try every possible placement for a word in every direction before deciding that it cannot be placed. This is when the board would expand and retry if that feature is enabled.
- The Enter key should be pressed after typing a word to submit it. When all words have been entered, a single dot should be entered as the word, and the word search will then be printed in the terminal. The dot will not count as a word itself.
- Words must only contain alphabetical letters. Case does not matter when entering words, and all letters on the board will be uppercase.
---
### TECHNICAL DETAILS
- The board is not stored as a 2-D array. Instead, it only uses two unsigned int variables for the length and height, so the board's dimensions could be as big as the max unsigned int value without any memory issues.
- Words are stored as individual letters using a hash table. Nodes contain a column number, row number, and letter.
- When a word is entered, a direction is chosen. Then a spot is searched from one of 9 starting areas. The search will look at every possible spot for that direction until a spot is found or every possible spot was checked. This will repeat for every direction until the word is placed.
- The searching functions are specific to each direction and will not check a potential spot unless the word could definitely fit on the board there.
- The actual checking is to find out if there is already a (different) letter at a spot where the current word could have been placed.
- To check if a spot is taken, the hash table is checked for existing nodes containing the desired coordinates.
- Once all of the words have been stored, the program goes through and prints the word search. For each spot, it checks the hash table for a node holding the coordinates.
- If a spot does not have a letter stored for it, a random uppercase letter is printed.
- If a node is found for the spot, the letter stored there is printed and the node is removed from the hash table.
---
### MEMORY USED

#### The most memory used by the program at once only scales based on the word input and total letters stored. 
- The word being entered is stored in a dynamic array that gets bigger as needed while letters are typed by the user.
- As words are stored, more nodes are needed in the hash table to store their letters.
- Note: Searching for a spot does not require memory to store locations already checked, because the randomness is based on where the search starts. From there, an algorithm is used to check each spot that the word could fit at considering the direction it is intended to be placed in.
