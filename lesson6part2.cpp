// lesson6part2.cpp 

/*Samantha Sax
netID srs190010


This program will read in a starting temperature, and ending temperature, and a value to increment the temperature by, 
and output the indicated temperature in fahrenheit, celcius, and kelvin for each increment. Results are displayed
in 18 characters wide columns with corresponding headers, to a precision of 4 decimal places. */

#include<iostream>
#include<iomanip>

using namespace std;

int main() {

	//define the starting and ending temperatures in Fahrenheit and the increment value
	double startTemp, endTemp, incVal;

	cin >> startTemp >> endTemp >> incVal;

	//validate the input
	while ((startTemp > endTemp) || (incVal <= 0.0)) {
		cout << "Starting temperature must be <= ending temperature and increment must be > 0.0\n";
		cin >> startTemp >> endTemp >> incVal;
	}

	//format output to fixed point with 4 decimal places of precision and output headers
	cout << setprecision(4) << fixed << right;
	cout << setw(18) << "Fahrenheit" << setw(18) << "Celsius" << setw(18) << "Kelvin" << endl;


	//increment the placeholder value i by incVal
	for (double i = startTemp; i <= endTemp; i = (i + incVal)) {
		double cStartTemp = ((i - 32) / 1.8);//celsius conversion
		double kStartTemp = (cStartTemp + 273.15);//kelvin conversion

		//display output for every iteration 
		cout << setw(18) << i << setw(18) << cStartTemp << setw(18) << kStartTemp << endl;
	}
}

