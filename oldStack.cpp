#include <iostream>
#include <fstream>

using namespace std;

typedef char ItemType;
const char MAX = 50;

class Stack
{
    public:
      void create();
      bool isEmpty();
      bool isFull();
      void push(ItemType);
      ItemType pop();

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

void Stack::push(ItemType t)
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
        ifstream f;
        Stack    st;
        char     ch;

	// creating the empty stack
        st.create();

        f.open("stack.txt");
        if(!f)
        {
                cout << "Unable to opne file\n";
                return 1;
        }

	// process the file
        f >> ch;
        while(f)
        {

		// if an opening brace is found, and
 		// there is room in the stack, push it
                if( ch == '{')
                     if(!st.isFull())
                           st.push('{');
                     else
                     {
                            cout << "Stack is full\n";
                            getchar();
                            return 1;
                     }
		// if a } is found, and the stack is not empty,
		// then pop the stack
                else if(ch == '}')
                     if(!st.isEmpty())
                           st.pop();
                     else
                     {
                        cout << "Too many } up to this point\n";
                        getchar();
                        return 1;
                     }

                f >> ch;
        }

        cout << "Balanced number\n";
        getchar();
        return 0;
}



 