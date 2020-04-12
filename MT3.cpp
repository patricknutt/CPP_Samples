/*******************************************************************************
* University of Maryland - European Division
* CMIS 140 - Mid Term Problem 3
*
* Program Description: This program receives two numbers from the user. The user
* also selects an operator from a menu. An expression is performed on the two
* numbers according to the operator chosen.
*
* Author: Patrick Nutt (Final version 17 September 2002)
*******************************************************************************/
#include<iostream>
#include<conio>         // for clrscr()
#include<iomanip>       // for setprecision()
#include<string>
using namespace std;

void DoMath(float, float, int, float&, string&); // performs expression
int GetOperator();         // gives user a menu to choose from
float GetValue();         // accept input from user


int main()
{
        float fNumber;    // first number
        float sNumber;    // second number
        float result;     // final result
        int choice;       // result from menu selection
        char again;       // 'y' or 'n'
        string opString;  // operation string

        cout << fixed << setprecision(2);

        do      // Yes or No Loop
        {

                clrscr();

                // get first value
                cout << "Enter the first number:\n";
                fNumber = GetValue();

                // determine operator
                choice = GetOperator();

                clrscr();

                // get second value
                cout << "Enter the second number:\n";
                sNumber = GetValue();

                // prevent divide by zero error
                if (choice == 4 && sNumber == 0)
                {
                        cout << "Dividing by zero is not allowed. Please enter "
                             << "another number.\n";
                        sNumber = GetValue();
                }

                // perform calculation
                DoMath(fNumber, sNumber, choice, result, opString);

                // output
                clrscr();
                cout << "The result of " << fNumber << opString << sNumber
                     << " is " << result
                     << "\nWould you like to perform another calculation? (y or n)\n";
                cin  >> again;

                // y or n not entered
                while (again != 'y' && again != 'n')
                {
                        cout << "Please select 'y' or 'n' only. (check the CAPS LOCK)\n";
                        cin >> again;
                }
        }while (again == 'y');  // repeat if answer is y
        return 0;
}

/*******************************************************************************
* Function name: int GetOperator
*
* Return value: choice as int
*
* This function provides the user a menu of operators to choose from. The choice
* is returned to the calling function
*
* Author: Patrick Nutt
* Last modified: 17 September 2002
*******************************************************************************/
int GetOperator()
{
        int choice;

        clrscr();
        cout << "Please choose from the following menu:\n\n"
             << "1. add\n"
             << "2. subtract\n"
             << "3. multiply\n"
             << "4. divide\n";
        choice = int(GetValue());

        // something other than 1 through 4 entered
        while (choice < 1 || choice > 4)
        {
                cout << "Please choose 1-4 only.\n";
                choice = int(GetValue());
        }
        return choice;
}
/******************************************************************************/

/*******************************************************************************
* Function name: void DoMath
*
* Parameters: float fNumber /in/ first number
*             float sNumber /in/ second number
*             int opChoice   /in/ choice of operator
*             float& answer /out/ result of expression
*             string& opString /out/ string representing operator
*
* This function performs a calculation on two numbers. The operator is passed by
* value from the calling function. The result is output along with a string
* representing the operator used to perform the calculation.
*
* Author: Patrick Nutt
* Last modified: 15 September 2002
*******************************************************************************/
void DoMath (/*in*/ float fNumber,
             /*in*/ float sNumber,
             /*in*/ int opChoice,
             /*out*/ float& answer,
             /*out*/ string& opString)
{

        switch (opChoice)
        {
             case 1:  // add
                answer = fNumber + sNumber;
                opString = " plus ";
                break;
             case 2: // subtract
                answer = fNumber - sNumber;
                opString = " minus ";
                break;
             case 3: // multiply
                answer = fNumber * sNumber;
                opString = " times ";
                break;
             case 4: // divide
                answer = fNumber / sNumber;
                opString = " divided by ";
                break;
        }
}
/******************************************************************************/

/*******************************************************************************
* Function name float GetValue
*
* Return value: floating point number
*
* This function reads a floating point value from the keyboard and returns it to
* the calling function.
*
* Author: Patrick Nutt
* Last modified: 15 September 2002
*******************************************************************************/
float GetValue()
{
        float value;
        cin >> value;

        while(!cin)     // input stream failure
        {
            cout << "You must enter a number here. Please try again.\n";
            cin.clear();
            cin.ignore(50,'\n');
            cin >> value;
        }
        return value;
}
/******************************************************************************/





