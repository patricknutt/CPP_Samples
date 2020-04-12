/*******************************************************************************
* University of Maryland -- European Division
* CMIS 240 -- Mid Term 1 Program 1
*
* This program allows the user to create a collection of up to 5 objects
* representing a DVD movie. Each DVD has three attributes; name, type, and
* language.
*
* Author: Patrick Nutt -- 23 November 2002
*******************************************************************************/
#include<iostream>
#include<conio> // for clrscr();
#include"DVD.h"
#include"DVD_Collection.h"
using namespace std;

void PrintMenu();       // user menu
void RunMenu(DVD_Collection);  // menu subroutine
void Remove(DVD_Collection&);   // subroutine for removing a movie
void Create(DVD_Collection&);   // subroutine for creating a collection

int main()
{
        DVD myVideo;
        DVD_Collection myCollection;

        RunMenu(myCollection);
        return 0;
}
/******************************************************************************/

/*******************************************************************************
* RunMenu
*
* Paramter: DVD_Collection myCollection /in/ DVD collection to be displayed.
*
* This function creates a user menu. The user can select commands from the menu
* to manipulate a DVD collection. The function prompts for a user selection
* after each action is performed.
*
* Author: Patrick Nutt -- 23 November 2002
*******************************************************************************/
void RunMenu(/*in*/ DVD_Collection myCollection)
{

        char choice;
        PrintMenu();

        // prompt user
        cout << "<Menu Choice>: ";
        cin  >> choice;
        cin.ignore (100, '\n');

        while (toupper(choice) != 'Q')
        {
                switch (toupper(choice))
                {
                        case 'C':
                                Create(myCollection);
                                break;
                        case 'A':
                                myCollection.AppendCollection ();
                                break;
                        case 'R':
                                Remove(myCollection);
                                break;
                        case 'P':
                                myCollection.PrintCollection();
                                break;
                        case 'M':
                                PrintMenu();
                                break;
                        default:
                                cout << "Please select from the menu. Enter 'm' "
                                     << "to display menu.\n";
                                break;
                }

                // prompt user
                cout << "<Menu Choice>: ";
                cin >> choice;
                cin.ignore(100,'\n');
        }
}
/******************************************************************************/

/*******************************************************************************
* PrintMenu
*
* This function displays a user menu.
*
* Author: Patrick Nutt -- 23 November 2002
*******************************************************************************/
void PrintMenu()
{
        clrscr();
        cout << "*** Choose One ***********************" << endl
             << "* (C)reate Collection                *" << endl
             << "* (A)dd Movie                        *" << endl
             << "* (R)emove Movie                     *" << endl
             << "* (P)rint Collection                 *" << endl
             << "* (M)enu                             *" << endl
             << "* (Q)uit                             *" << endl
             << "**************************************" << endl;
}
/******************************************************************************/

/*******************************************************************************
* Remove
*
* Paramter: DVD_Collection myCollection /inout/ collection that contains movie
*           to be removed
*
* This function prompts the user for the movie number to delete. It then calls
* the DVD_Collection member function RemoveMovie() to remove the movie
*
* Author: Patrick Nutt -- 23 November 2002
*******************************************************************************/
void Remove(/*inout*/ DVD_Collection& myCollection)
{
        int mNumber;
        if (!myCollection.IsEmpty ())
        {
                cout << "Which movie would you like to remove?\n";
                        cin  >> mNumber;
                        cin.ignore(100,'\n');

                        while (myCollection.IsOutOfRange(mNumber))
                        {
                                cout << "This value is not a valid entry. "
                                     << "You can only choose a movie\n"
                                     << "from this collection.\n";
                                cin  >> mNumber;
                                cin.ignore(100, '\n');
                        }
                // call class member function to remove DVD
                myCollection.RemoveMovie(mNumber);
        }
        else
        {
                cout << "There are no DVD's in this collection." << endl;
        }
}
/******************************************************************************/

/*******************************************************************************
* Create
*
* Parameter: DVD_COllection newCollection /out/ collection to be created
*
* This function prompts the user for the number of DVDs are to be input then
* calls the DVD_Collection class member function CreateCollection to create a
* collection with that number of DVDs
*
* Author: Patrick Nutt -- 23 November 2002
*******************************************************************************/
void Create(/*out*/ DVD_Collection& newCollection)
{
        int totNumber;

        if (!newCollection.IsEmpty())
                cout << "Sorry, only one collection can be created at a time.\n";
        else
        {
                do
                {
                cout << "How many movies would you like to add to this collection?\n"
                     << "Up to 5 movies are allowed. ";
                cin  >> totNumber;
                cin.ignore(100, '\n');
                }while(totNumber > 5 || totNumber < 1);

                // call class member function to create a collection
                newCollection.CreateCollection(totNumber);
        }
}
/*********************************End of File**********************************/
