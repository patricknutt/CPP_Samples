/*******************************************************************************
* University of Maryland - European Division
* CMIS 240 - Programming Project 1
*
* This program creates an array of data structures representing 10 soccer players.
* The array is propagated with data from a text file. These players are sorted
* according to the number of goals they have scored. The list is sorted in
* descending order with the player with the highest score occupying the first
* position of the array. The average score of all the players is also computed.
* A final sorted list of the players is displayed on the screen along with the
* average score.
*
* Author: Patrick Nutt
* Last modified: 13 November 2002
*******************************************************************************/
#include<iostream>
#include<fstream>
#include<string>
#include "SoccerPlayer.h"
using namespace std;

const int TOP_PLAYERS = 10;      // top ten players
const string FILE_NAME = "PlayerList.txt"; // name of file to read from
int main()
{
        SoccerPlayer playerList[TOP_PLAYERS];   // reserve space for array
        int avgTourn;   // average score for tournament

        // read, sort, and average
        ReadPlayers(playerList, TOP_PLAYERS, FILE_NAME);
        SortList(playerList, TOP_PLAYERS);
        avgTourn = Average(playerList, TOP_PLAYERS);

        // print results
        PrintList(playerList, TOP_PLAYERS);
        cout << "\nThe average for the tournament is: " << avgTourn << endl;

        getchar();
        return 0;

}






