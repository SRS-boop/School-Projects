/*
Name: Samantha Sax



This program will read in a file containing five columns and a maximum of 30 rows of grades, store those values in 
a multidimentional array, and calculate the average, and smallest values of those grades per column and row respectively.*/

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX_COLUMNS = 5;


// read input file and populate the array
int readFile(double values[][MAX_COLUMNS], int maxRows, string inputFileName);

// for the array
double average(double values[][MAX_COLUMNS], int numberRows);

// for a specified column (column)
double columnAverage(double values[][MAX_COLUMNS], int column, int numberRows);

//smallest values in a row function prototype
double smallestRowValue(double values[][MAX_COLUMNS], int rowNumber);



//MAIN FUNCTION BEGINS HERE
int main()
{
	const int maxRows = 30;//constant max rows 
	double values[maxRows][MAX_COLUMNS];
	string inputFileName;
	

	//get user-defined input file name
	cout << "Enter input file name\n";
	  getline(cin, inputFileName);

	  //call the funtion to read, store in an array, and return the number of rows read in
	  int actualRows = readFile(values, maxRows, inputFileName);
	
	  //if the file couldn't be read, display error message
	  if (actualRows == -1) {
		  cout << "File \"" << inputFileName << "\" could not be opened\n";
		  exit(EXIT_FAILURE);//quit the program
	  }

		//if the file was empty
		 else if (actualRows == 0) {
			  cout << "The input file \"" << inputFileName << "\" did not contain any data\n";
		  }

			//process the data
			else {
				cout << "Processing " << actualRows << " rows, and 5 columns\n";
				cout << "Average for all values is " << setprecision(2) << fixed << average(values, actualRows) << endl;
				
				//loop through each column to display the average of each
				for (int colNum = 0; colNum < MAX_COLUMNS; colNum++) {
					  cout << "Average for column " << colNum << " is " << columnAverage(values, colNum, actualRows) << endl;
				}
				//loop through rows to display the smallest values of each
				for (int rowNum = 0; rowNum < actualRows; rowNum++) {
					 cout << "Smallest value for row " << rowNum << " is " << smallestRowValue(values, rowNum) << endl;
				}
			}	 
}

//FUNCTION DEFINITIONS

//inputFile will have 5 columns and a maximum of 30 rows
int readFile(double values[][MAX_COLUMNS], int maxRows, string inputFileName) {
	
	double val1;//variable that stores the data point read in from the file
	int rowCounter = 0;//keep track of how many rows are read in

	//open input file
	ifstream inputFile;
	inputFile.open(inputFileName);

	//verify the file is open
	if (inputFile.is_open()) {

		//if it is open, check to make sure it is not empty by checking for the End Of File marker
		if (inputFile.peek() == EOF) {
			return 0;//if it is empty, return a 0
		}

			//if it is not empty, iterate through the columns and rows, extracting a data point at a time
			for (int rowNum = 0; rowNum < maxRows; rowNum++) {
				for (int colNum = 0; colNum < MAX_COLUMNS; colNum++) {
					
					if ((inputFile.peek() == EOF)) {//if this row is empty, return total rows read in 
					
						return rowCounter;
					}
						else {//if this row is not empty, read in and assign the data point to the array
							inputFile >> val1;
							values[rowNum][colNum] = val1;
						
						
						}
				}
					
			rowCounter++;//increment the row counter and go back through the first for loop.
				}
			return rowCounter;

	}
	
	//if the file failed to open, return -1	
	else if (inputFile.fail()) {
		return -1;
	}
}

//average for all values function begins here
double average(double values[][MAX_COLUMNS], int numberRows) {
	double total = 0;//initialize total to 0
	for (int rowNum = 0; rowNum < numberRows; rowNum++) {
		for (int colNum = 0; colNum < MAX_COLUMNS; colNum++) {
			total = total + values[rowNum][colNum];//total is reassigned to itself plus the stored value
		}
	}

	//calculate average from sum
	double average = (total / (static_cast<double>(numberRows) * 5.0));//cast to a double to avoid truncation

		//return the average calculated
		return average;
}

//column average calculation function begins here
double columnAverage(double values[][MAX_COLUMNS], int column, int numberRows) {
	//specific column designation is passed in by value
	double columnTotal = 0;//initialize columnTotal sum to 0 
	double averageOfOneCol;
	
	for (int rowNum = 0; rowNum < numberRows; rowNum++) {
		columnTotal = columnTotal + values[rowNum][column];//add the columnTotal to the next value in the column
	}
	//calculate average, casting ints to doubles to avoid truncation
	averageOfOneCol = (columnTotal / static_cast<double>(numberRows));
	
	//return average of the specified column
		return averageOfOneCol;
}

//smallest value per row function begins here
double smallestRowValue(double values[][MAX_COLUMNS], int rowNumber) {
	//specified row to be calculated is passed in by value
	double smallestVal = values[rowNumber][0];//set the smallest value to the first value in that row (value at column 0)

	for (int colNum = 0; colNum < MAX_COLUMNS; colNum++) {
		if (values[rowNumber][colNum] <= smallestVal){//if the next value is smaller than the current smallest value, reassign 
			smallestVal = values[rowNumber][colNum];
		}
	}

	//return the smallest value in that row
		return smallestVal;
}

