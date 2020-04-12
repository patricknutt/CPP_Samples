/*******************************************************************************
* University of Maryland -- European Division
* CMIS 240 -- Mid Term 1 Program 2
*
* This program simulates a dice game between a two die. Each die is "rolled" and
* the face values are compared to find the highest. The die with the highest
* face value is declared to be the winner. If the die values are equal, a tie is
* declared. Appropriate messages are displayed for each instance.
*
* Author: Patrick Nutt -- 21 November 2002
*******************************************************************************/
#include<iostream>
#include<stdlib>        // for srand()
#include<time>          // time is used as a seed
#include<string>
#include<conio>         // for clrscr()
#include"die.h"         // Die class
using namespace std;

string ShowWinner(Comparison);  // return appropriate message

int main()
{
        Die myDie1,
            myDie2;
        char op;
        int total;
        string strGameResult;
        Comparison testResult;
        time_t tSeed;

        // seed random number generator
        srand ((unsigned) time(&tSeed));

        cout << "The following two options are available now, and after each roll.\n"
             << "Type 'r' to roll dice. Type 'q' to quit.";
        cin  >> op;
        clrscr();

        while (tolower(op) == 'r')
        {
                myDie1.RollDie();
                myDie2.RollDie();
                cout << "First Die: " << myDie1.GetValue() << endl;
                cout << "Second Die: " << myDie2.GetValue() << endl << endl;

                testResult = CompareDie(myDie1, myDie2);

                // print appropriate message
                strGameResult = ShowWinner(testResult);
                cout << strGameResult << endl;

                // wait for user to roll again or quit
                cin  >> op;
                clrscr();
        }
        return 0;
}
/******************************************************************************/

/*******************************************************************************
* ShowWinner
*
* Parameter: Comparison testValue /in/ integer value represneting winning die
* Return value: string msgString -- appropriate message corresponding to value of
* testValue.
*
* This function recievs a value of Comparison type, and returns the appropriate
* message to the calling function.
*
* Author: Patrick Nutt --   21 November 2002
*******************************************************************************/
string ShowWinner(/*in*/ Comparison testValue)
{
        string msgString;
        switch (testValue)
        {
            case SAME:
                   msgString = "It's a tie!";
                   break;
            case ONE_HIGHER:
                   msgString = "Number one wins!";
                   break;
            case TWO_HIGHER:
                   msgString = "Number two wins!";
                   break;
        }
        return msgString;
}
/***********************************End of File********************************/

