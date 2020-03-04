// ProgFundHW6.cpp 
/*Name: Samantha Sax
NetID: srs190010
Date submitted: 9/28/19
Date due: 9/29/19
*/
//

#include <iostream>
#include <cmath> // for abs()
using namespace std;

int main()
{

	int userVal;

	// ask for input
	cout << "Hello! Please enter an integer between -20 and 20." << endl;
	cin >> userVal;


	while (userVal < -20 || userVal > 20) {
		cout << "That value is not valid. Please enter an integer between -20 and 20." << endl;
		cin >> userVal;
	}
	while (userVal != 0&& userVal >= -20 && userVal <= 20) {//this will reprompt the user as long as they dont enter zero 
		
		//square wizardry
		if (userVal > 0) {
			for (int sqrRow = 0; sqrRow < userVal; sqrRow++) { //this for loop will form the rows. Each nested for loop inside it will form the columns.
				for (int sqrCol = 0; sqrCol < userVal; sqrCol++) {
					if (sqrRow == 0 || sqrRow == (userVal - 1) || sqrCol == 0 || sqrCol == (userVal - 1)) {
						cout << "@ "; //there is a space after the @ sign to make it look prettier.
					}
					else {
						cout << "  "; //there are two spaces here to make it look prettier.
					}
				}
				cout << endl;
			}
		}

		//triangle wizardry
		else if (userVal < 0) { // for all negative integers chosen in the interval specified, an isoceles right triangle will be displayed to the console
			userVal = abs(userVal); // take absolute value of the user input.
			for (int triRow = 1; triRow <= userVal; triRow++) { //This external for loop once again handles the rows of the triangle
				for (int triSpaces = triRow; triSpaces < userVal; triSpaces++) { //this loop decides when to output a space, hence "triSpaces"
					cout << " ";
				}
				for (int triSigns = 1; triSigns <= (triRow); triSigns++) { //this loop decides when to output an @ sign, hence "triSigns."
					if (triSigns == 1 || triSigns == triRow || triRow == userVal) {
						cout << "@";
					}
					else { cout << " "; }
				}
				cout << endl;
			}
		}
		cout << "Please enter another integer between -20 and positive 20 if you'd like to see more pretty shapes. Otherwise, enter 0 to exit. No hard feelings." << endl;
		cin >> userVal;//this reprompts the user to enter more values within the specified range in order to go back through
		//the program and make more shapes. It exits if the user enters zero 
	}

}
