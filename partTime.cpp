/* IMPLEMENTATION FILE (partTime.cpp) */

#include <iostream>
#include "partTime.h"
using namespace std;

Part_Time::Part_Time()
{
        rate = 0;
}

void Part_Time::computePay()
{
        if (cat == "nov")
                pay = rate * 10;
        else if (cat == "level 1")
                pay = rate * 20;
        else if (cat == "level 2")
                pay = rate * 30;
}

void Part_Time::setRate(float wage)
{
        rate = wage;
}
/**************************************END*************************************/


