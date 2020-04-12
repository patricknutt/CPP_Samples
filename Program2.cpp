//***********************************************************************************
//NAME: Patrick Nutt
//Program2
//CMIS 102
//DATE: 9 July 2002
//PROGRAM DESCRIPTION: Arithmetic Operators Program
//This program performs calculations using the integer division, floating-point
//division, and modulus arithmetic operators and displays the results.
//***********************************************************************************
#include <iostream>
#include <iomanip>      // For setprecision

using namespace std;

const int NUM = 7;      // Dividend
const int DEN = 4;      // Divisor

int main ()
{
        // Declare variables

        int intAnswer;
        float floatAnswer;
        int modAnswer;

        // Calculate results

        intAnswer = NUM/DEN;
        floatAnswer = float(NUM) / float(DEN);  // Type cast integer values as floats
        modAnswer = NUM % DEN;

        // Output results

        cout << fixed << showpoint      // Set floating-point output
             << setprecision (2);       // format precision to 2 digits.

        cout << endl << NUM << " / " << DEN << " using integer division equals "
             << intAnswer << endl
             << NUM << " / " << DEN << " using floating-point division equals "
             << floatAnswer << endl
             << NUM << " modulo " << DEN << " equals "
             << modAnswer << endl;
        return 0;
}

