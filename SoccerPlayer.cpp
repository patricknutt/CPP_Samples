/*******************************************************************************
* IMPLEMENTATION FILE (SoccerPlayer.cpp)
* This module provides functions for reading into an array of SoccerPlayer
* data types, sorting the data, printing the data, and averaging the numberGoals
* for each struct in the array
*******************************************************************************/
#include<iostream>
#include<string>
#include<fstream>
#include "SoccerPlayer.h"
using namespace std;

/*******************************************************************************
* Function name: ReadPlayers
*
* Parameters:   SoccerPlayer champ[] /out/ array of SoccerPlayer structs
*               int nPlayers /in/ number of players in from file
*               string fileName /in/ name and/or location of input data file
*
* This function receives an array of SoccerPlayers and fills the array
* with values from a file specified by the calling function.
*
* Author: Patrick Nutt
* Last modified: 10 November 2002
*******************************************************************************/
void ReadPlayers (/*out*/ SoccerPlayer champ[],
                  /*in*/ int nPlayers,
                  /*in*/ string fileName)
        //**********************************************************************
        // PRE: Data file name has been set and contains data in the form of
        //      name, next line, score, and next line
        //    && Assigned(nPlayers)
        // POST: Assigned( champ[0..nPlayers-1] )
        //**********************************************************************
{

        ifstream inData;
        inData.open(fileName.c_str());
       
        
        if (!inData)
        {
                cout << '\"' << fileName << '\"' << " is not a valid file." << endl
                     << "Press return to exit..." << endl;
                getchar();
                exit(1);        // stop program if data file is invalid
        }

        // fill array
        for (int arrayPos = 0; arrayPos < nPlayers; arrayPos++)
        {
                getline(inData, champ[arrayPos].name);
                inData >> champ[arrayPos].numberGoals;
                inData.ignore (100,'\n');
        }

}
/******************************************************************************/

/*******************************************************************************
* Function name: PrintList
*
* Parameters: SoccerPlayer champ[] /in/ array to be printed
*             int nPlayers /in/ number of players in array
*
* This function prints the name and numberGoals of each player to the screen
*
* Author: Patrick Nutt
* Last modified: 10 November 2002
*******************************************************************************/
void PrintList(/*in*/ const SoccerPlayer champ[],
                  /*in*/ int nPlayers)
        //**********************************************************************
        // PRE: Assigned( champ[0..nPlayers-1] )
        // POST: each champ.name and champ.numberGoals in array have been printed
        //       to the screen
        //**********************************************************************
{
        for (int arrayPos = 0; arrayPos < nPlayers; arrayPos++)
        {
                cout << champ[arrayPos].name << " -- "
                     << champ[arrayPos].numberGoals << "\n";
        }
}
/******************************************************************************/

/*******************************************************************************
* Function name: SortList
*
* Parameters:   SoccerPlayer champ[] /inout/ array of SoccerPlayer structs
*               int nPlayers /in/ number of players in the array
*
* This function receives an array of SoccerPlayers and sorts them according to
* the number of goals scored. They are sorted in descending order.
*
* Author: Patrick Nutt
* Last modified: 10 November 2002
*******************************************************************************/
void SortList(/*inout*/ SoccerPlayer champ[],
              /*in*/ int nPlayers)
        //**********************************************************************
        // PRE: Assigned( champ[0..nPlayers-1] )
        //    && Assigned(nPlayers)
        // POST: champ[0..nPlayers -1] values are rearranged in descending
        //       order according to the number of goals of each
        //**********************************************************************
{
        int pass;       // number of passes made through array
        int maxIndex;   // position with highest numberGoals
        int index;      // current position

        for(pass = 0; pass < (nPlayers-1); pass++)
        {
                maxIndex = pass;
 	        for(index = pass+1; index < nPlayers; index++)
                {
                        if(champ[maxIndex].numberGoals < champ[index].numberGoals)
                                maxIndex = index;
                }
                swapPlayers (champ[pass], champ[maxIndex]);
        }



}
/******************************************************************************/

/*******************************************************************************
* Function name: SwapPlayers
*
* Parameters: SoccerPlayer& player1 /inout/ first player to be swapped
*             SoccerPlayer& player2 /inout/ second player to be swapped
*
* This function receives two SoccerPlayers and swaps their values.
*
* Author: Patrick Nutt
* Last modified: 10 November 2002
*******************************************************************************/
void swapPlayers (/*inout*/ SoccerPlayer& player1,
                  /*inout*/ SoccerPlayer& player2)
        //**********************************************************************
        // PRE: Assigned(player1) && Assigned(player2)
        // POST: player1 == player2 at entry
        //     && player2 == player1 at entry
        //**********************************************************************
{
        SoccerPlayer temp;       // to temporarily store values of player1

        temp = player1;
        player1 = player2;
        player2 = temp;
}
/******************************************************************************/

/*******************************************************************************
* Function name: Average
*
* Parameters: SoccerPlayer player[] /in/ array with values to be averaged
*             int nPlayers /in/ number of players to be averaged
*
* Return value: int avgScore
*
* Author: Patrick Nutt
* Last modified: 10 November 2002
*******************************************************************************/
int Average(/*in*/ const SoccerPlayer player[],
            /*in*/ int nPlayers)
        //**********************************************************************
        // PRE: Assigned(nPlayers)                                             
        //    && Assigned( player[0..nPlayers-1] )
        // POST: FCTVAL == (sum of numberGoals) / nPlayers
        //**********************************************************************

{
        int total = 0;
        int avgScore;

        for(int arrayPos = 0; arrayPos < nPlayers; arrayPos++)
        {
                total = total + player[arrayPos].numberGoals;
        }
        avgScore = total / nPlayers;
        return avgScore;
}
/******************************************************************************/
                                /*End of File*/
