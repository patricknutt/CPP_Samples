#include<iostream>
using namespace std;

class DynArray
{
        friend istream& operator>>(istream& inStr, DynArray &);
        friend ostream& operator<<(ostream& outStr, DynArray );

        public:
                DynArray();
                ~DynArray();
                DynArray(const DynArray &a);
                void operator=(const DynArray &another);


        private:
                int *data;
                int length;
                int size;
                void getMoreSpace(int newSize);
};

DynArray::DynArray()
{
        size = 10;
        data = new int[size];
        length = 0;
}

DynArray::~DynArray()
{
        delete data;
}

DynArray::DynArray(const DynArray &a)
{

        size = a.size;
        data = new int[size];
        length = a.length;
        for (int i = 0; i < length; i++)
                data[i] = a.data[i];
}

void DynArray::operator=(const DynArray &another)
{
        size = another.size;
        data = new int[size];
        length = another.length;
        for (int i = 0; i < length; i++)
                data[i] = another.data[i];
}

istream& operator>>(istream& inStr, DynArray& array)
{
        if (array.length == array.size)
        {
                array.getMoreSpace(11);
        }
        inStr >> array.data[array.length];
        array.length++;
        return inStr;
}

ostream& operator<<(ostream& outStr, DynArray array)
{
        for (int i = 0; i < array.length; i++)
                outStr << array.data[i] << ' ';
        outStr << endl;
        return outStr;
}

void DynArray::getMoreSpace(int newSize)
{
        int* temp = new int[newSize];
        for (int i = 0; i < newSize;i++)
                temp[i] = data[i];
        delete data;
        data = temp;
        delete temp;
}


int main()
{
        DynArray firstArray;
        DynArray secondArray;

        for (int i = 0; i < 11; i++)
        {
                cout << i << " -- ";
                cin >> secondArray;
        }
        cout << "First:  " << firstArray;
        cout << "Second: " << secondArray;

        firstArray = secondArray;
        cout << "First:  " << firstArray;
        //cout << "Second: " << secondArray;
        getchar();
        return 0;
}



