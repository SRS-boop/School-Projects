/*lesson4part1.cpp
Name: Samantha Sax
NetID: srs190010
Date Due: 10/6/19

This program will calculate the weight in Newtons of an object on Earth, the Moon, and Venus, 
based on it's mass. The Mass will be read in from the console in kilograms, and only positive,
nonzero masses will be converted. Results will be displayed to the console with four decimal
places displayed in fixed point notation. Object exceeding 1500 Newtons based on Earth's gravity
will be specified as "heavy," and objects weighing less than 5 Newtons will be "light."*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {


	cout << setprecision(4) << fixed;

	//get input for object weight in KG
	double massKG;
	cout << "Enter the mass in kg" << endl;
	cin >> massKG;

	//conversion from kilograms to Newtons
	const double eGravity = 9.81;//acceleration due to gravity on Earth
	const double mGravity = 1.62;//acceleration due to gravity on the Moon
	const double vGravity = 8.87;//acceleration due to gravity on Venus
	double eNewtonWeight = massKG * eGravity;//weight in Newtons on Earth
	double mNewtonWeight = massKG * mGravity;//weight in Newtons on the moon
	double vNewtonWeight = massKG * vGravity;//weight in Newtons on Venus



	if (massKG <= 0) {

		cout << "The mass is " << massKG << " kg" << endl;
		cout << "The mass must be greater than zero" << endl;
	}

	else if (massKG > 0) {
		cout << "The mass is " << massKG << " kg" << endl;
		cout << setw(8) << left << "Location" << setw(14) << right << "Weight (N)" << endl;
		cout << setw(8) << left << "Earth" << setw(14) << right << eNewtonWeight << endl;
		cout << setw(8) << left << "Moon" << setw(14) << right << mNewtonWeight << endl;
		cout << setw(8) << left << "Venus" << setw(14) << right << vNewtonWeight << endl;

		if (eNewtonWeight >= 1500) {
			cout << "The object is heavy" << endl;;
		}
		else if (eNewtonWeight < 5) {
			cout << "The object is light" << endl;
		}
	}

}