#include<iostream>
#include<string>
using namespace std;

class AtomicElement
{
        public:
             AtomicElement();
             void SetName(string);
             void SetSymbol(char);
             void SetNumber(int);
             char GetSymbol();
             void PrintElement();

        private:
             string name;
             char symbol;
             int atomicNumber;
};

AtomicElement::AtomicElement()
{
        name = "Carbon";
        symbol = 'C';
        atomicNumber = 6;
}

char AtomicElement::GetSymbol()
{
        return symbol;
}

void AtomicElement::SetName (string newName)
{
        name = newName;
}

void AtomicElement::SetSymbol(char newSymb)
{
        symbol = newSymb;
}

void AtomicElement::SetNumber(int newNumber)
{
        atomicNumber = newNumber;
}

void AtomicElement::PrintElement()
{
        cout << "Name: " << name << endl
             << "Symbol: " << symbol << endl
             << "Number: " << atomicNumber << endl;

}

struct ChemicalCompound
{
        AtomicElement component[3];
        int nElements[3];
        int nDiffElements;
};
void InsertElement(AtomicElement , ChemicalCompound );
int main()
{

        AtomicElement myElement;
        ChemicalCompound myCompound;
        string elemName;
        char elemSymb;
        int elemNumber;
        char op;
        myCompound.nDiffElements = 0;
        while (true)
        {

        cout << "Name: \n";
        cin  >> elemName;
        myElement.SetName(elemName);

        cout << "Symbol: \n";
        cin  >> elemSymb;
        myElement.SetSymbol(elemSymb);

        cout << "Number: \n";
        cin  >> elemNumber;
        myElement.SetNumber(elemNumber);

        myElement.PrintElement();

        cout << "How many of this element? ";
        cin  >> myCompound.nElements[myCompound.nDiffElements];

        InsertElement(myElement, myCompound);
        cout << "Continue? Y/N: ";
        cin  >> op;
        if (toupper(op) == 'N' || myCompound.nDiffElements == 3)
             break;
        }
        for (int i = 0; i < myCompound.nDiffElements; i++)
        {
                cout << myCompound.component[i].GetSymbol() << myCompound.nElements [i];
        }
        cout << endl << myCompound.nDiffElements;
        getchar();
        return 0;
        
}

//void InsertElement(AtomicElement newElement, ChemicalCompound thisComp)
//{
//        thisComp.component[thisComp.nDiffElements] = newElement;
//        thisComp.nDiffElements++;
//}


