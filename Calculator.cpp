//************************************************************************
// Caculator
// Performs calculations for the performance of the 1018B Peak Power Meter
// an input data file called "standar.cal" is needed for the CalDetector() 
// function. The format of the file should be "freq calFactor dB".
// ***********************************************************************
#include<iostream>
#include<cmath>         // For fabs() and pow()
#include<fstream>
#include<iomanip>       // For setprecision() & setw()
#include <conio.h>
using namespace std;

const float K = 1.25;   // Constant value
void CalDetector ();    // Perform calculations for detector calibration
void CalMeter ();       // Perform calculations cal output
void RunMenu ();
float dbConvert(float); // Convert mW to dB
ifstream inData;
ofstream outData;

int main()
{
        char menuSelect;
        float answer;

        cout << fixed << showpoint      // Format floating point output
             << setprecision(7);        // to 7 decimal places

        outData << fixed << showpoint   // Format file floting point output
                << setprecision(7);     // to 7 decimal places

        RunMenu ();
        cin  >> menuSelect;
        while (menuSelect != 'Q' && menuSelect != 'q')
        {
             switch (menuSelect)
             {
                case '1' : CalMeter ();         // Calibrator Out
                           break;
                case '2' : CalDetector ();      // Detector Cal
                           break;
                case '3' : system("edit output.cal");   // Results of Step CalDetector
                           break;
                case '4' : system("edit standard.cal");  // Input for CalDetector
                           return 1;
                default  : cout << "Inproper selection. Try again." << endl;
                           break;
             }
             RunMenu();
             cin  >> menuSelect;
        }

}

//*****************************************************************************************
void RunMenu ()
{
        clrscr();
        cout << "Select from the following menu..." << endl << endl
             << "1.........Meter Calibration." << endl
             << "2.........Detector Calibration." << endl
             << "3.........View Detector output file." << endl
             << "4.........Edit Detector input file." << endl
             << "Q.........Quit Program." << endl;
}

//******************************************************************
float dbConvert(/*in*/ float dB)
{
        return pow(10,(dB / 10));       // Equivalent to inverse log function
}

//******************************************************************************************
void CalMeter ()
{
        float dB;       // Insertion loss
        float vZero;    // V0
        float vOne;     // V1
        float vComp;    // VCOMP
        float pmW;      // Result of equation
        float calFactor;        // Thermistor mount cal factor at 100 MHz

        clrscr();
        // Get Data
        cout << "Enter V0 in mV:" << endl;
        cin  >> vZero;
        clrscr();
        cout << "Enter V1 in mV:" << endl;
        cin  >> vOne;
        clrscr();
        cout << "Enter VCOMP in Volts:" << endl;
        cin  >> vComp;
        clrscr();
        cout << "Enter thermistor mount Calibration Factor at 100 MHz:" << endl;
        cin  >> calFactor;
        clrscr();
        cout << "Enter dB charted value @ 100MHz:" << endl;
        cin  >> dB;
        clrscr();

        // Convert mV to Volts
        vZero = vZero / 1000;
        vOne = vOne / 1000;

        // Compute PmW
        pmW = ((2* vComp)*(vOne - vZero)) + ((vZero * vZero) - (vOne * vOne));
        pmW = pmW * K;
        pmW = pmW / calFactor;
        dB = fabs(dB);          // dB must be positive
        pmW = pmW * dbConvert(dB);

        // Output result
        cout << "With: " << endl << endl
             << "V0    -- " << vZero << endl
             << "V1    -- " << vOne << endl
             << "VCOMP -- " << vComp << endl
             << "CF    -- " << calFactor << endl
             << "dB    -- " << dB << endl << endl
             << "PmW is equal to " << pmW << " mW" << endl << endl
             << "Press any key to continue....." << endl;
        getch();
}

//*****************************************************************
void CalDetector()
{
        float calFactor;        // Standard mount cal factor
        float dB;               // dB insertion loss of connectors
        float sPmW;             // Reciprocal of cal factor
        float tInput;           // TI input
        int freq;               // Frequency

        // Open data files
        inData.open("standard.cal");
        outData.open("output.cal");

        // Test input file
        if(!inData)
        {
                cout << "No data file found." << endl
                     << "You must construct a data file named \"standard.cal\"" << endl
                     << "in the following format: Frequency(MHZ)  Cal Factor  dB loss" << endl
                     << "for each frequency required by detector being calibrated. The" << endl
                     << "file must be in the same directory as this program." << endl << endl
                     << "Press any key to continue...." << endl;
                inData.close ();
                getch();
                return;
        }

        // Send headers to output file
        outData << setw(15) << "Frequency (MHz)"
                << setw(7) << " "
                << setw(15) << "Input @ TI (mW)" << endl;

        // Get data
        inData >> freq >> calFactor >> dB;
        while (inData)
        {

                if (dB > 0)             // Ensure dB is negative
                     dB = dB * (-1);

                sPmW = 1 / calFactor;    // Reciprocate the cal factor
                tInput = sPmW * dbConvert(dB);  // Get mW result

                outData << setw(7) << freq
                        << setw(15) << " "
                        << setw(12) << tInput << endl;
                inData  >> freq >> calFactor >> dB;
        }
        inData.close();
}




