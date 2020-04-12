/*******************************************************************************
* University of Maryland -- European Division
* CMIS 140 -- Programming Project 3
*
* Program description: This program defines an array of 5 objects. Each is of
* Point2D type. Each object will contain x and y coordinates. These values will
* be supplied by the user. Each of the 5 objects will be tested to see if they
* fall in a zero to fifty range. If so, their position is printed to the screen.
* The total of the objects that were in range will be displayed.
*
* Author: Patrick Nutt
* Last modified: 9 October 2002
*******************************************************************************/
#include<iostream>
#include<conio>  // for clrscr()
using namespace std;

class Point2D
{
   public:
        Point2D(); // sets x and y to 10, 10
        Point2D(int, int);
        void setX(int);
        void setY(int);
        int getX();
        int getY();
        bool isTheSame(Point2D);
   private:
        int x;
        int y;
};

Point2D::Point2D()
{
        x = 10;
        y = 10;
}

Point2D::Point2D(int xVal, int yVal)
{
        x = xVal;
        y = yVal;
}

void Point2D::setX(int xVal)
{
        x = xVal;
}

void Point2D::setY(int yVal)
{
        y = yVal;
}

int Point2D::getX()
{
        return x;
}

int Point2D::getY()
{
        return y;
}

bool Point2D::isTheSame(Point2D other)
{
        return (x == other.x && y == other.y);
}
/******************************************************************************/

const int ARRAY_SIZE = 5,      // number of elements in array
          LOWER = 0,           // lower range limit
          UPPER = 50;          // upper range limit

int readInteger();
void getPos(Point2D[]);
void printPos(Point2D, int);
void printResults(int);
void printInRange(Point2D, int);
bool isInRange (Point2D);

int main()
{
        int posCounter = 0; // in range counter
        // create object
        Point2D objectList[ARRAY_SIZE];

        // fill array
        getPos(objectList);

        cout << "Press return for final report....";
        getchar();
        clrscr();

        // check range & print message
        for (int loopCount = 0; loopCount < 5; loopCount++)
        {
                if (isInRange(objectList[loopCount]))
                {
                        printInRange (objectList[loopCount], loopCount);
                        posCounter++;
                }
        }
        cout << endl;

        // print results
        printResults(posCounter);

        getchar();
        return 0;
}
/******************************************************************************/

/*******************************************************************************
* Function name: int readInteger
*
* Return Value: intInput as integer
*
* This function reads an input from the keyboard and determines if it is a valid
* integer. If not, the function loops until a valid integer is entered.
*
* Author: Patrick Nutt
* Last modified: 17 September 2002
*******************************************************************************/

int readInteger()
{
        int intInput;   // value to be returned
        cin >> intInput;

        while (!cin)    // test for input stream failure
        {
                cout << "This was not a valid integer.\n"
                     << "Please try again.\n";
                cin.clear();
                cin.ignore(50,'\n');
                cin >> intInput;
        }
        clrscr();
        return intInput;
}
/******************************************************************************/

/*******************************************************************************
* Function name: getPos
*
* Parameter: Point2D position /out/ coordinates to be assigned
*
* This function fills an array of type Point2D with x and y coordinates supplied
* by the user.
*
* Author: Patrick Nutt
* Last modified: 9 October 2002
*******************************************************************************/
void getPos(/*out*/ Point2D position[])
{
        for (int loopCount = 0; loopCount < ARRAY_SIZE; loopCount++)
        {
               int xPos,
                    yPos;

                // get x value
                cout << "Please enter the value of x for coordinate #"
                     << (loopCount + 1) << '\n';
                xPos = readInteger();

                // get y value
                cout << "Please enter the value of y for coordinate #"
                     << (loopCount + 1) << '\n';
                yPos = readInteger();

                // set coordinates
                position[loopCount].setX(xPos);
                position[loopCount].setY(yPos);
        }
}
/******************************************************************************/

/*******************************************************************************
* Function name: printPos
*
* Parameters: Point2D dataSet /in/ object whose values are to be printed
*             int arrayPos /in/ position in array of current object
*
* This function prints the contents of one object in an array. The position of
* the function is passed by value from the calling function.
*
* Author: Patrick Nutt
* Last modified: 9 October 2002
*******************************************************************************/
void printPos(/*in*/ Point2D dataSet,
              /*in*/ int arrayPos)
{
        cout << dataSet.getX() << "," << dataSet.getY();
}
/******************************************************************************/

/*******************************************************************************
* Function name: printResults
*
* Parameter: int count /in/ total of objects in range
*
* This function prints the total number of objects that were in range
*
* Author: Patrick Nutt
* Last modified: 9 October 2002
*******************************************************************************/
void printResults(/*in*/ int count)
{
        if (count == 1)         // determine which message is to be printed
                cout << "There was only 1 position in range." << endl;
        else
                cout << "There were " << count << " positions in range." << endl;
}
/*******************************************************************************
* Function name: printInRange
*
* Parameters: Point2D dataSet /in/ data set to be tested
*             int position /in/ position of current data set
* This function prints a message for a data set that is within a certain range
*
* Author: Patrick Nutt
* Last modified: 9 October 2002
*******************************************************************************/
void printInRange(/*in*/ Point2D dataSet,
                  /*in*/ int position)
{
     cout << "Position " << position + 1
          << " (";
     printPos(dataSet, position);
     cout  << ')' << " is in range\n\n";
}
/******************************************************************************/

/*******************************************************************************
* Function name: isInRange
*
* Paramter: Point2D dataSet /in/ x and y values for Point2D object
*
* Return values: TRUE if x and y are in range
*                FALSE if x and/or y are not in range
*
* This function receives an object of type Point2D and returns TRUE if its x and
* y values are between lower and upper values inclusive.
*
* Author: Patrick Nutt
* Last modified: 9 October 2002
*******************************************************************************/
bool isInRange (/*in*/ Point2D dataSet)
{
        if ((dataSet.getX() >= LOWER && dataSet.getX() <= UPPER) &&
            (dataSet.getY() >= LOWER && dataSet.getY() <= UPPER))
             return TRUE;
        else
             return FALSE;
}
/*******************************************************************************
****************************** END OF PROGRAM **********************************
*******************************************************************************/

 