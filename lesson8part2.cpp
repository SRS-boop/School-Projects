/* 
Name: Samantha Sax
NetID: srs190010
Date due: 11/10/19

This program will use functions to read in the future value, the interest rate, and the number of years, and calculate the present value
from those inputs. Data in the read functions will be validated by a while loop, to ensure nonzero input is obtained. 
After reading in and calculating, the results will be formatted and displayed by another function by passing in the values. 
*/

#include <iostream>
#include<cmath>
#include <iomanip>

using namespace std;

//function definitions

//calculate the present value based on future value, interest rate, and number of years inputs
double presentValue(double futureValue, double interestRate, int numberYears) {
	double presentVal = (futureValue / (pow((1 + interestRate), numberYears)));

	return presentVal;
}

//read in the future value to be used in the presentValue() function
double readFutureVal() {

	double futureVal;
	cout << "Enter future value\n";
	cin >> futureVal;
	
		//validate future value input
		while (futureVal <= 0) {
			cout << "The future value must be greater than zero\n";
			cout << "Enter future value\n";
				cin >> futureVal;
	}

	return futureVal;//return it to main
}



//read in the interest rate and change it from a percent to a decimal
double readInterestRate() {

	double interestRateTemp;
	cout << "Enter annual interest rate\n";
		cin >> interestRateTemp;
		
		//validate interest rate input
		while (interestRateTemp <= 0) {
				cout << "The annual interest rate must be greater than zero\n";
				cout << "Enter annual interest rate\n";
					cin >> interestRateTemp;
	}
	//convert from percent to decimal
	double interestRate = interestRateTemp / 100;

	//return to main()
	return interestRate;
}


//read in number of years
int readNumYears() {
	int numYears;
	cout << "Enter number of years\n";
		cin >> numYears;
		
	//validate input
		while (numYears <= 0) {
			cout << "The number of years must be greater than zero\n";
			cout << "Enter number of years\n";
				cin >> numYears;

	}
	//return to main()
	return numYears;
}


//format and display results
void displayResults(double presentVal, double futureVal, double interestRate, int numYears) {
	cout << setprecision(2) << fixed;
	cout << "Present value: $" << presentVal << endl;
	cout << "Future value: $" << futureVal << endl;
	cout << setprecision(3) << fixed;
	cout << "Annual interest rate: " << (interestRate * 100) << "%\n";//convert the interest rate from decimal back to percent
	cout << "Years: " << static_cast<int>(numYears) << endl;//output years as an integer

}
//end of function definitions

//program body
//call functions
int main() {
	double futureValPass = readFutureVal();
	double interestRatePass = readInterestRate();
	int numYearsPass = readNumYears();
	double presentValPass = presentValue(futureValPass, interestRatePass, numYearsPass);
	displayResults(presentValPass, futureValPass, interestRatePass, numYearsPass);

}