/*******************************************************************************
* DRIVER (currencyTest.cpp)
*******************************************************************************/
#include <iostream>
#include "currency.h"
using namespace std;

// outputs two dollar values to the screen
void printCurrency(const Currency &, const Currency &);

int main()
{
        Currency fCurrency,
                 sCurrency,
                 totCurrency;
        // displays values from class Constructors
        printCurrency(fCurrency, sCurrency);

        // sets fCurrency == $5.99
        fCurrency.setDollars(5);
        fCurrency.setCents(99);

        // sets sCurrency == $10.15
        sCurrency.setDollars(10);
        sCurrency.setCents(15);

        // test getDollars() and getCents()
        cout << "\n-- TEST of getDollars() nad getCents() functions -- \n"
             << "1st -- $" << fCurrency.getDollars()
             << '.' << fCurrency.getCents() << endl
             << "2nd -- $" << sCurrency.getDollars()
             << '.' << sCurrency.getCents() << endl;

        cout << '\n';

        // outputs new dollar amounts
        printCurrency(fCurrency, sCurrency);

        // sums dollar amounts
        // operator+ is overloaded to work with the Currency class
        totCurrency = fCurrency + sCurrency;

        cout << "\nTotal: " << totCurrency;

        getchar();
        return 0;
}

void printCurrency(const Currency &first, const Currency &second)
{
        cout << "1st -- " << first << endl;
        cout << "2nd -- " << second << endl;
}
/******************************END OF DRIVER***********************************/
