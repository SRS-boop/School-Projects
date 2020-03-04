// lesson6part1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main() {




	unsigned int lowerVal, upperVal;


	//get input from the user between 32 and 126 inclusive
	cout << "Enter lower and upper values" << endl;
	cin >> lowerVal >> upperVal;


	//validate the input via a while loop - this will keep asking for input until it gets satisfactory upper and lower values
	while (lowerVal < 32 || upperVal > 126 || lowerVal > upperVal) {
		cout << "Values must be in range 32 to 126 inclusive" << "\nEnter lower and upper values\n";
		cin >> lowerVal >> upperVal;
	}


	//tell the user that the ASCII characters that map to the integer inputs will be displayed between the specified values
	cout << "Characters for ASCII values between " << lowerVal << " and " << upperVal << endl;
	cout << "----+----+----+----+\n";


	//use the lowerVal and upperVal input as parameters for a for loop - leave out increment to avoid skipping every 20th character
	int row = 0;// a counter to make sure row length does not exceed 20 characters


	for (int i = lowerVal; i <= upperVal; ) {

		if (row == 20) {//if row is 20, start a new line and reset the row counter
			cout << endl;
			row = 0;
		}
		else {//if row is not 20, cast the integer to a character and output the ASCII character associated with the integer
			cout << static_cast<char>(i);
			row++;//increment the row counter
			i++;//increment ASCII character value

		}

	}


	cout << "\n----+----+----+----+\n";


}
