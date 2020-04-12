/*******************************************************************************
* IMPLEMNTATION FILE (die.cpp)
* This file implements the Die class representing a 6 sided die.
*
* Author: Patrick Nutt -- 21 November 2002
*******************************************************************************/

#include<iostream>
#include<stdlib> // for rand()
#include"die.h"
using namespace std;

Die::Die()
        //**********************************************************************
        // Constructor
        // POST: faceValue == 1
        //**********************************************************************
{
        faceValue = 1;
}

void Die::RollDie()
        //**********************************************************************
        // PRE: srand() has been called
        // POST: faceValue == next pseudorandom number
        //    && 1 <= faceValue <= 6
        //**********************************************************************
{
        faceValue = rand() % 6+ 1;
}

int Die::GetValue()
        //**********************************************************************
        // PRE: Assigned(faceValue)
        // POST: FCTVAL == faceValue
        //**********************************************************************
{
        return faceValue;
}

Comparison CompareDie(/*in*/ Die firstDie,
                      /*in*/ Die secondDie)
        //**********************************************************************
        // PRE: Assigned(firstDie)
        //   && Assigned(secondDie)
        // POST: FCTVAL == SAME, if firstDie == secondDie
        //              == ONE_HIGHER, if firstDie > secondDie
        //              == TWO_HIGHER, if secondDie < firstDie
        //**********************************************************************
{
        Comparison result;
        if (firstDie.faceValue == secondDie.faceValue)
                result = SAME;

        else if (firstDie.faceValue > secondDie.faceValue)
                result = ONE_HIGHER;

        else
                result = TWO_HIGHER;

        return result;
}










