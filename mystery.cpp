#include<iostream>
using namespace std;

void Mystery(char ch1, char ch2)
{
        if (ch1 != ch2)
        {
                ch1++;
                ch2--;
                Mystery(ch1, ch2);
                cout << ch1 << " -- " << ch2 << endl;
        }
}

int main()
{
        Mystery('A', 'G');
        getchar();
        return 0;
}

 