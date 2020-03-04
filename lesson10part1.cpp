/*
Name: Samantha Sax


This function reads in a students' and the correct quiz answers from input files and stores that data into two parallel arrays.
The data in the arrays are then compared for parity, and the score of the student is calculated and recorded. Incorrect student 
answers are displayed with their correct answers.*/
//

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <array>
using namespace std;


//prototype functions
void displayResults(char studentAnswers[], char correctAnswers[], int countCorrectAns);
int readAnswers(char studentAnswers[], string, int& count);


//main function 
int main()
{
	//define local variables/arrays
	char correctAnswers[30];
	char studentAnswers[30];
	char tempArr[30];
	int size;
	string studentInput;
	string correctInput;


	//get user input
	cout << "Enter student answers file name\n";
	getline(cin, studentInput);

	//call read funtion and assign the return value to a variable that will be used to record array size
	int size1 = readAnswers(tempArr, studentInput, size);


	//transfer values from tempArr to student answer array
	for (int i = 0; i < size1; i++) {
		studentAnswers[i] = tempArr[i];
	}

	//if the previous read worked, repeat the process with the correct answer input file file 
	if (size1 != -1) {
		cout << "Enter correct answer file name\n";
		getline(cin, correctInput);

		//call function and record return value
		int size2 = readAnswers(tempArr, correctInput, size);


		//if second read failed, return error message
		if (size2 == -1) {
			cout << "File \"" << correctInput << "\" could not be opened\n";
		}

		//if it didnt fail, assign correct answer array with tempArr values
		else {


			for (int i = 0; i < size2; i++) {
				correctAnswers[i] = tempArr[i];
			}

			//assign number of correct answers to count correct variable
			//int countCorrectAns = size;

			//compare the two count variables and display errors if needed
			if (size1 != size2) {
				cout << "The student answers file has " << size1 << " entries and the correct answers file has " << size2 << " entries\n";
				cout << "Grading cannot be done if they are not the same\n";

				exit(EXIT_FAILURE);
			}

			//if theyre both zero
			else if ((size1 == 0) && (size2 == 0)) {
				cout << "The number of student answers and correct answers are both 0\n";
				cout << "No grade can be calculated\n";

				exit(EXIT_FAILURE);
			}
			//the else statement will call the display function 					
			else {
				
				displayResults(studentAnswers, correctAnswers, size);

			}
		}
	}
	else {
		cout << "File \"" << studentInput << "\" could not be opened\n";
	}
}




//function definitions
//the readAnswers function opens an input file specified by the user, reads the data into an array, and returns the size of the array.
			int readAnswers(char tempArr[], string inputFileName, int& size) {
				ifstream inputFile;
				inputFile.open(inputFileName);
				if (inputFile.is_open()) {


					//define variable to store the read-in data
					char answer;
					size = 0;//keep track of number of elements in array
					for (int i = 0; i < 30; i++) {
						if (inputFile >> answer) {
							tempArr[i] = answer;
							size = size + 1;
						}
							else { break; }
						}

					//if array elements exceed 30, rturn 30
					if (size > 30) {
						return 30;
					}
						//else if they don't exceed 30, return the number of elements
						else if (size <= 30) {
							return size;
						}
				}	//else if the file fails to open, display error message.
						else if (inputFile.fail()) {
					//cout << "File \"" << inputFileName << "\" could not be opened\n";
						return -1;
				}
			}
		
			//this function calculates and displays the results of the student's score based on passed in values.
			void displayResults(char studentAnswers[], char correctAnswers[], int size) {
				
				//define and initialize counters for the number of correct, incorrect, and total answers.
				int correctAns = 0;
				int incorrectAns = 0;
				int totalAns = size; //to use this function, returnVal1 and returnVal2 must be equal so i could have used either here.

				//iterate through the arrays and compare values of their contents
				for (int i = 0; i < size; i++) {
					if (studentAnswers[i] == correctAnswers[i]) {
						continue;
						
					}
						else {
							cout << "Question " << (i + 1) << " has incorrect answer \'" << studentAnswers[i] << "\', the correct answer is \'" << correctAnswers[i] << "\'\n";
							incorrectAns = incorrectAns + 1;
						}
				}
				
				//calculate number of correct answers and score
				correctAns = totalAns - incorrectAns;
				//cast to doubles for calculations
				double score = (static_cast<double>(correctAns) / static_cast<double>(totalAns)) * 100;
				
				//display results to the console.
				cout << setprecision(1) << fixed;
				cout << incorrectAns << " questions were missed out of " << totalAns << endl;
				cout << "The student grade is " << score << "%\n";
				if ((score - 70) < -0.001) {
					cout << "The student failed\n";
				}

					else {
						cout << "The student passed\n";
					}
			}
