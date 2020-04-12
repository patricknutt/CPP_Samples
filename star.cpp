#include<iostream>
#include<string>
using namespace std;

class Star
{
        public:
             Star();
             Star(string, char);
             void SetName(string);
             void SetType(char);
             void PrintSpecs();
             string GetName();
             char GetType();

        private:
             string name;
             char specType;
};

Star::Star()
{
        name = "Rigel";
        specType = 'O';
}

Star::Star(string newName, char newType)
{
        name = newName;
        specType = newType;
}

void Star::SetName(string newName)
{
        name = newName;
}

void Star::SetType(char newType)
{
        specType = newType;
}

string Star::GetName()
{
        return name;
}

char Star::GetType()
{
        return specType;
}

void Star::PrintSpecs()
{
        string specs[7] = {{"O     28,000 - 50,000       Ionized Helium"},
                          {"B     10,000 - 28,000       Helium, some Hydrogen"},
                          {"A      7,500 - 10,000       Strong hydrogen, some ionized metals"},
                          {"F      6,000 -  7,500       Hydrogen, ionized calcium, and iron"},
                          {"G      5,000 -  6,000       Neutral and ionized metals, especially calcium"},
                          {"K      3,500 -  5,000       Neutral metals, sodium"},
                          {"M      2,500 -  3,500       Strong titanium oxide, very strong sodium"}};

        cout << "Name: " << name << endl;
        cout << "Specification: ";
        switch (toupper(specType))
        {
                case 'O': cout << specs[0];
                          break;
                case 'B': cout << specs[1];
                          break;
                case 'A': cout << specs[2];
                          break;
                case 'F': cout << specs[3];
                          break;
                case 'G': cout << specs[4];
                          break;
                case 'K': cout << specs[5];
                          break;
                case 'M': cout << specs[6];
                          break;
        }
        cout << endl;
}

class Constellation
{
        public:
             Constellation();
             void InsertStar(Star);
             void PrintStars();
             void SetName(string);
             string GetName();

        private:
             string name;
             Star collection[10];
             int nStars ;
};

Constellation::Constellation()
{
        nStars = 0;
}

void Constellation::InsertStar(Star thisStar)
{
        collection[nStars] = thisStar;
        nStars ++;
}

void Constellation::PrintStars()
{
        for (int i = 0; i < nStars; i++)
        {
                cout << "       Star " << (i+1) << '\n';
                collection[i].PrintSpecs();
                cout << endl;
        }
}
void Constellation::SetName(string newName)
{
        name = newName;
}

string Constellation::GetName()
{
        return name;
}

int main()
{
        Star myStar;
        Constellation myCollection;
        string starName;
        string constellationName;
        char type;
        char op;
        int count = 0;
        cout << "Enter the name of the constellation: " << endl;
                getline (cin,constellationName);
                myCollection.SetName(constellationName);
        while(true)
        {
                cout << "Enter the name of the star " << (count + 1) << ": " << endl;
                getline(cin,starName);
                myStar.SetName(starName);
                cout << "Enter the star's spectral type: (O,B,A,F,G,K,M)";
                cin  >> type;
                myStar.SetType(type);

                myCollection.InsertStar(myStar);
                cout << "Quit? Y/N:" << endl;
                cin  >> op;
                cin.ignore(100,'\n');
                count++;
                if (toupper(op) == 'Y' || count == 10)
                    break;
        }
        cout << "Constellation: " << myCollection.GetName() << endl;
        myCollection.PrintStars();
        getchar();
        return 0;
}


