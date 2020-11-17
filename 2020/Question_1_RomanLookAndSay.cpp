#include <iostream>
#include <string>
#include <vector>
#include <sstream>



std::string counter(std::string numeral) {
	std::string new_numeral;
	std::stringstream ss;
	int counter = 1;
	char counterCH;
	char character;
	//MMXX
	for (int i = 0; i < numeral.size(); i++) {
		character = numeral[i]; //M
		if (character == numeral[i + 1]) {
			counter++;
		}
		else {
			ss << counter;
			ss >> counterCH;
			new_numeral.push_back(counterCH);
			new_numeral.push_back(character);
			counter = 1;
		}
	}
	return new_numeral;
}



std::string numeraliser(std::string numeral) {
	//2M2X
	std::stringstream ss;
	ss << numeral;
	int number;
	char ch;
	std::string numeralAdd;

	int M = 1000;
	int D = 500;
	int C = 100;
	int L = 50;
	int X = 10;
	int V = 5;
	int I = 1;

	for (int i = 0; i < numeral.size(); i = i + 2) {

		ss >> number;
		while (number != 0) {
			//exceptions:
			if (number == 4) {
				numeralAdd.append("IV");
				number = number - 4;
			}
			else if (number == 9) {
				numeralAdd.append("IX");
				number = number - 9;
			}
			else if (number == 40) {
				numeralAdd.append("XL");
				number = number - 40;
			}
			else if (number == 90) {
				numeralAdd.append("XC");
				number = number - 90;
			}
			else if (number == 400) {
				numeralAdd.append("CD");
				number = number - 400;
			}
			else if (number == 900) {
				numeralAdd.append("CM");
				number = number - 900;
			}

			//usual cases:

			else if (number - 1000 > -1) {
				numeralAdd.push_back('M');
				number = number - 1000;
			}
			else if (number - 500 > -1) {
				numeralAdd.push_back('D');
				number = number - 500;
			}
			else if (number - 100 > -1) {
				numeralAdd.push_back('C');
				number = number - 100;
			}
			else if (number - 50 > -1) {
				numeralAdd.push_back('L');
				number = number - 50;
			}
			else if (number - 10 > -1) {
				numeralAdd.push_back('X');
				number = number - 10;
			}
			else if (number - 5 > -1) {
				numeralAdd.push_back('V');
				number = number - 5;
			}
			else if (number - 1 > -1) {
				numeralAdd.push_back('I');
				number = number - 1;
			}
		}

		ss >> ch;
		numeralAdd.push_back(ch);
	}

	return numeralAdd;
}

int number_I(std::string numeral) {
	int I = 0;

	for (int i = 0; i < numeral.size(); i++) {
		if (numeral[i] == 'I') {
			I++;
		}
	}

	return I;
}

int number_V(std::string numeral) {
	int V = 0;

	for (int i = 0; i < numeral.size(); i++) {
		if (numeral[i] == 'V') {
			V++;
		}
	}

	return V;
}

int main() {
	std::string str;
	std::string numeral;
	std::string new_numeral;
	std::stringstream ss;
	int n;


	std::getline(std::cin, str);
	ss << str;
	ss >> numeral;
	ss >> n;

	for (int i = 0; i < n; i++) {
		new_numeral = counter(numeral);
		numeral = numeraliser(new_numeral);
	}

	std::cout << number_I(numeral) << " " << number_V(numeral) << std::endl;
	

	






	return 0;
}
