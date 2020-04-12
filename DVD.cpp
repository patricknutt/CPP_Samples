/*******************************************************************************
* IMPLEMENTATION FILE (DVD.cpp)
* This class represents one DVD
*
* Author: Patrick Nutt -- 23 November 2002
*******************************************************************************/
#include<iostream>
#include<string>
#include"DVD.h"
using namespace std;

DVD::DVD()
        //**********************************************************************
        // Constructor
        // POST: Assigned(name)
        //    && Assigned(type)
        //    && Assigned(lang)
        //**********************************************************************
{
        name = "Beauty and the Beast";
        type = "cartoon";
        lang = "English and German";

}

DVD::DVD(/*in*/ string newName,
         /*in*/ string newType,
         /*in*/ string newLang)
        //**********************************************************************
        // Constructor
        // PRE: Assigned(newName)
        //   && Assigned(newType)
        //   && Assigned(newLang)
        // POST: name == newName
        //    && type == newType
        //    && lang == newLang
        //**********************************************************************
{
        name = newName;
        type = newType;
        lang = newLang;
}

void DVD::CreateDVD(/*in*/ string newName,
                    /*in*/ string newType,
                    /*in*/ string newLang)
        //**********************************************************************
        // PRE: Assigned(newName)
        //   && Assigned(newType)
        //   && Assigned(newLang)
        // POST: name == newName
        //    && type == newType
        //    && lang == newLang
        //**********************************************************************
{
        name = newName;
        type = newType;
        lang = newLang;
}

void DVD::PrintDVD ()
        //**********************************************************************
        // PRE: Assigned(name)
        //    && Assigned(type)
        //    && Assigned(lang)
        // POST: name, type, and lang have been displayed
        //**********************************************************************
{
        cout << "Name: " << name << endl;
        cout << "Type: " << type << endl;
        cout << "Language: " << lang << endl;
}

string DVD::GetName()
        //**********************************************************************
        // PRE: Assigned(name)
        // POST: FCTVAL == name
        //**********************************************************************
{
        return name;
}

string DVD::GetType()
        //**********************************************************************
        // PRE: Assigned(type)
        // POST: FCTVAL == type
        //**********************************************************************
{
        return type;
}

string DVD::GetLang()
        //**********************************************************************
        // PRE: Assigned(lang)
        // POST: FCTVAL == lang
        //**********************************************************************
{
        return lang;
}

