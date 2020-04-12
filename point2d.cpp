#include "point2d.h"

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

 