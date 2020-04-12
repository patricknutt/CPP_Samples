/*******************************************************************************
* University of Maryland - European Division
* CMIS 140 - Mid-Term 1 Problem 2
*
* Program Description: This program accepts the input of two values. The first
* is the amount of gas in gallons and the second is the price per liter of that
* gas in dollars. The program then computes the total price of the gas.
*
* Author Patrick Nutt (Final version 17 September 2002)
*******************************************************************************/
#include<iostream>
#include<iomanip>       // for setprecision()
#include<conio>         // for clrscr()
using namespace std;

float GetValue(); // prompts user for value and returns result
float ConvertGallons (float); //converts gallons to liters
float ComputePrice (float, float); // computes final price

int main()
{
        float gallons;  // input amount from user
        float liters;   // from function ConvertGallons()
        float price;    // price of 1 liter of gas
        float cost;     // final cost

        cout << fixed << setprecision(2);

        // prompt user for gallons and price
        cout << "Please enter the amount of gas in gallons.\n";
        gallons = GetValue();
        cout << "Please enter the price of one liter of gas in dollars.\n";
        price = GetValue();

        // convert gallons to liters
        liters = ConvertGallons(gallons);

        // compute final cost
        cost = ComputePrice(liters, price);

        // print results
        clrscr();
        cout << "The price of " << liters << " liters of gas"
             << " (" << gallons << " gallons)\n"
             << "at $" << price << " per liter is: $" << cost << endl << endl
             << "Press any key to exit....";
        getch();
        return 0;
}
/******************************************************************************/

/*******************************************************************************
* Function name: float ConvertGallons
*
* Parameter: float gallons /in/ amount of gas in gallons input from user
* Return value: liters as float
*
* This function simply returns the liter equivalent of a given gallon amount
*
* Author: Patrick Nutt
* Last modified: 15 September 2002
*******************************************************************************/
float ConvertGallons(/*in*/ float gallons)
{
        float liters;
        liters = gallons * 3.785;
        return liters;
}
/******************************************************************************/

/*******************************************************************************
* Function name: float ComputePrice
*
* Parameters: float liters /in/ total liters of gas
*             float price  /in/ price per liter of gas
* Return value: cost as float
*
* This function computes the cost of the amount of gas, in liters, supplied by
* the calling function.
*
* Author: Patrick Nutt
* Last modified: 15 September 2002
*******************************************************************************/
float ComputePrice(/*in*/ float liters,
                   /*in*/ float price)
{
        float cost;
        cost = liters * price;
        return cost;
}
/******************************************************************************/

/*******************************************************************************
* Function name: float GetValue
*
* Return value: value as float
*
* This function reads a floating point value input from the keyboard and ensures
* that it is a positive number.
*
* Author: Patrick Nutt
* Last modified: 15 September 2002
*******************************************************************************/
float GetValue()
{
        float value;
        cin >> value;

        while (!cin || value < 0)
        {
                cout << "You must enter a positive number here. Please try again.\n";
                if (!cin)
                {
                        cin.clear();
                        cin.ignore(50,'\n');
                }
                cin >> value;
        }
        return value;
}
/******************************************************************************/





