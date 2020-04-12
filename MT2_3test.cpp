/*******************************************************************************
* University of MAryland -- European Division
* CMIS 140 -- MidTerm 2 Problem 3
*
* Program Description: This program creates and object of type TeddyBear. The
* user is then asked to give the object a name and a color.
*
* Author: Patrick Nutt
* Last Modified: 27 September 2002
*******************************************************************************/
#include<iostream>
#include<string>

using namespace std;

void GetInfo (string&, string&, string);

int main()
{
        TeddyBear userObject;     // bear to be modified
        TeddyBear myObject ("BoBo", "white");     // computer bear

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

        userObject.SetName(name);
        userObject.SetColor(color);

        cout << "\nYou have set the following attributes for your " << object
             << ":" <<endl;
        userObject.WriteInfo();

        cout << "\nThese are the attributes of my " << object << ":" << endl;
        myObject.WriteInfo();

        getchar();
        return 0;
}
/******************************************************************************/

/*******************************************************************************
* Function name: void GetInfo
*
* Parameters: string name  /out/
*             string color /out/
*
* This function accepts two strings from the user representing the name and color
* of their object. The type of object is also supplied by the user to increase
* the versatility of the function.
*
* Author: Patrick Nutt
* Last modified: 27 September 2002
*******************************************************************************/
void GetInfo (/*out*/ string& name,
              /*out*/ string& color,
              /*in*/  string object)
{
        cout << "\nEnter the name for your " << object << ":  ";
        getline (cin,name);
        cout << "\nEnter the color of your " << object << ":  ";
        getline (cin,color);
}




 