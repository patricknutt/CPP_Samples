#include<iostream>
using namespace std;

int main()
{
        int x[10],
               *p,
            i = 0;

        p = x;

        while (i < 10)
        {
                *p = i;
                i++;
                p++;
        }
        cout << "The first value is " << x[0] << endl;
        cout << "The second value is " << *(p) << endl;
        getchar();
        return 0;
}


 