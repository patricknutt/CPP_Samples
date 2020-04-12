//***********************************************************************************
// NAME: Patrick Nutt
// Program4
// CMIS 102
// DATE: 18 July 2002
// PROGRAM DESCRIPTION: Telephone Code
// This program returns a number that corresponds to a letter input by the user.
// The numbers and letters correspond to those found on the common telephone.
// 2 = ABC, 3 = DEF, 4 = GHI, 5 = JKL, 6 = MNO, 7 = PRS, 8 = TUV, & 9 = WXY.
// This program also tests the input letter to insure that it is an uppercase letter,
// and whether or not it is a Q or Z which are not on the telephone.
//***********************************************************************************
#include <iostream>
using namespace std;

int main()
{
        char letter;            // Input letter
        char number;            // Output number

        cout << "Enter a single uppercase letter, and I will tell you" << endl
             << "what the corresponding digit is on the telephone." << endl;
        cin  >> letter;

        if (letter >= 'A' && letter <= 'Z')     // Test for valid letter
              // This block is performed if the letter is a valid character
        {
            if (letter != 'Q' && letter != 'Z') // Test for Q or Z
              // This block is performed if the letter is not a Q or a Z
              // Assign number value
            {
                if (letter >= 'A' &&
                    letter <= 'C')

                    number = '2';

                else if (letter >= 'D' &&
                         letter <= 'F')

                         number = '3';

                else if (letter >= 'G' &&
                         letter <= 'I')

                         number = '4';

                else if (letter >= 'J' &&
                         letter <= 'L')

                         number = '5';

                else if (letter >= 'M' &&
                         letter <= 'O')

                         number = '6';

                else if (letter >= 'P' &&
                         letter <= 'S')

                         number = '7';

                else if (letter >= 'T' &&
                         letter <= 'V')

                         number = '8';

                else if (letter >= 'W' &&
                         letter <= 'Y')

                         number = '9';

                        // Print output result with message
                cout << "The letter " << letter << " corresponds to the number " << number
                     << endl << "on the telephone.";
            }           // If letter is Q or Z
            else
                cout << letter << " does not correspond to a digit on the telephone.";
        }               // If letter is invalid
        else
            cout << letter << " is not a valid uppercase letter. Please try again.";
        return 0;
}



