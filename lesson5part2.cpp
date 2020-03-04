// lesson5part2.cpp 

/*Name: Samantha Sax
NetID: srs190010
Date Due: October 13th, 2019

This program will calculate the distance sound will travel through a chosen medium. It will do this by first displaying a menu
of mediums for the user to choose from, validating the input, and if the input is valid, reading in the seconds that sound traveled
through that medium. Using rates of sound travel speed in meters/second through each medium, the program will calculate the total
distanced traveled in that time. Time must be between 0.0000 and 30.0000 seconds.*/


#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	//define constants to be used in later calculations
	const double A_MPS = 331.5;//meters/second through air
	const double CD_MPS = 258.0;//meters/second through carbon dioxide
	const double HE_MPS = 972.0;//meters/second through helium
	const double HY_MPS = 1270.0;//meters/second through hydrogen

	unsigned int menuChoice = 0;
	double seconds = 0;

	//output menu to the console
	cout << "Select the medium that sound is traveling through:" << endl;
	cout << "1 Carbon Dioxide\n" << "2 Air" << "\n3 Helium" << "\n4 Hydrogen\n";
	cin >> menuChoice;

	//conditional statements to make sure the menu input is valid
	if (menuChoice <= 0 || menuChoice >= 5) {
		cout << "The menu value is invalid. Please run the program again." << endl;
	}

	//if the menu input is valid, get time input in seconds
	else {
		cout << "Enter time (in seconds)\n";
		cin >> seconds;

		//make sure the input is within the valid range
		if (seconds < 0 || seconds > 30) {
			cout << "The time must be between 0.000 and 30.000 (inclusive)\n";
		}

		//if it is within the range, determine what calculations to make based on what menu input was read in
		else {
			if (menuChoice == 1) {
				double cdDistance = seconds * CD_MPS;//Carbon Dioxide distance traveled
				cout << "Carbon Dioxide: " << setprecision(3) << fixed << seconds << " seconds\n";
				cout << "Traveled " << setprecision(4) << fixed << cdDistance << " meters\n";
			}

			else if (menuChoice == 2) {
				double aDistance = seconds * A_MPS;//air distance traveled
				cout << "Air: " << setprecision(3) << fixed << seconds << " seconds\n";
				cout << "Traveled " << setprecision(4) << fixed << aDistance << " meters\n";
			}
			else if (menuChoice == 3) {
				double heDistance = seconds * HE_MPS;//Helium distance traveled
				cout << "Helium: " << setprecision(3) << fixed << seconds << " seconds\n";
				cout << "Traveled " << setprecision(4) << fixed << heDistance << " meters\n";
			}
			else if (menuChoice == 4) {
				double hyDistance = seconds * HY_MPS;//Hydrogen distance traveled
				cout << "Hydrogen: " << setprecision(3) << fixed << seconds << " seconds\n";
				cout << "Traveled " << setprecision(4) << fixed << hyDistance << " meters\n";
			}
		}
	}

}