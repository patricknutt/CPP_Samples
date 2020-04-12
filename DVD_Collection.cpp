/*******************************************************************************
* IMPLEMENTATION FILE (DVD_Collection.cpp)
* This class represents a collection of up to five DVDs
*
* Author: Patrick Nutt -- 23 November 2002
*******************************************************************************/
#include<iostream>
#include<string>
#include"DVD_Collection.h"
using namespace std;

DVD_Collection::DVD_Collection()
        //**********************************************************************
        // Constructor
        // POST: nMovies == 0
        //    && isCreated == false
        //**********************************************************************
{
        nMovies = 0;
        isCreated = false;
}

void DVD_Collection::CreateCollection(/*in*/ int maxNumber)
        //**********************************************************************
        // PRE: 1 <= maxNumber < 5
        // POST: isCreated == true
        //    && Assigned( movie[0..maxNumber] )
        //**********************************************************************
{
        isCreated = true;
        for (int count = 0; count < maxNumber; count++)
        {
                AppendCollection();
        }

}

void DVD_Collection::PrintCollection()
        //**********************************************************************
        // POST: Contents of movie[0..nMovies] has been displayed
        //**********************************************************************
{
        if (!IsEmpty())
        {
                for (int count = 0; count < nMovies; count++)
                {
                        cout << "\nMovie Number " << count + 1 << endl;
                        movie[count].PrintDVD();
                }
        }
        else
        {
                cout << "There are no DVD's in this collection." << endl;
        }
}

void DVD_Collection::AppendCollection()
        //**********************************************************************
        // POST: Assigned( movie[nMovies + 1] )
        //    && nMovies == nMovies + 1
        //**********************************************************************
{
        string name,
               type,
               lang;

        if (!isCreated)
        {
               cout << "You must create a collection before you can add to it.\n";
        }

        else if (!IsFull())
        {
               cout << "Please enter the name of movie number " << nMovies + 1
                     << ": ";
                getline (cin, name);

                cout << "\nWhat catagory, cartoon or film, does movie number "
                     << nMovies + 1 << " belong to?: ";
                getline (cin, type);

                cout << "\nWhat language(s) is movie number " << nMovies + 1
                     << " dubbed in?: ";
                getline (cin, lang);

                movie[nMovies].CreateDVD(name, type, lang);
                nMovies++;
                cout << '\n';
        }
        else
        {
                cout << "Collection is full. Only " << NUMBER_DVD
                     << " are allowed." << endl;
        }
}

void DVD_Collection::RemoveMovie(/*in*/ int mNumber)
        //**********************************************************************
        // PRE: 1 <= mNumber <= nMovies
        // POST: movie[mNumber - 1] has been deleted
        //    && movie[mNumber..nMovies) ] contain same values but have been
        //       shifted down one position
        //    && nMovies == nMovies - 1
        //**********************************************************************
{
      for (int count = 0; count < (nMovies - mNumber); count ++)
               movie[(mNumber - 1) + count] = movie[mNumber + count];
      nMovies--;
}

bool DVD_Collection::IsEmpty()
        //**********************************************************************
        // POST: FCTVAL == TRUE, if nMovies == 0
        //              == FALSE, otherwise
        //**********************************************************************
{
        if (nMovies == 0)
                return true;
        return false;
}

bool DVD_Collection::IsFull()
        //**********************************************************************
        // POST: FCTVAL == TRUE, if nMovies == NUMBER_DVD
        //              == FALSE, otherwise
        //**********************************************************************
{
        if (nMovies == NUMBER_DVD)
                return true;
        return false;
}

bool DVD_Collection::IsOutOfRange(/*in*/ int value)
        //**********************************************************************
        // POST: FCTVAL == TRUE, if nMovies < value < 1
        //              == FALSE, otherwise
        //**********************************************************************
{
        if (value > (nMovies) || value < 1)
                return true;
        else
                return false;
}




