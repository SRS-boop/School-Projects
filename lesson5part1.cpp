// lesson5part1.cpp
/*
Name: Samantha Sax

Date Due:10/13/19

This program will read in an input value corresponding to a menu of 3 media,then read in a distance in feet that sound has travelled
through that medium. The time (in seconds) that it took for sound to travel that distance through that medium is then calculated, and
displayed on the console to a precision of 4 decimal places.*/


#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	unsigned int medium;
	double distance;//the distance that sound traveled through the medium

	//get input for the medium using a menu of 3
	cout << "Select the medium that sound is traveling through:" << endl;
	cout << "1 Air" << endl << "2 Water" << endl << "3 Steel" << endl;
	cin >> medium;


	cout << setprecision(4) << fixed;//format outputs to 4 decimal places

	switch (medium) {
		
	case 1: //user choses Air as the medium
			cout << "Enter distance (in feet)" << endl;
			cin >> distance;
				if (distance <= 0) {
					cout << "The distance must be greater than zero" << endl;
				}
				else {
					double airSeconds = (distance / 1100);
					cout << "Air: " << distance << " ft" << endl;
					cout << "Traveled for " << airSeconds << " seconds" << endl;
				}
			break;
		
		case 2: //user chooses water
			cout << "Enter distance (in feet)" << endl;
			cin >> distance;
				if (distance <= 0) {
					cout << "The distance must be greater than zero" << endl;
				}
				else {
					double waterSeconds = (distance / 4900);
					cout << "Water: " << distance << " ft" << endl;
					cout << "Traveled for " << waterSeconds << " seconds" << endl;
				}
			break;
	
		case 3://user chooses steel
		cout << "Enter distance (in feet)" << endl;
		cin >> distance;
			if (distance <= 0) {
				cout << "The distance must be greater than zero" << endl;
			}
			else {
				double steelSeconds = (distance / 16400);//calculate the seconds taken 
				cout << "Steel: " << distance << " ft" << endl;
				cout << "Traveled for " << steelSeconds << " seconds" << endl;
			}
			break;
	
	default: //user enters an invalid value
		cout << "The menu value is invalid. Please run the program again." << endl;
	}
}
