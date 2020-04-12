//************************************************************************************
// Name: Patrick Nutt
// Program 5
// CMIS 102
// Date: 25 July 2002
// Program Description: Magic Diamond
// This program accepts the input of a character and an integer from the user.
// A diamond is then constructed from this character with the maximum width being
// equal to the integer. The number is always forced to a positive integer.
// If the integer entered is an even number it is coerced to the next higher
// integer. This is to maintain the equalibrium of the shape. The program uses
// two sets of nested count-controlled loops. The key to the construction is the
// fact that the height of the diamond is always equal to the width. For example,
// if the number is 11 the diamond is 11 characters wide and 11 lines high.
//************************************************************************************
#include <iostream>
#include <iomanip>      // For setw() and setprecision()
#include <conio.h>      // For clrscr()
using namespace std;

int main()
{
        // Clear the screen
        clrscr();

        // Declare variables
        int diamondCount;  // Integer entered by user
        int innerLoop;  // Vertical control
        int mainLoop;   // Number of characters per line
                        // and number of lines per loop
        char ch;        // Building block of diamond

        // Get character and number
        cout << "This program will construct a diamond based on the character \n"
             << "that you will enter. The maximum width will also be determined \n"
             << "by you. Please enter a character followed by a number: \n";

        cin  >> ch >> diamondCount;

        // Handle negative number entry
        diamondCount = abs(diamondCount);

        // Handle even number entry
        if ((diamondCount % 2) == 0)
                diamondCount++;    // Coerced to the next higher integer

        mainLoop = 1;   // Initialize counters

        // Clear the screen
        clrscr();

        // Build the diamond

        // Build top half
        // Loop will count up by two until the value in diamondCount is reached
        while (mainLoop < diamondCount)
        {
                cout << setw(10 + (diamondCount - (mainLoop / 2)));  // Centers each line
                                                              // by setting width of
                                                              // first character
                innerLoop = 1;  // Initialize counter
                  // Loop counts up to the value in mainLoop
                while (innerLoop <= mainLoop)
                    {
                        cout << ch;
                        innerLoop++;    // Increment the counter
                    }

                mainLoop = mainLoop + 2;  // Each line has 2 more characters than the last
                innerLoop = 1;            // Reset the counter
                cout << endl;             // Start new line of diamond

        }
        // At this point mainLoop = diamondCount

        // Build Bottom half
        // Loops down until the value in mainLoop is -1
        while(mainLoop >= 1)    // The diamond always ends with 1 character
        {
                cout << setw(10 + (diamondCount - (mainLoop / 2)));  // Centers each line

                 // Loop counts up to the value in mainLoop
                while (innerLoop <= mainLoop)
                    {
                        cout << ch;
                        innerLoop++;    // Increment the counter
                    }
                mainLoop = mainLoop - 2;  // Each line has 2 less characters than the last
                innerLoop = 1;            // Reset the counter
                cout << endl;             // Start new line of diamond

        }
        return 0;
}
