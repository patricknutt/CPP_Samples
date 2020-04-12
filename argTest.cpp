#include<iostream>
#include<string>
using namespace std;

int main(int argc, char* argv[])
{
        cout << "TEST...\n";
        
        if (argc == 1)
        {
                cout << "No Argument";
                getchar();
                return 0;
        }
        if (strcmp(argv[1], "-u") == 0)
        {
                cout << "-u argument called";
                getchar();
                return 0;
        }
        if (strcmp(argv[1], "-r") == 0)
        {
                cout << "-r argument called";
                getchar();
                return 0;
        }
        cout << "Incorrect argument.";
        getchar();
        return 0;
}


