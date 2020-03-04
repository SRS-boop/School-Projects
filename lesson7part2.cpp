// lesson7part2.cpp : 
/*Name: Samantha Sax


This program will read in a list of numbers from a user-specified file and calculate the average of all
non-negative values in the list between 1 and 105. Once the file has been validated, a message specifying 
that the file is being read is displayed. Invalid values are output to an invalid-values.txt file.
When there are no valid input numbers, and the average cannot be calculated, an error message is displayed. 
A running count of the number of valid inputs and invalid inputs is kept, and the total sum of valid inputs is calculated.*/
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>


using namespace std;

int main()
{
	string fileName;//to get user file name
	ifstream inputFile;//create an object for user specified file
	ofstream invalidNumFile;//create an object for the output file for invalid numbers
	double inputNum, validNumCount=0, invalidNumCount=0, validNumSum=0, totalNum=0, avgValidNum;

	//get filename input from user
	cout << "Enter input file name\n";
	cin >> fileName;
	
	//open invalid input file
	invalidNumFile.open("invalid-values.txt");
	
	//check that invalidNumFile opened
	if (!invalidNumFile) {
		cout << "File \"invalidNumFile\" could not be opened\n";
	}

	//open input file to read from
	inputFile.open(fileName);

	//check that it opened correctly
	if(inputFile){
		cout << "Reading from file \"" << fileName << "\"\n";

		//read in and process data
		while (inputFile >> inputNum) {
			//validate data
			if ((inputNum >= 0) && (inputNum <= 105)) {
				validNumCount++;//increment valid input counter
				validNumSum = validNumSum + inputNum;//calculate running sum of al valid inputs
			}
			//if data is invalid, output it into invalid-values.txt
			else if ((inputNum < 0) || (inputNum > 105)) {
				invalidNumFile << setprecision(5) << fixed;
					invalidNumFile << inputNum << endl;
					invalidNumCount++;//increment invalid input counter
					}
		}

		totalNum = validNumCount + invalidNumCount;//sum total number of inputs
		

		if (validNumCount == 0) {//if the average can not be calculated (dividing by zero valid number count)
			cout << "Total values: " << totalNum << endl;
			cout << "Invalid values: " << invalidNumCount << endl;
			cout << "Valid values: " << validNumCount << endl;
			cout << "An average cannot be calculated" << endl;
		}
			else if (validNumCount != 0){//if the average can be calculated
				avgValidNum = validNumSum / validNumCount;
				cout << "Total values: " << totalNum << endl;
				cout << "Invalid values: " << invalidNumCount << endl;
				cout << "Valid values: " << validNumCount << endl;
				cout << setprecision(4) << fixed;//format final cout output
				cout << "Average of valid values: " << avgValidNum << endl;
			}
		}
	else {
		cout << "File \"" << fileName << "\" could not be opened\n";
	}
	}

