#include"teddybear.h"

TeddyBear::TeddyBear()
{
        teddyName = "teddy";
        teddyColor = "brown";
}

TeddyBear::TeddyBear(string name, string color)
{
        teddyName = name;
        teddyColor = color;
}

void TeddyBear::SetName (string name)
{
        teddyName = name;
}

void TeddyBear::SetColor (string color)
{
        teddyColor = color;
}

void TeddyBear::WriteInfo()
{
        cout << "Name = " << teddyName << " and color = " << teddyColor << endl;
}
