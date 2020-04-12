/*******************************************************************************
* University of Maryland -- European Division
* CMIS 240 -- Programming Project 2
*
* This program is designed to check a file for the number of opening and closing
* braces. A message displayed telling the user whether the file has a matching
* number of braces, too many left braces, or too many right braces. Also, if
* the stack becomes full, and an opening brace is at the top, an appropriate
* message is displayed.
*
* Author : Cristina Ethington
* Last Revision (Patrick Nutt -- 29 November 2002)
*******************************************************************************/
#include <iostream>
#include <fstream>

using namespace std;

typedef char ItemType;
const char MAX = 50;

class Stack
{
    public:
      void create();
      // POST: stackPointer == -1

      bool isEmpty();
      // PRE: create has been allled
      // POST: FCTVAL == TRUE, if stackPointer == -1
      //              == FALSE, otherwise

      bool isFull();
      // POST: FCTVAL == TRUE, if stackPointer  == MAX
      //              == FALSE, otherwise

      void push(ItemType);
      // PRE: stack is not full
      // POST: ItemType is placed at top of stack
      //    && pointer == pointer + 1

      ItemType pop();
      // PRE: stack is not empty
      // POST: FCTVAL == array[stackPointer]
      //    && pointer == pointer - 1

    private:
       ItemType array[MAX];
       int      stackPointer;
};

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

void Stack::push(/* in */ ItemType t)
{
    array[++stackPointer] = t;
}

ItemType Stack::pop()
{
    return array[stackPointer--];
}


// Client code
int main()
{
        ifstream inData;
        Stack    myStack;
        char     buffChar;

	// create the empty stack
        myStack.create();

        inData.open("stack.txt");
        if(!inData)
        {
                cout << "Unable to open file\n";
                return 1;
        }

	// process the file
        inData >> buffChar;
       
        while(inData)
        {

		// if an opening brace is found, and
 		// there is room in the stack, push it
                if( buffChar == '{')
                {
                     if(myStack.isFull())    /* stack is full and last character is an
                                           opening brace. program termination */
                     {
                            cout << "too many left braces in the input \n";
                            getchar();
                            return 1;
                     }

                     // add character to top of stack
                     myStack.push(buffChar);
                }

		// if a closing brace is found, and the stack is not empty,
		// then pop the stack
                else if(buffChar == '}')
                {
                     if(myStack.isEmpty())   /* closing brace found without matching
                                           opening brace. program termination */
                     {
                        cout << "more right than left braces\n";
                        getchar();
                        return 1;
                     }

                     // remove character from top of stack
                     myStack.pop();
                }
                inData >> buffChar;
                
        }

        // if stack is empty that an equal number of characters were popped and
        // pushed from the top of the stack. If the stack is not empty, then by
        // default, there must be more left braces than right.
        if (myStack.isEmpty())
                cout << "braces match\n";
        else
                cout << "more left than right braces\n";

        getchar();
        return 0;
}


