#include <stdio.h>
#include "MacUILib.h"
#include "myStringLib.h"   // This is your first custom C library

// [TODO] Import the required library for rand() and srand()
// [TODO] Import the required library for accessing the current time - for seeding random number generation





// PREPROCESSOR DIRECTIVE CONSTANTS
// ================================
// For program-wide constants, define them here using #define.  Add as seen needed.

// [COPY AND PASTE FROM PPA2] Copy your additional preprocessor constants from PPA2 and paste them below


// [TODO] Then, define more constants here as seen needed.





// GLOBAL VARIABLES
// ================================

int exitFlag; // Program Exiting Flag

// [COPY AND PASTE FROM PPA2] Copy your additional global from PPA2 and paste them below

// [TODO] Declare More Global Variables as seen needed.

// [TODO] Declare Global Pointers as seen needed / instructed in the manual.








// FUNCTION PROTOTYPES
// ================================
// Declare function prototypes here, so that we can organize the function implementation after the main function for code readability.

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

// [TODO] In PPA3, you will need to implement this function to generate random items on the game board
//        to set the stage for the Scavenger Hunter game.
// list[]       The pointer to the Item Bin
// listSize     The size of the Item Bin (5 by default)
// playerPos    The pointer to the Player Object, read only.
// xRange       The maximum range for x-coordinate generation (probably the x-dimension of the gameboard?)
// yRange       The maximum range for y-coordinate generation (probably the y-dimension of the gameboard?)
// str          The pointer to the start of the Goal String (to choose the random characters from)
void GenerateItems(struct objPos list[], const int listSize, const struct objPos *playerPos, const int xRange, const int yRange, const char* str);




// MAIN PROGRAM
// ===============================
int main(void)
{

    Initialize();

    while(!exitFlag)  
    {
        GetInput();

        RunLogic();

        DrawScreen();

        LoopDelay();
    }

    CleanUp();

}




// INITIALIZATION ROUTINE
// ===============================
void Initialize(void)
{
    MacUILib_init();

    MacUILib_clearScreen();

    // [COPY AND PASTE FROM PPA2] Copy your initialization routine from PPA2 and paste them below

    
    // [TODO] Initialize any global variables as required.
    exitFlag = 0;  // 0 - do not exit, non-zero - exit the program

    
    // [TODO] Allocated heap memory for on-demand variables as required.  Initialize them as required.

    // [TODO] Seed the random integer generation function with current time.

    // [TODO] Generate the initial random items on the game board at the start of the game.

    
}




// INPUT COLLECTION ROUTINE
// ===============================
void GetInput(void)
{

    // Asynchronous Input - non blocking character read-in
    
    // [COPY AND PASTE FROM PPA2] Copy your input collection routine from PPA2 and paste them below

    // [TODO] Though optional for PPA3, you may insert any additional logic for input processing.

   
}




// MAIN LOGIC ROUTINE
// ===============================
void RunLogic(void)
{
    // [COPY AND PASTE FROM PPA2] Copy your main logic routine from PPA2 and paste them below

    // [TODO]   Implement the Object Collision logic here
    //
    //      Simple Collision Algorithm
    //      1. Go through all items on board and check their (x,y) against the player object x and y.
    //      2. If a match is found, use the ASCII symbol of the collided character, and 
    //         find all the occurrences of this ASCII symbol in the Goal String
    //      3. For every occurrence, reveal its ASCII character at the corresponding location in the
    //         Collected String
    //      4. Then, determine whether the game winning condition is met.

    // [TODO]   Implement Game Winning Check logic here
    //
    //      Game Winning Check Algorithm
    //      1. Check if the contents of the Collected String exactly matches that of the Goal String.
    //         YOU MUST USE YOUR OWN my_strcmp() function from Lab 3.
    //      2. If matched, end the game.
    //      3. Otherwise, discard the current items on the game board, and 
    //         generate a new set of random items on the board.  Game continues.
    
}



// DRAW ROUTINE
// ===============================
void DrawScreen(void)
{
       
    // [COPY AND PASTE FROM PPA2] Copy your draw logic routine from PPA2 and paste them below

    // [TODO]   Insert somewhere in the draw routine to draw the randomly generated items on the board.

    // [TODO]   Display the "Mystery String" contents at the bottom of the game board
    //          To help players keep track of their game progress.
    
    
    
}



// DELAY ROUTINE
// ===============================
void LoopDelay(void)
{
    MacUILib_Delay(100000); // 0.1s delay
}





// TEAR-DOWN ROUTINE
// ===============================
void CleanUp(void)
{
    // [TODO]   To prevent memory leak, free() any allocated heap memory here
    //          Based on the PPA3 requirements, you need to at least deallocate one heap variable here.

    // Insert any additional end-game actions here.
    

    MacUILib_uninit();
}




// The Item Generation Routine
////////////////////////////////////
void GenerateItems(struct objPos list[], const int listSize, const struct objPos *playerPos, const int xRange, const int yRange, const char* str)
{
    // This is possibly one of the most conceptually challenging function in all PPAs
    // Once you've mastered this one, you are ready to take on the 2SH4 course project!

    // Random Non-Repeating Item Generation Algorithm
    ////////////////////////////////////////////////////

    // Use random number generator function, rand(), to generate a random x-y coordinate and a random choice of character from the Goal String as the ASCII character symbol.
    //      The x and y coordinate range should fall within the xRange and yRange limits, which should be the x- and y-dimension of the board size.
    // This will then be a candidate of the randomly generated Item to be placed on the game board.

    // In order to make sure this candidate is validated, it needs to meet both criteria below:
    //  1. Its coordinate and symbol has not been previously generated (no repeating item)
    //  2. Its coordinate does not overlap the Player's position
    // Thus, for every generated item candidate, check whether its x-y coordinate and symbol has previously generated.  
    //  Also, check if it overlaps the player position
    //      If yes, discard this candidate and regenerate a new one
    //      If no, this candidate is validated.  Add it to the input list[]

    // There are many efficient ways to do this question
    //  We will take a deep dive into some methods in 2SI.

}
