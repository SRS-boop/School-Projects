// lesson7part1.cpp : 
/* 
Name: Samantha Sax
NetID: srs190010
*/
//This program will read in data from a file indicated by a user and format that data into a bar chart that is displayed 
//in another txt file called "saleschart.txt." Data from inputfiles will be validated using if statements. Integer division
//is used to determine the number of asterisks displayed in the chart.

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;


int main()
{
	ifstream inputFile;
	ofstream outputFile;
	string fileName;
	unsigned int storeNum=0;
	long long int storeSales=0;

	//prompt for file name
	cout << "Enter input file name\n";
	cin >> fileName;

	//create an object and open fileName
	inputFile.open(fileName);

	//open the file and check that it opened
	if (inputFile) {//if inputfile opened
		//open outputFile
		outputFile.open("saleschart.txt");

		//check if it opened, and if it did, begin outputting bar chart headers and data into the file
			if (outputFile) {
				outputFile << "SALES BAR CHART\n" << "(Each * equals 5,000 dollars)\n";

			//begin reading in and outputting barchart
				while (inputFile >> storeNum >> storeSales) {
					//validate that storeNum data is 1<=storeNum<=99
					
					if ((storeNum < 1) || (storeNum > 99)) {
						cout << "The store number " << storeNum << " is not valid\n";
						
						
					}
					
					//validate that storeSales is not negative
					else if ((storeSales < 0)) {
						cout << "The sales value for store " << storeNum << " is negative\n";
						
						
					}
					
					//if all data is good, process it into the output file
					else {
						long long int asteriskNum = storeSales / 5000;//calculate how many asterisks to output
					
							outputFile << "Store " << setw(2) << storeNum << ": ";//for each line in input file, output a line in outputfile
								//enter a loop that outputs an asterisk for each 5000 in sales
								for (int countJ = 0; countJ < asteriskNum; countJ++) {
									outputFile << "*";
								}
							outputFile << endl;//make a newline for each bar chart line
						}
				}//exit while loop
			
		}
			//else for if the outputFile doesn't open
			else {
				cout << "The file could not be opened\n";
				inputFile.close();
				
			}
	}
	
	//else for if the inputFile doesn't open 
	else {
		cout << "File \"" << fileName << "\" could not be opened\n";
		
	}
	
	//close both files if all runs as it should
	inputFile.close();
	outputFile.close();

	return 0;
}

