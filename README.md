__USAGE OVERVIEW__

Generates a word search as terminal output given a length and height for the board followed by words to include in the board. 
- The program asks whether or not the board should expand to fit words that cannot be placed. If enabled, this feature will grow both the length and height by 1 until the word can be placed.
- Words could be placed in one of eight directions, chosen at random.
- Word can overlap with other words if the letters are the same.
- To avoid predictability, the program uses randomness to decide where a word will be placed.
- The program will try every possible placement for a word in every direction before deciding that it cannot be placed. This is when the board would expand and retry if that feature is enabled.
- The Enter key should be pressed after typing a word to submit it. When all words have been entered, a single dot should be entered as the word, and the word search will then be printed in the terminal. The dot will not count as a word itself.
- Words must only contain alphabetical letters. Case does not matter when entering words, and all letters on the board will be uppercase.

__TECHNICAL DETAILS__
- The board is not stored as a 2-D array. Instead, it only uses two unsigned int variables for the length and height.
- Words are stored as individual letters using a hash table. Nodes contain a column, row, and letter.
- When a word is entered, a direction is chosen, then a spot is searched from one of 9 starting areas. The search will look at every possible spot for that direction until a spot is found or every possible spot was checked. This will repeat for every direction until the word is placed.
- The searching functions are specific to each direction and will not check a potential spot unless the word could definitely fit on the board there.
- The actual checking is to find out if there is already a (different) letter at a spot where the current word could have been placed.
