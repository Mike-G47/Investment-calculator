#ifndef INVESTMENT_H
#define INVESTMENT_H
#include <string>
using namespace std;

class Investment {
public:
    // constructor
    Investment();
    // declare functions
    void getInput();
    float monthlyDeposit() const;
    float annualInterest() const;
    void calculateGrowth();

    //private variables
private:
    float openingAmount;
    float depositAmount;
    float totalAmount;
    float interestAmount;
    float closingAmount;
    int years;
};

#endif