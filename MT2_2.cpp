/*******************************************************************************
* University of Maryland -- European Division
* CMIS 140 -- MidTerm 2 Problem 2
*
* Program Description: This program receives the dimensions of a box from the
* user. This information is then tested to determine if the box is a cube. To be
* a cube, all three dimensions must be equal.
*
* Author: Patrick Nutt
* Last modified: 28 September 2002
*******************************************************************************/
#include<iostream>
using namespace std;

struct Box
{
     int length,
         width,
         height;
};

void InputBox(Box&);    // get dimensions
bool IsCube(Box);       // test for equal sides
int GetInteger();       // get integer from user

int main()
{
        Box testBox;    // user defined box

        // define dimensions
        InputBox(testBox);

        // echo dimensions
        cout << "\nLength: " << testBox.length << "\n Width: " << testBox.width
             << "\nHeight: " << testBox.height << endl;

        // test box
        if (IsCube(testBox))
            cout << "\nCongratulations! This box is a cube!" << endl;
        else
            cout << "\nSorry! This box is not a cube." << endl;

        getchar();
        return 0;
}
/******************************************************************************/

/*******************************************************************************
* Function name: void InputBox
*
* Parameters: Box userBox /out/ box to be defined by user
*
* This function accepts an input of the length, width and height of a box.
*
* Author: Patrick Nutt
* Last modified: 28 September 2002
*******************************************************************************/
void InputBox(/*out*/ Box& userBox)
{
        cout << "Please enter the length of your box: ";
        userBox.length = GetInteger();
        
        cout << "\nPlease enter the width of your box:  ";
        userBox.width = GetInteger();

        cout << "\nPlease enter the height of your box: ";
        userBox.height = GetInteger();
}
/******************************************************************************/

/*******************************************************************************
* Function name: int GetInteger
*
* Return value: value as int
*
* This function reads an integer value input from the keyboard and ensures
* that it is a positive number.
*
* Author: Patrick Nutt
* Last modified: 28 September 2002
*******************************************************************************/
int GetInteger()
{
        int value;
        cin >> value;

        while (!cin || value < 1)
        {
                cout << "\nYou must enter a positive number here. Please try again.\n";
                if (!cin)
                {
                        cin.clear();
                        cin.ignore(50,'\n');
                }
                cin >> value;
        }
        return value;
}
/******************************************************************************/

/*******************************************************************************
* Function name: IsCube()
*
* Parameters: Box testBox /in/ defined by user
*
* This function returns TRUE if all three sides of the test box are equal. It
* returns FALSE otherwise.
*
* Author: Patrick Nutt
* Last modified: 28 September 2002
*******************************************************************************/
bool IsCube(/*in*/ Box testBox)
{
        if (testBox.length == testBox.width && testBox.width == testBox.height)
            return TRUE;        // is a cube
        else
            return FALSE;       // is not a cube
}
/******************************************************************************/




