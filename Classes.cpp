#include<iostream>
#include "point2d.h"
using namespace std;

void GetPos(int&, int&);

int main()
{
        Point2D pos1;
        Point2D pos2;

        int pos1X;
        int pos1Y;
        int pos2X;
        int pos2Y;

        cout << "Please enter the x and y coordinates of the first position seperated by a comma: (ex. 7,5)" << endl;
        GetPos(pos1X, pos1Y);

        cout << "Please enter the x and y coordinates of the second position seperated by a comma: (ex. 7,5)" << endl;
        GetPos(pos2X, pos2Y);

        pos1.setX(pos1X);
        pos1.setY(pos1Y);
        pos2.setX(pos2X);
        pos2.setY(pos2Y);

        cout << "The first position is: (" << pos1.getX() << ','
             << pos1.getY() << ")." << endl
             << "The second position is: (" << pos2.getX() << ','
             << pos2.getY() << ")." << endl;


        if (pos1.isTheSame(pos2))
                cout << "The two positions are equal" << endl;
        else
                cout << "The two positions are not equal" << endl;

        getchar();
        return 0;
}

void GetPos( int& xVal, int& yVal)
{
        char ch;
        cin >> xVal >> ch >> yVal;
}





