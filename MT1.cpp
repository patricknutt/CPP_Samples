#include<iostream>
using namespace std;

int main()
{
        int x = 13;

        cout << "The value of x is: " << x << endl;
        {
                int x =58;
                cout << "The value of x here is = " << x << endl;
        }
        cout << "The value of x is still " << x
             << " in the outer block." << endl;
        getchar();
        return 0;
}

 