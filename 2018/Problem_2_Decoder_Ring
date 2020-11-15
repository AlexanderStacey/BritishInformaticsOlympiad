#include <iostream>
#include <string>
#include <vector>
#include <sstream>
std::vector<char> rotate_left(std::vector <char> second_dial) {
	int index;

	for (int i = 0; i < 26; i++) {
		index = i - 1;
		if (index == -1) {
			index = 25;
		}

		second_dial[index] = second_dial[i];
	}

	return second_dial;
}


void deciphered_print(std::string deciphered_message) {

	for (int i = 0; i < deciphered_message.size(); i++) {
		std::cout << deciphered_message[i];
	}
	std::cout << "" << std::endl;


}

void second_dial_print(std::vector<char> second_dial) {
	for (int i = 0; i < 6; i++) {
		std::cout << second_dial[i];
	}
	std::cout << "" << std::endl;
}

std::vector <char> second_dial_generator(int n) {
	std::vector <char> alphabet = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	std::vector <char> second_dial;
	int index = 0;
	char ch;

	while (alphabet.size() != 0) {
		index = index + (n - 1);
		index = index % alphabet.size();
		ch = alphabet[index];
		second_dial.push_back(ch);
		alphabet.erase(alphabet.begin() + (index));
	}
	return second_dial;
}

int find_index_alphabet(char ch) {
	int index;
	std::vector <char> alphabet = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };


	for (int i = 0; i < 26; i++) {
		if (alphabet[i] == ch) {
			index = i;
		}
	}
	return index;
}

std::string decipher(std::vector <char> second_dial, std::string w) {
	std::vector <char> first_dial = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	//0    1    2    3    4    5	 6	  7    8	9    10   11   12   13   14   15   16   17   18   19   20   21   22   23   24   25
	std::string deciphered_message = w;
	int index;

	char ch;
		for (int i = 0; i < w.size(); i++) {
			ch = deciphered_message[i];
			index = find_index_alphabet(ch);
			deciphered_message[i] = second_dial[index];
			second_dial = rotate_left(second_dial);

		}
	
	


	return deciphered_message;
}


int main() {

	std::vector <char> second_dial;


	int n;
	std::string w;
	std::string str;
	std::stringstream ss;
	std::string deciphered_message;



	std::getline(std::cin, str);
	ss << str;
	ss >> n;
	ss >> w;

	//Generate second_dial
	second_dial = second_dial_generator(n);

	//Print first 6 letters of the second_dial for first part of output
	second_dial_print(second_dial);

	//Now we decipher the message given by the input
	deciphered_message = decipher(second_dial, w);

	//Nowe we print the deciphered_message

	deciphered_print(deciphered_message);







	return 0;
}
