/*************************************************************************
* University of Maryland - European Division
* CMIS 140 - Programming Project 1
*
* Program Description:
* The purpose of this program is to compute the average of three test scores.
* The grades are listed with a student name in a file provided by the user.
* The average is then used determine which grade a student will receive.
* The number of students and each letter grade will be counted. The percentage
* of the total for each grade will be determined from these numbers. A print out
* of each student's name, average, and letter grade will be output to the screen.
* Also, a report of the totals of each letter and its corresponding percentage of
* the total as well as the total number of students will be displayed.
* Authors:
*	Prof. L.A. (initial version -- 26 August 02)
* 
* 	Patrick Nutt (final version -- 30 August 02)
*************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>      // for setprecision()
#include <conio>        // for getch()
using namespace std;

int main()
{
        ifstream inFile;	// input file
	string stName;		// student name

	float grade1, 		// mid term 1 grade
	      grade2,		// mid term 2 grade
	      grade3;		// final exam grade
        float aveGrade;         // average grade for each student
        float percA,            // percent of A's
              percB,            // percent of B's
              percC,            // percent of C's
              percF;            // percent of F's

        // counters
	int studentCount = 0;   // count of students from file
        int countA = 0,         // total A's
            countB = 0,         // total B's
            countC = 0,         // total C's
            countF = 0;         // total F's

        char letterGrade;       // equivalent letter grade


	inFile.open ("grades.txt");

	if (!inFile)
	{
		cout << "The file 'grades.txt' could not be found. Please correct "
                     << "and try again.\n"
		     << "Press any key to exit.\n";
		getch();
		return 1;
	}

	cout << setprecision(2)<< fixed;
        cout << "Student Name\tAverage\tGrade\n\n";

        while (inFile)
	{
                getline(inFile, stName, '-');
		inFile >> grade1 >> grade2 >> grade3;
                

                // if end of file reached, exit loop
                if(!inFile)
                        break;

                studentCount++;
		// compute average
		// print student info
                aveGrade = (grade1 + grade2 + grade3) / 3;
                cout << stName << "\t" << aveGrade;

		// identify letter grade based on average and print
		// it for the current student
               	if(aveGrade <=10.0 && aveGrade >= 9.0)
		{
                        letterGrade = 'A';
                        countA ++;
		}
		else if(aveGrade >= 8.0)
		{
                        letterGrade = 'B';
                        countB++;
		}
		else if(aveGrade >= 7.0)
		{
                        letterGrade = 'C';
                        countC++;
		}
		else
		{
                        letterGrade = 'F';
                        countF++;
		}

                // output letter grade
                cout << "\t" << letterGrade << endl;
	}
        // print report
        cout << "\n\n\t\t\tReport\n\n";
	cout << "-----------------------------------------------\n\n";

	// print the totals for each grade and
	// corresponding percentage
        percA = (float(countA) / float(studentCount)) * 100;
        percB = (float(countB) / float(studentCount)) * 100;
        percC = (float(countC) / float(studentCount)) * 100;
        percF = (float(countF) / float(studentCount)) * 100;

        cout << "\tNumber of Grades\tPercentages\n"
             << "Grade A:\t" << countA << "\t=\t" << setw(8) << percA << "%\n"
             << "Grade B:\t" << countB << "\t=\t" << setw(8) << percB << "%\n"
             << "Grade C:\t" << countC << "\t=\t" << setw(8) << percC << "%\n"
             << "Grade F:\t" << countF << "\t=\t" << setw(8) << percF << "%\n\n";

	cout << "-----------------------------------------------\n\n";
	cout << "Total grades: " << studentCount << endl;

	cout << "Press any key to exit\n";
	getch();
	return 0;
}


