/*******************************************************************************
* University of Maryland -- European Division
* CMIS 140 -- MidTerm 2 Problem 3
*
* Program Description: This program creates a class object of type TeddyBear. The
* user is then asked to give the object a name and a color.
*
* Author: Patrick Nutt
* Last Modified: 28 September 2002
*******************************************************************************/
#include<iostream>
#include<string>
using namespace std;

class TeddyBear
{
  public:
    TeddyBear();        // sets name to "teddy" and color to "brown"
    TeddyBear(string, string);  // two argument constructor
    void SetName(string);       // assign name
    void SetColor(string);      // asign color
    void WriteInfo();           // print name and color

  private:
    string teddyName;   // object's name
    string teddyColor;  // object's color
};

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

void GetInfo (string&, string&, string);    // receive name nad color from user

int main()
{
        TeddyBear userObject;     // object to be modified
        TeddyBear myObject ("BoBo", "white");     // computer object

        string name;
        string color;
        string object;

        // allow for easy modification of the function
        object = "teddy bear";

        // print initial attributes
        cout << "Default " << object << ":" << endl;
        userObject.WriteInfo();
        cout << "\nMy " << object << ":" << endl;
        myObject.WriteInfo();

        // get name and color from user
        GetInfo(name, color, object);

        // set name and color of object
        userObject.SetName(name);
        userObject.SetColor(color);

        // print results
        cout << "\nYou have set the following attributes for your " << object
             << ":" <<endl;
        userObject.WriteInfo(); // user defined object
        cout << "\nThese are the attributes of my " << object << ":" << endl;
        myObject.WriteInfo();   // computer object

        getchar();
        return 0;
}
/******************************************************************************/

/*******************************************************************************
* Function name: void GetInfo
*
* Parameters: string name  /out/  object name
*             string color /out/  object color
*             string object /in/ type of object working with
*
* This function accepts two strings from the user representing the name and color
* of their object. The type of object is also supplied by the user to increase
* the versatility of the function.
*
* Author: Patrick Nutt
* Last modified: 29 September 2002
*******************************************************************************/
void GetInfo (/*out*/ string& name,
              /*out*/ string& color,
              /*in*/  string object)
{
        cout << "\nEnter the name for your " << object << ":  ";
        getline (cin,name);
        cout << "\nEnter the color of your " << object << ":  ";
        getline (cin,color);

        // delete trailing space
        name = name + '\b';     
        color = color + '\b';
}




 