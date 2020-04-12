/* IMPLEMENTATION FILE (employee.cpp) */

#include <iostream>
#include <string>
#include "employee.h"
using namespace std;

Employee::Employee()
{
        name = "Bob the Builder";
        cat = "level 2";
}

void Employee::setInfo(string newName, string newCat)
{
        name = newName;
        cat = newCat;
        computePay();
}

void Employee::computePay()
{
        if (cat == "nov")
                pay = 50000;
        else if (cat == "level 1")
                pay = 55000;
        else if (cat == "level 2")
                pay = 100000;

}

void Employee::printInfo()
{
        cout << "Name -- " << name << endl
             << "Catagory -- "<< cat << endl
             << "Pay -- " << pay << endl;
}
/**********************************END*****************************************/
 