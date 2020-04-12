//***********************************************************************************
// NAME: Patrick Nutt
// Program3
// CMIS 102
// DATE: 12 July 2002
// PROGRAM DESCRIPTION: Rainbow Height
// This program accepts a distance input from the user and performs calculations
// based on this value to determine the height of the main rainbow and a
// secondary rainbow.
//***********************************************************************************
#include <iostream>
#include <iomanip>      // For setprecision
#include <cmath>        // For tan function
using namespace std;

const float PI = 3.14159265;
const float DEGREE1 = 42.3333333;      // Main Rainbow
const float DEGREE2 = 52.25;           // Secondary Rainbow

int main ()
{
        float distance;         // Distance to main rainbow to be input by user
        float angle1;           // For DEGREE1 in radians
        float angle2;           // For DEGREE2 in radians
        float rainbow1;         // Main rainbow height
        float rainbow2;         // Secondary rainbow height

        cout << fixed << showpoint      // Format floating-point output
             << setprecision(4);        // to 4 decimal places
        // Initialize distance
        distance = 0.0;
        
        // Input distance from keyboard
        cout << "Please enter the distance to the main rainbow and press return.\n";
        cin  >> distance;

        // Compute height for each rainbow

        // Main rainbow
        angle1 = DEGREE1 * (PI / 180);  // Convert degrees into radians
        rainbow1 = tan(angle1) * distance;         // Compute height

        // Secondary rainbow
        angle2 = DEGREE2 * (PI / 180);  // Convert degrees into radians
        rainbow2 = tan(angle2) * distance;         // Compute height

        // Print results
        cout << "\nWith a distance of " << distance << ", "
             << "the height of the main rainbow is " << rainbow1 << endl
             << "and the height of the secondary rainbow is " << rainbow2 << ".\n";
        return 0;
}

