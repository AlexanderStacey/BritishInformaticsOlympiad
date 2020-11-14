#include <iostream>
#include<string>
#include <sstream>
#include <utility>
#include <stdio.h>


//Loses 4 or so marks due to rounding.
//Suggestions to reader and self, when working with decimals. Turn to integer form and then work stuff of using that, it is a lot easier! Alongside the values will be near to fully accurate
// / 100 after to achieve the decimal form


float interestCalculate(double interest, double current) {

	double amount_interest = current * (interest / 100);
	amount_interest = ceil((amount_interest * 100)) / 100;
	current = current + amount_interest;

	return current;

}

std::pair <double, double> repaymentCalculate(double repayment, double current) {
	std::pair <double, double> repaymentCalculation;
	// first = current
	// second = debtpaid
	double debt_paid = 0;

	double amount_repayment = current * (repayment/ 100);
	amount_repayment = ceil((amount_repayment * 100)) / 100;
	if (amount_repayment < 50) {
		if (current - 50 < 0) {
			amount_repayment = current;

			current = current - amount_repayment;
			debt_paid = debt_paid + amount_repayment;
		}
		else {
			current = current - 50;
			debt_paid = debt_paid + 50;
		}

	}
	else {
		current = current - amount_repayment;
		debt_paid = amount_repayment;

	}
	

	repaymentCalculation.first = current;
	repaymentCalculation.second = debt_paid;

	return repaymentCalculation;
}




int main() {
	double interest;
	double  repayment;
	double current_Debt = 100;
	double debt_paid = 0;
	std::pair <double, double> repaymentCalculation;
	std::stringstream ss;

	std::string str;
	std::getline(std::cin, str);
	ss << str;
	ss >> interest;
	ss >> repayment;

	while (current_Debt > 0) {
		current_Debt = interestCalculate(interest, current_Debt);
		repaymentCalculation = repaymentCalculate(repayment, current_Debt);
		current_Debt = repaymentCalculation.first;
		debt_paid = debt_paid + repaymentCalculation.second;
	}

	printf("%0.2f", ceil((debt_paid * 100))/100);

	









	return 0;
}
