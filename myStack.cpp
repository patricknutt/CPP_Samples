#include<iostream>
#include<fstream>
#include"stack.h"
using namespace std;

int main()
{
        Stack myStack;
        ifstream inData;
        char buffChar;
        int charCount;

        myStack.create();
        inData.open("stack.txt");
        charCount = 0;
        if (!inData)
        {
                cout << "File does not exist..\n";
                getchar();
                return 1;
        }

        inData  >> buffChar;

        while(inData)
        {
                if (buffChar == '{')
                {
                        if (myStack.isFull())
                        {
                                cout << "Stack is full...";
                                getchar();
                                return 1;
                        }
                        myStack.push(buffChar);
                        charCount++;
                }

                if (buffChar == '}')
                {
                        if (myStack.isEmpty())
                        {
                                cout << "Too many right braces...";
                                getchar();
                                return 1;
                        }
                        myStack.pop();
                        charCount--;
                }
                inData  >> buffChar;
        }

        if (!myStack.isEmpty())
        {
                cout << "Too many left braces...";
                getchar();
                return 1;
        }
        
        cout << "Count: " << charCount << endl
             << "Braces match...";

        getchar();
        return 0;
}








