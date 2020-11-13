#include <vector>
#include <string>
#include <sstream>
#include<iostream>



int main() {
	std::string str;
	std::stringstream ss;
	char ch;
	std::vector<char> array;

	std::getline(std::cin, str);
	ss << str;

	//populating vector with items
	for (int i = 0; i < str.size(); i++) {
		ss >> ch;
		array.push_back(ch);
	}
	int n = array.size();
	for (int y = 0; y < n - 1; y++) {
		for (int i = 0; i < array.size() - 1; i++) {
			if (array[i] == array[i + 1]) {
				array[i] = array[i];
			}
			else if (array[i] == 'R' && array[i + 1] == 'G') {
				//B
				array[i] = 'B';
			}
			else if (array[i] == 'R' && array[i + 1] == 'B') {
				//G
				array[i] = 'G';
			}
			else if (array[i] == 'B' && array[i + 1] == 'G') {
				//R
				array[i] = 'R';
			}
			else if (array[i] == 'B' && array[i + 1] == 'R') {
				//G
				array[i] = 'G';
			}
			else if (array[i] == 'G' && array[i + 1] == 'R') {
				//B
				array[i] = 'B';
			}
			else if (array[i] == 'G' && array[i + 1] == 'B') {
				//R
				array[i] = 'R';
			}

			

		}

		array.pop_back();
	}
	std::cout << array[0] << std::endl;





	return 0;
}
