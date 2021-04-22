//Imports necessary libraries
#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>

//IEEE Standard 754 Floating Point Numbers

//So we know in IEE Standard 754 there are 32 bits
//In this format we are using 2's complement for simplicity sake

//Format: 1 for Sign Bit, 8 bits for exponent, 23 bits for mantissa
// 0 00000000 0000000000000000000000

//To save memory on the stack (more memory efficient), we will assign an object with a struct (similar to a class) to hold the values for conversion to decimal later on. 
typedef union {
	float y;
	struct {
		int mantissa : 23;
		int exponent : 8;
		int sign : 1;
	} raw_ieee;
} decimal_ieee;


//ConvertToDecimal is used to convert the part of the IEEE format to a real number. Is in union with decimal_ieee so it calculates each part of the IEEE correctly.
//int* IEEE = Parameter is set to the pointer (memory address) in the stack of the array IEEE
int ConvertToDecimal(int* IEEE, int low, int high) {
	int y = 0;
	int i;

	for (i = high; i >= low; i--) {
		y = y + IEEE[i] * pow(2, high - i); //Raises the binary to the power of high - i
	}
	return y;
}

int main() {
	
	int IEEE[32] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	std::string IEEE_stringForm; // So that we can convert to an integer form for conversion into the IEEE array
	std::cout << "Input IEEES74 (1,8,23 format): ";
	std::cin >> IEEE_stringForm;

	//Converts string form to IEEE integer for use later in the program
	for (int i = 0; i < 32; i++) {
		IEEE[i] = IEEE_stringForm[i];
	}

	decimal_ieee result; //Initialises the object Decimal_ieee and thus the struct in the variable result
	int decimal_result;
	//Convert mantissa to decimal and assign it to struct
	decimal_result = ConvertToDecimal(IEEE, 9, 32);
	result.raw_ieee.mantissa = decimal_result;
	//Convert exponent to decimal and assign it to struct
	decimal_result = ConvertToDecimal(IEEE, 1, 8);
	result.raw_ieee.exponent = decimal_result;
	//Assign sign bit accordingly
	result.raw_ieee.sign = IEEE[0];

	std::cout << "The float value of IEEE754 set given: ";
	std::cout << result.y;
	







	return 0;
}
