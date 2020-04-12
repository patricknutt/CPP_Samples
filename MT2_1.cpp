/*******************************************************************************
* University of Maryland -- European Division
* CMIS 140 MidTerm 2 Problem 1
*
* Program Description: This program prompts the user for a color four times.
* The program then determines which of three colors is the most common. The
* choices are blue, yellow, and red. The most common color is printed to the
* screen with the number of times it was chosen.
*
* Author: Patrick Nutt
* Last modified: 2 October 2002
*******************************************************************************/
#include<iostream>
#include<string>
#include<cctype>        // for toupper()
using namespace std;

enum Color {BLUE, YELLOW, RED};

void ReadColor(Color&);                   // input color choice
void PrintColor(Color);                   // print color
void CountColor(Color, int&, int&, int&); // count color frequency
Color DetMostCommon(int, int, int);       // determine the most common color
Color ConvertColor(char);                 // convert color into string

int main()
{
        Color first,    // first choice
              second,   // second choice
              third,    // third choice
              fourth,   // fourth choice
              common;   // most common color

        // frequency counters
        int countBlue = 0,
            countYellow = 0,
            countRed = 0;

        // process first color
        ReadColor(first);
        CountColor(first, countBlue, countYellow, countRed);

        // process second color
        ReadColor(second);
        CountColor(second, countBlue, countYellow, countRed);

        // process third color
        ReadColor(third);
        CountColor(third, countBlue, countYellow, countRed);

        // process fourth color
        ReadColor(fourth);
        CountColor(fourth, countBlue, countYellow, countRed);

        // determine the most common color
        common = DetMostCommon(countBlue, countYellow, countRed);

        // print results
        cout << "Results:\n\n" << "Blue -- " << countBlue << endl
             << "Yellow -- " << countYellow << endl
             << "Red -- " << countRed << endl << endl
             << "The most common color is ";
        PrintColor (common);
        cout << "." << endl;

        getchar();
        return 0;
}
/******************************************************************************/

/*******************************************************************************
* Function name: void ReadColor
*
* Parmeters: Color name /out/ color chosen by user
*
* This function reads a string from the user and converts it into the
* corresponding value of type Color.
*
* Author: Patrick Nutt
* Last modified: 29 September 2002
*******************************************************************************/
void ReadColor(/*out*/ Color& name)
{
        string strColor;        // color read in from user
        char fLetter;           // first letter of string


        cout << "What is your favorite color: blue, yellow, or red?" << endl;
        cin  >> strColor;

        fLetter = toupper(strColor[0]);

        // make sure user enters only blue, yellow, or red
        while (fLetter != 'B' &&
               fLetter != 'Y' &&
               fLetter != 'R')
        {
                cout << "Please choose only blue, yellow, or red" << endl;
                cin  >> strColor;
                fLetter = toupper(strColor[0]);
        }

        // assign a Color to name
        name = ConvertColor(fLetter);

}
/******************************************************************************/

/*******************************************************************************
* Function name: Color ConvertColor
*
* Parameters: char letter /in/  first letter color to be converted from string
*             to Color type
*
* Return value: BLUE, YELLOW, or RED
*
* This function recieves a char and returns the corresponding enumerator of
* Color type.
*
* Author: Patrick Nutt
* Last modified: 29 September 2002
*******************************************************************************/
Color ConvertColor(/*in*/ char letter)
{

        if (letter == 'B')
           return BLUE;
        else if (letter == 'Y')
           return YELLOW;
        else 
           return RED;
}
/******************************************************************************/

/*******************************************************************************
* Function name: void PrintColor
*
* Parameter: Color name /in/ color to be printed
*
* This function receives BLUE, YELLOW, or RED and prints the string equivalent.
*
* Author: Patrick Nutt
* Last modified: 28 September 2002
*******************************************************************************/
void PrintColor(/*in*/ Color name)
{
        switch (name)
        {
                case BLUE:
                        cout << "Blue";
                        break;
                case YELLOW:
                        cout << "Yellow";
                        break;
                case RED:
                        cout << "Red";
                        break;
        }
}
/******************************************************************************/

/*******************************************************************************
* Function void CountColor
*
* Parameters: Color name /in/ color to be checked
*             int countBlue /inout/ total number of BLUEs
*             int countYellow /inout/ total number of YELLOWs
*             int countRed /inout/ total number of REDs
*
* This function receives a Color and increments the counter for that color.
*
* Author: Patrick Nutt
* Last modified: 28 September 2002
*******************************************************************************/
void CountColor(/*in*/ Color name,
                /*inout*/ int& countBlue,
                /*inout*/ int& countYellow,
                /*inout*/ int& countRed)
{
        if (name == BLUE)
            countBlue ++;
        else if (name == YELLOW)
            countYellow ++;
        else if (name == RED)
            countRed ++;
}
/******************************************************************************/

/*******************************************************************************
* Function name: Color DetMostCommon
*
* Parameters: int countBlue /in/ total number of BLUEs
*             int countYellow /in/ total number of YELLOWs
*             int countRED /in/ total number of REDs
*
* Return value: BLUE, YELLOW, or RED
*
* This function receives three totals and determines which is the greatest and
* returns the corresponding Color value. If there is a tie between blue and yellow
* or between blue and red, then blue is the default. If the tie is between yellow
* red, yellow is the default.
*
* Author: Patrick Nutt
* Last modified: 2 October 2002
*******************************************************************************/
Color DetMostCommon(/*in*/ int countBlue,
                    /*in*/ int countYellow,
                    /*in*/ int countRed)
{
        if ((countBlue > countYellow && countBlue > countRed)
            ||(countBlue == countYellow || countBlue == countRed))// blue is default if a tie
                return BLUE;
        // countBlue can't be largest. Yellow is default if tie with Red
        else if ((countYellow > countRed)||(countYellow == countRed)) 
                return YELLOW;
        // countRed must be the largest
        else   
                return RED;

}
/******************************************************************************/


