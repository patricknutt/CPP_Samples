/*******************************************************************************
* University of Maryland -- European Division
* CMIS 240 -- Programming Project 3
*
* This program is used to test the function of the employee and the part_time
* classes. It demonstrates the use of the set, compute, and print functions of
* each classs.
*
* Last modified: 15 December 2002
*******************************************************************************/
#include<iostream>
#include<string>
#include"employee.h"
#include"partTime.h"
using namespace std;

void computePay(Employee &);
void printPay(Employee &);

int main()
{
        Employee fullEmp;
        Part_Time partEmp;

        fullEmp.setInfo("Jim Smith", "level 2");
        partEmp.setInfo("Bob Jones", "level 2");
        partEmp.setRate(6.58);

        computePay(fullEmp);
        computePay(partEmp);

        printPay(fullEmp);
        printPay(partEmp);

        getchar();
        return 0;
}

void computePay(Employee &worker)
{
        worker.computePay();
}

void printPay(Employee &worker)
{
        worker.printInfo();
}
/***********************************END****************************************/
