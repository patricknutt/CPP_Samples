/*******************************************************************************
* University of Maryland - European Division
* CMIS 140 - Programming Project 2
*
* Program Description: This program prints rows of squares on the screen. The
* number of lines as well as the number of squares per line will be accepted from
* the user. The input must be a positive integer.
*
* Author: Patrick Nutt (Final version 17 September 2002)
*******************************************************************************/
#include<iostream>
#include<conio>         // for clrscr()
#include<string>        // for square sides
using namespace std;

void GetValues (int&, int&);    // read integers and test for negative
void PrintSquares (int, int);   // print squares
void PrintSqSides (int, string); // print squares sides
int ReadInteger ();             // read individual integer

int main ()
{
        int nSquares;   // number of squares per line
        int nLines;     // number of lines to print

        clrscr();
        cout << "*******************************************************************************\n"
             << "* This program will ask you to determine the number of squares to be printed. *\n"
             << "* It will also allow you to determine the number of lines to print.           *\n"
             << "*******************************************************************************"
             << "\n\n\n\n\n\n\n\n\n\n"
             << "Press enter key to continue.\n";
        getchar();

        // get number of squares and lines
        GetValues (nSquares, nLines);    // pass by reference

        // output squares to screen
        PrintSquares (nSquares, nLines); // pass by value

        cout << "Press any key to exit.....\n";
        getch();
        return 0;
}
/******************************************************************************/

/*******************************************************************************
* Function name: void GetValues
*
* Parameters: int& fNumber /out/ first integer to be returned to calling function
*             int& sNumber /out/ second integer to be returned to calling function
*
* This function prompts the user for two integers. The integers are tested to
* make sure they are positive. The integers are assigned to two variables that
* are passed by reference into the calling function.
*
* Author: Patrick Nutt
* Last modified: 17 September 2002
*******************************************************************************/

void GetValues( /*out*/ int& fNumber,
                /*out*/ int& sNumber)

// Postcondition:
//      fNumber && sNumber are positive integers

{
        clrscr();

        // get first number
        cout << "Please enter the number of squares you want printed on each line.\n";
        fNumber = ReadInteger();

        // get second number
        cout << "Please enter the total number of lines you want printed.\n";
        sNumber = ReadInteger();

        // ensure integers are positive
        while (fNumber < 0 || sNumber < 0)      // either one or both integers are negative
        {
                if (fNumber < 0)
                {
                        if (sNumber < 0)        // if fNumber & sNumber are both negative
                         {
                              cout << "You have entered negative values.\n"
                                   << "Please enter the number of squares.\n";
                              fNumber = ReadInteger();
                              cout << "Please enter the number of lines.\n";
                              sNumber = ReadInteger();
                         }
                         else   // if fNumber is negative & sNumber is positive
                         {
                              cout << "You have entered a negative value for the number of squares.\n"
                                   << "Please enter a positive integer.\n";
                              fNumber = ReadInteger();
                         }
                }
                else            // if fNumber is positive & sNumber is negative
                {
                      cout << "You have entered a negative value for the number of lines.\n"
                           << "Please enter a positive integer.\n";
                      sNumber = ReadInteger();
                }
        }
}
/******************************************************************************/

/*******************************************************************************
* Function name: int ReadInteger
*
* Return Value: intInput as integer
*
* This function reads an input from the keyboard and determines if it is a valid
* integer. If not, the function loops until a valid integer is entered.
*
* Author: Patrick Nutt
* Last modified: 17 September 2002
*******************************************************************************/

int ReadInteger()
{
        int intInput;   // value to be returned
        cin >> intInput;

        while (!cin)    // test for input stream failure
        {
                cout << "This was not a valid integer.\n"
                     << "Please try again.\n";
                cin.clear();
                cin.ignore(50,'\n');
                cin >> intInput;
        }
        clrscr();
        return intInput;
}
/******************************************************************************/

/*******************************************************************************
* Function name: void PrintSquares
*
* Parameters: int nSquares /in/ number of squares to be printed
*             int nLines   /in/ number of lines to be printed
*
* This function prints lines of squares. The number of squares per line and the total
* number of lines is passed into the function
*
* Author: Patrick Nutt
* Last Modified: 17 September 2002
*******************************************************************************/

void PrintSquares(/*in*/ int nSquares,
                  /*in*/ int nLines)
{
        int lnCount;         // counter for number of lines
        int sqCount;         // counter for number of squares
        string hSides;       // for top and bottom of each square
        string vSides;       // for sides of each sqauare

        // assign square sides
        hSides = "  --  ";
        vSides = " |  | ";

        clrscr();

        // if zero was entered for number of lines and/or number of squares
        if (nSquares == 0 || nLines == 0)
        {
                cout << "You have chosen to print zero squares.\n"
                     << "Press any key to exit....\n";
                getch();
                exit(1);
        }

        cout << nLines<< " lines of " << nSquares
             << " squares to be printed. " << endl
             << "Press any key to continue..." << endl;
        getch();
        clrscr();
        for (lnCount = 1; lnCount <= nLines; lnCount++)
        {
                // tops
                PrintSqSides (nSquares, hSides);

                // sides
                PrintSqSides (nSquares, vSides);

                // bottoms
                PrintSqSides (nSquares, hSides);
        }
        cout << "\n\n\n\n";
}

/*****************************************************************************/

/*******************************************************************************
* Function name: PrintSqSides
*
* Parameters: int nSquares /in/ number of squares to be printed
*             string sides /in/ string expression representing sides to be printed
*
* This function prints the sides of each square required by the nSquares parameter.
* The side to be printed is passed into the sides parameter by the calling function.
*
* Author: Patrick Nutt
* Last modified: 17 September 2002
*******************************************************************************/
void PrintSqSides(/*in*/ int nSquares,
                  /*in*/ string sides)
{
        for (int sqCount = 1; sqCount <= nSquares; sqCount++)
             cout << sides;
        cout << endl;
}
/******************************************************************************/
