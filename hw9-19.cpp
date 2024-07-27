//Intermediate19.cpp - displays two monthly car payments
//and the total paid if financing through the credit union
//and dealer
//Created/revised by <your name> on <current date>

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//function prototypes
double getPayment(int, double, int);
double getTotal(double, int);

int main()
{
	int carPrice = 0;
	int rebate = 0;
	double creditRate = 0.0;
	double dealerRate = 0.0;
	int term = 0;
	double creditPayment = 0.0;
	double dealerPayment = 0.0;
	double totalCreditPaid = 0.0;
	double totalDealerPaid = 0.0;

	cout << "Car price (after any trade-in): ";
	cin >> carPrice;
	cout << "Rebate: ";
	cin >> rebate;
	cout << "Credit union rate: ";
	cin >> creditRate;
	cout << "Dealer rate: ";
	cin >> dealerRate;
	cout << "Term in years: ";
	cin >> term;

	//call function to calculate payments
	creditPayment = getPayment(carPrice - rebate,
		creditRate / 12, term * 12);
	dealerPayment = getPayment(carPrice, 
		dealerRate / 12, term * 12);
	//call function to calculate totals
	totalCreditPaid = getTotal(creditPayment, term * 12);
	totalDealerPaid = getTotal(dealerPayment, term * 12);

	//display payments and totals
	cout << fixed << setprecision(2) << endl; 
	cout << "Credit union payment: $" 
		<< creditPayment << endl;
	cout << "Total paid financing through credit union: $" 
		<< totalCreditPaid << endl;

	cout << "Dealer payment: $"
		<< dealerPayment << endl;
	cout << "Total paid financing through dealer: $" 
		<< totalDealerPaid << endl;
	return 0;
}	//end of main function

//*****function definitions*****
double getPayment(int prin,
				  double monthRate, 
				  int months)
{
	//calculates and returns a monthly payment
    double monthPay = 0.0;
	double denominator = 0.0;

	denominator = 1 - pow(monthRate + 1, -months);
	if (denominator != 0)
		monthPay = prin * monthRate / denominator;
	else
		monthPay = -1;
	return monthPay;
}	//end of getPayment function

double getTotal(double monthPay, int months)
{
	double total = 0.0;
	double roundedPay = 0.0;

	roundedPay = static_cast<int>((monthPay + .005) * 100) / 100.0;
	total = roundedPay * months;
	return total;
} //end of getTotal function
