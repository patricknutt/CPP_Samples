#include <iostream>
using namespace std;

class Point2D
{
    public:

        Point2D();           // default constructor - sets x and y to 10,10
        Point2D( int, int);  // 2-arg constructor
        void setX(int);       // used to set the value of x
        void setY(int);       // used to set the value of y
        int getX();           // reports back the value of x
        int getY();           // reports back the value of y
        bool isTheSame( Point2D );     // compares 2 objects of type Point2D

  private:
        int x;
        int y;
};

Point2D::Point2D()
{
   x = 10;
   y = 10;
}

Point2D::Point2D(int x0, int y0)
{
   x = x0;
   y = y0;
}

// This member function is used to assign a value
// to the private field x
void Point2D::setX(int x0)
{
   x = x0;
}

// This member function is used to assign a value
// to the private field y
void Point2D::setY(int y0)
{
   y = y0;
}

// This member function returns the value of the
// private attribute x
int Point2D::getX()
{
  return x;
}

//This member function returns the value of the
// private attribute y
int Point2D::getY()
{
  return y;
}

// Compares 2 objects of type Point2D to see if they
// have the same x and y coordinates or not.
// E.g. assume p1 and p2 are 2 objects of type
//      Point2D
//
//    if( p1.isTheSame( p2 ) )
//
// p2 corresponds in this case to the argument the
// member function receives
bool Point2D::isTheSame(Point2D another)
{
  if (x == another.x && y == another.y)
     return true;
  else
     return false;
}

//****** Client code example **************
int main()
{
   Point2D p1; // default constructor called here
   Point2D p2(10,25); // 2-arg constructor called here

   // the member functions getX and getY are used here
   // to report back to us the value of P1's private x and y
   // attributes
   cout << "Original values of P1: "
        << p1.getX() << ' ' << p1.getY() << endl;


   // setting new values for P1's x and y:
   int x; // user's x input
   int y; // user's y input

   cout << "Enter P1's x and y: ";
   cin >> x >> y;

   //setting the values for P1
   p1.setX(x);
   p1.setY(y);

   // printing the new values
   // the member functions getX and getY are used here
   // to report back to us the value of P1's private x and y
   // attributes
   cout << "New values of P1: "
        << p1.getX() << ' ' << p1.getY() << endl;

   // comparing 2 Point2D Objects

   if (p1.isTheSame(p2))
     cout << "P1 and P2 have the same coordinates." << endl;
   else
     cout << "P1 and P2 have different coordinates" << endl;

   getchar();
   return 0;
}
 