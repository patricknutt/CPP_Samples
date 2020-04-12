/* stack.cpp */

#include <iostream>
#include "stack.h"
using namespace std;

// Implementation of member functions
void Stack::create()
{
    stackPointer = -1;
}

bool Stack::isEmpty()
{
    if (stackPointer == -1)
       return true;
    return false;
}


bool Stack::isFull()
{
        if(stackPointer == MAX)
           return true;
        return false;
}

void Stack::push(ItemType t)
{
    array[++stackPointer] = t;
}

ItemType Stack::pop()
{
    return array[stackPointer--];
}
 