/*******************************************************************************
* University of Maryland - European Division
* CMIS 140 - Mid Term Problem 4
*
* Program Description: This program prints the multiplication tables of the
* numbers 2 through 9 using multipliers of 1 through 10. No input is required
* from the user.
*
* Author: Patrick Nutt (Final version 17 September 2002)
*******************************************************************************/
#include<iostream>
#include<conio>         // for clrscr()
#include<iomanip>       // for setw()
using namespace std;

void PrintTable(int, int, int); // multiplication table for 2 through 9
void PrintHeader(int, int);     // 1 through 10 table header

int main()
{
        clrscr();
        PrintHeader(1,10);      // print 1 through 10 on top row

        // for each value from 2 through 9
        for (int count = 2; count <= 9; count++)
            PrintTable(count, 1, 10);

        getch();
        return 0;
}
/******************************************************************************/

/*******************************************************************************
* Function name void PrintTable
*
* Parameters: int number /in/ multiplicand value for table
*             int initialValue /in/ first multiplier
*             int finalValue   /in/ last multiplier
*
* This function receives three numbers. The value is multiplied by each number
* from initialValue through finalValue. A multiplication table is output
* with the results.
*
* Author: Patrick Nutt
* Last modified: 17 September 2002
*******************************************************************************/
void PrintTable(/*in*/ int number,
                /*in*/ int initialValue,
                /*in*/ int finalValue)
{
        cout << number << "\t";

        // for each value between initialValue and finalValue
        for (int count = initialValue; count <= finalValue; count++)
            cout << setw(3) << number * count << "  ";

        cout << endl << endl;
}
/******************************************************************************/

/*******************************************************************************
* Function name: void PrintHeader
*
* Parameters: int fNumber /in/ first number in range
*             int sNumber /in/ second number in range
*
* This function prints a row of numbers between fNumber and sNumber.
*
* Author: Patrick Nutt
* Last modified: 15 September 2002
*******************************************************************************/
void PrintHeader(int fNumber, int sNumber)
{
        cout << "\t";

        // for each number from fNumber through sNumber
        for (int count = fNumber; count <= sNumber; count++)
            cout << setw(3) << count << "  ";
        cout << "\n\n\n\n\n";
}
/******************************************************************************/

