/*******************************************************************************
* IMPLEMENTATION FILE (currency.cpp)
*******************************************************************************/
#include<iostream>
#include"currency.h"
using namespace std;

ostream &operator <<(ostream &ostr, const Currency &c)
{
        ostr << "$" << c.dollars << '.';
        if (c.cents < 10)
        {
                cout <<'0';
        }
        cout << c.cents;
        return ostr;
}

Currency::Currency()
{
        dollars = 0;
        cents = 0;
}

Currency::~Currency()
{
        cout << "Destroying object..." << endl;
}

void Currency::setDollars(int d)
{
        dollars = d;
}

int Currency::getDollars() const
{
        return dollars;
}

void Currency::setCents(int c)
{
        cents = c;
}

int Currency::getCents() const
{
        return cents;
}

Currency Currency::operator+ (const Currency &secCurrency) const
{
        Currency newCurrency;

        newCurrency.dollars = dollars + secCurrency.dollars;
        newCurrency.cents = cents + secCurrency.cents;

        while (newCurrency.cents > 99)
        {
               newCurrency.dollars++;
               newCurrency.cents = newCurrency.cents - 100;
        }
        
        return newCurrency;
}
/****************************END OF IMPLEMENTATION*****************************/

