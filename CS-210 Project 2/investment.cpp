#include "investment.h"
#include <iostream>
#include <iomanip>  
using namespace std;

// constructor
Investment::Investment() {
	openingAmount = 0.0;
	depositAmount = 0.0;
	totalAmount = 0.0;
	interestAmount = 0.0;
	closingAmount = 0.0;
	years = 0;
}

//get input function
void Investment::getInput() {
    cout << "**********************************" << endl;
    cout << "*********** Data Input ***********" << endl;
	cout << "Initial Investment Amount: $";
    cin >> openingAmount;
    cout << "\nMonthly Deposit: $";
    cin >> depositAmount;
    cout << "\nAnnualInterest: %";
    cin >> interestAmount;
    cout << "\nNumber of years: ";
    cin >> years;
}

//monthlyDeposit() function
float Investment::monthlyDeposit() const {
    return depositAmount;
}

//annualInterest() function
float Investment::annualInterest() const {
    return (interestAmount / 100) / 12;
}

//Calculations and output
void Investment::calculateGrowth() {
	float balance = openingAmount;
	float monthlyInterestRate = annualInterest();

	cout << fixed << setprecision(2); // set percision

	//without deposit variables
	float totalInterestNoDeposit = 0.0;
	float totalBalanceNoDeposit = openingAmount;

	//Display
    
    cout << "\n\n    Balance and Interest Without Additional Monthly Deposit" << endl;
    cout << "=============================================================" << endl;
    cout << " Year       Year End Balance         Year end earned Interest" << endl;
    cout << "-------------------------------------------------------------" << endl;

    balance = openingAmount;
    for (int year = 1; year <= years; year++) {
        totalInterestNoDeposit = 0.0;
        for (int month = 1; month <= 12; month++) {
            float interest = balance * monthlyInterestRate;
            balance += interest;
            totalInterestNoDeposit += interest;
        }

        cout << "  " << year << "           $" << balance << "                       $" << totalInterestNoDeposit << endl;
    }

    cout << "\n    Balance and Interest With Additional Monthly Deposit" << endl;
    cout << "=============================================================" << endl;
    cout << " Year       Year End Balance      Year end earned Interest" << endl;
    cout << "-------------------------------------------------------------" << endl;

    for (int year = 1; year <= years; year++) {
        float yearlyInterest = 0.0;

        for (int month = 1; month <= 12; month++) {
            balance += monthlyDeposit();
            float interest = balance * monthlyInterestRate;
            balance += interest;
            yearlyInterest += interest;
        }

        cout << "  " << year << "         $" << balance << "                      $" << yearlyInterest << endl;
    
    }


}