/* zybooks tests.cpp
Name: Samantha Sax
NetID: srs190010
Date Due 11/10/19

This program will use modullar programming to read in a time value, and compute the distance an object can travel in that time on Earth
and on the moon. These values will be returned to the main function, and another function will be called to display the results.
While the time entered is negative, the program will prompt for a valid input, and while the input is not zero, the program will run
repeatedly until a zero is entered.
*/

#include <iostream>
#include <iomanip>

using namespace std;

//function definitions
double readSeconds() {//this function will be called to read in and return a time value in seconds to the main function.
	double timeSeconds;
	cout << "Enter the time (in seconds)\n";
	cin >> timeSeconds;

	if (timeSeconds < 0) {//if the function is negative, display an error message, but return the value to main regardless.
		cout << "The time must be zero or more\n";

	}
	return timeSeconds;

}

double calculateEarthDistance(double timeSeconds) {//calculate the distance traveled on the earth and return that distance to main

	const double gravityE = 9.8;
	double eDistance = 0.5 * gravityE * (timeSeconds * timeSeconds);

	return eDistance;
}

double calculateMoonDistance(double timeSeconds) {//calcuate the distance traveled on the moon and return that distance to main


	const double gravityM = 1.6;
	double mDistance = 0.5 * gravityM * (timeSeconds * timeSeconds);

	return mDistance;
}
void displayResults(double timeSeconds, double eDistance, double mDistance) {//cout the formatted results to the console

	cout << "The object traveled " << setprecision(4) << fixed << eDistance << " meters in " << setprecision(2) << fixed << timeSeconds << " seconds on Earth\n";
	cout << "The object traveled " << setprecision(4) << fixed << mDistance << " meters in " << setprecision(2) << fixed << timeSeconds << " seconds on the Moon\n";
}

//end of function definitions
//program body
int main() {

	double timeSeconds = readSeconds(); //call and assign return value to timeSeconds

	while (timeSeconds != 0) {//loop while the time is not zero

		if (timeSeconds < 0) {//if time is negative, re-prompt by calling the function again
			timeSeconds = readSeconds();
		}

		if (timeSeconds > 0) {//if input is valid, calculate and display the results by calling the appropriate functions
			double eDistance = calculateEarthDistance(timeSeconds);
			double mDistance = calculateMoonDistance(timeSeconds);
			displayResults(timeSeconds, eDistance, mDistance);
			timeSeconds = readSeconds();//re-prompt the user to enter another time value to loop again. 
		}
	}
}