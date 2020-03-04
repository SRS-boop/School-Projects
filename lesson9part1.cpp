/*Name: Samantha Sax
NetID: srs190010

This program uses functions to read in data for a hypothetical product order. The user will input an order for spools of wire,
including how many are ordered, if there is special shipping and handling fees, and how many spools are actually in stock.
The next function, readyOrBackOrder, will handle calculating how many of the ordered spools are availible to ship,
and how many are on backorder. The final two functions, calcFunction and displayFunction calculate the cost of the spools
ready to ship and the fees applied to those spools, and then displays the final order summary to the console. All values
are passed by reference and no global variables are used.*/

#include <iostream>
#include <iomanip>


using namespace std;


//function prototypes
void readInFunction(int&, int&, double&);
double calcFunction(int&, double&, const double, double&, double&, double&);
void displayFunction(int&, int&, double&, double&, double&);
void readyOrBackOrder(int&, int&, int&, int&);

//main function
int main() {
	const double SPOOL_COST = 104.00;//constant cost of the product
	int orderedSpools, stockSpools;//spools that are ordered and spools that are in stock
	double shipAndHand;//shipping and handling costs

	readInFunction(orderedSpools, stockSpools, shipAndHand);//pass in parameters by reference to the readInFunction

	//define variables to be passed to the readyOrBackOrder, calcFunction, and displayFunctions.
	int readySpools = 0, backOrderSpools = 0;//spools that are ready to deliver and spools that are on backorder
	double readySpoolCost = 0, shippingFeeTotal = 0, totalAllIn = 0;//cost of spools ready to sell, the shipping fee for those spools, and the total of deliverable product with all fees applied


	readyOrBackOrder(orderedSpools, stockSpools, readySpools, backOrderSpools);

	calcFunction(readySpools, shipAndHand, SPOOL_COST, totalAllIn, readySpoolCost, shippingFeeTotal);//calculate costs

	displayFunction(readySpools, backOrderSpools, readySpoolCost, shippingFeeTotal, totalAllIn);//format and display results
}


//function definitions
//read in spools to be ordered, spools in stock, and shipping and handling fee
void readInFunction(int& orderedSpools, int& stockSpools, double& shipAndHand) {

	cout << "Spools to be ordered\n";
	cin >> orderedSpools;

	//validate data
	while (orderedSpools < 1) {
		cout << "Spools order must be 1 or more\n";
		cout << "Spools to be ordered\n";
		cin >> orderedSpools;
	}

	cout << "Spools in stock\n";
	cin >> stockSpools;

	//validate data
	while (stockSpools < 0) {
		cout << "Spools in stock must be 0 or more\n";
		cout << "Spools in stock\n";
		cin >> stockSpools;
	}

	//check for a special shipping rate
	char y = 'y', n = 'n';
	char userChar;

	cout << "Special shipping and handling (y or n)\n";
	cin >> userChar;

	//if there is a special rate:
	if (userChar == y) {//if the user enters y
		cout << "Shipping and handling amount\n";
		cin >> shipAndHand;//user enters shipping fee amount

		//validate data
		while (shipAndHand < 0) {//if the fee is invalid (less than zero), display error and reprompt
			cout << "The spool shipping and handling charge must be 0.0 or more\n";
			cout << "Shipping and handling amount\n";
			cin >> shipAndHand;
		}
	}
	//if there is no special shipping, use the default amount
	else if (userChar == n) {//if the user enters n, assign default shipping fee. 
		shipAndHand = 12.99;
	}
}

//calculate how many spools are ready to sell vs how many are on backorder.
void readyOrBackOrder(int& orderedSpools, int& stockSpools, int& readySpools, int& backOrderSpools) {

	if (stockSpools >= orderedSpools) {//if spools in stock exceed spools ordered
		readySpools = orderedSpools;
		backOrderSpools = 0;
	}

	else if (stockSpools < orderedSpools) {//if spools ordered exceed spools in stock
		backOrderSpools = orderedSpools - stockSpools;
		readySpools = stockSpools;
	}

}


//pass in parameters by reference for calulations for cost of the ready product, cost of fees for that product, then total cost of fees and product
double calcFunction(int& readySpools, double& shipAndHand, const double SPOOL_COST, double& totalAllIn, double& readySpoolCost, double& shippingFeeTotal) {

	readySpoolCost = readySpools * SPOOL_COST;//total cost of the product
	shippingFeeTotal = shipAndHand * readySpools;//total cost of additional fees
	totalAllIn = readySpoolCost + shippingFeeTotal;//total cost of product plus fees

	return 0;
}

//format and display data on the console
void displayFunction(int& readySpools, int& backOrderSpools, double& readySpoolCost, double& shippingFeeTotal, double& totalAllIn) {
	cout << setprecision(2) << fixed;
	cout << "Spools ready to ship: " << right << readySpools << endl;
	cout << "Spools on back-order: " << right << backOrderSpools << endl;
	cout << "Subtotal ready to ship: $" <<setw(10) << readySpoolCost << endl;
	cout << "Shipping and handling:  $"  << setw(10) << shippingFeeTotal << endl;
	cout << "Total shipping charges: $" <<  setw(10) << totalAllIn << endl;
}