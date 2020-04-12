/*******************************************************************************
* University of Maryland - European Division
* CMIS 140 - Programming Project 2
*
* Program Description: This program prints rows of squares on the screen. The
* number of lines as well as the number of squares per line will be accepted from
* the user. The input must be a positive integer.
*
* Author: Patrick Nutt (Final version 24 September 2002)
*******************************************************************************/
#include<iostream>
#include<conio>
#include<iomanip>
using namespace std;

void GetValues (int&, int&);
int ReadInteger ();
void PrintSquares (int, int);

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
             << "Press any key to continue.\n";
        getch();

        // get number of squares and lines
        GetValues (nSquares, nLines);    // pass by reference
        PrintSquares (nSquares, nLines); // pass by value

        cout << "Press any key to exit.....\n";
        getch();
        return 0;
}


/*******************************************************************************
* Function name: void GetValues
*
* Parameters: int& fNumber /out/ first integer to be ruturned to calling function
*             int& sNumber /out/ second integer to be returned to calling function
*
* This function prompts the user for two integers. The integers are tested to
* make sure they are positive. The integers are assigned to two variables that
* passed by refernece into the funcion.
*
* Author: Patrick Nutt
* Last modified: 24 September 2002
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

        // check to see if integers are negative
        while (fNumber < 0 || sNumber < 0)
        {
        if (fNumber < 0)
        {
                if (sNumber < 0)
                {
                        cout << "You have entered negative values.\n"
                             << "Please enter the number of squares.\n";
                        fNumber = ReadInteger();
                        cout << "Please enter the number of lines.\n";
                        sNumber = ReadInteger();
                }
                else
                {
                        cout << "You have entered a negative value for the number of squares.\n"
                             << "Please enter a positive integer.\n";
                        fNumber = ReadInteger();
                }
        }
        else if (sNumber < 0)
        {
                cout << "You have entered a negative value for the number of lines.\n"
                     << "Please enter a positive integer.\n";
                sNumber = ReadInteger();
        }
        }
}

/*******************************************************************************
* Function Name: int ReadInteger
*
* Return Value: intInput as integer
*
* This function reads an input from the keyboard and determines if is a valid
* integer. If not, the function loops until a valid integer is entered.
*
* Author: Patrick Nutt
* Last modified: 24 September 2002
*******************************************************************************/

int ReadInteger()
{
        int intInput;   // value to be returned
        cin >> intInput;

        while (!cin)
        {
                cout << "This was not a valid integer.\n"
                     << "Please try again.\n";
                cin.clear();
                cin.ignore(1,'\n');
                cin >> intInput;
        }
        clrscr();
        return intInput;
}

/*******************************************************************************
* Function name: void PrintSquares
*
* Parameters: int nSquares /in/ number of squares to be printed
*             int nLines   /in/ number of lines to be printed
*
* This functions lines of squares. The number of squares per line and the total
* number of lines is passed into the function
*
* Author: Patrick Nutt
* Last Modified: 24 September 2002
*******************************************************************************/

void PrintSquares(int nSquares, int nLines)
{
        int x;         // counter for number of lines
        int y;       // counter for number of squares
        int z;
        z = 0;
        clrscr();
        cout << nLines<< " lines of " << nSquares
             << " squares to be printed. " << endl
             << "Press any key to continue..." << endl;
        getch();
        clrscr();
        for (x = 1; x <= nLines; x++)
        {
                for (y = 1; y <= nSquares; y++)
                    cout << "  --  ";

                cout << endl;
                for (y = 1; y <= nSquares; y++)
                    cout << " |" << setw(2) << y + z << "| ";

                cout << endl;

                for (y = 1; y <= nSquares; y++)
                    cout << "  --  ";

                cout << endl;
                z = z +nSquares;
        }
        cout << "\n\n\n\n";
}


