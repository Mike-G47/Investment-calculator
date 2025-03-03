#include <iostream>
#include <string>
#include "investment.h"
using namespace std;



int main() {
	//declare object
	Investment input1;

	//get input
	input1.getInput();
	
	//calculate and print
	input1.calculateGrowth();



		return 0;
}