#include <iostream>
#include <vector>

std::vector<int> lucky_number_generator(std::vector<int> odds, int systematic_removal) {
	
	for (int i = 0 + systematic_removal; i < odds.size(); i = i + systematic_removal) {
		
			odds.erase(odds.begin() + i);
			i--;
		
	}


	return odds;
}

int lucky_number_generator_helper(std::vector<int> odd_numbers, int y) {
	int systematic_removal;

	systematic_removal = odd_numbers[y];

	return systematic_removal;

	
}

std::vector<int> odds(int number) {
	std::vector<int> odds;
	odds.push_back(0);
	odds.push_back(1);
	for (int i = 3; i < number + 200; i = i + 2) {
		odds.push_back(i);
	}

	return odds;
}

int findLower(std::vector<int> odd_numbers, int number) {
	int i = 1;
	int closest = odd_numbers[i];
	int last;

	for (int i = 1; i < odd_numbers.size(); i++) {
		last = odd_numbers[i - 1];
		if (odd_numbers[i] >= number) {
			return last;
		}
	}

}

int findHigher(std::vector<int> odd_numbers, int number) {
	int closest = 0;

	for (int i = 1; i < odd_numbers.size(); i++) {
		if (odd_numbers[i] > number) {
			closest = odd_numbers[i];
			return closest;
		}
	}

}

int main() {
	int lower;
	int higher;
	int number;
	std::cin >> number;

	int y;

	y = 2;

	//Populating vector with 1 and all odds
	std::vector<int> odd_numbers = odds(number);
	int systematic_removal = 3;

	while (systematic_removal < odd_numbers.size()) {

		systematic_removal = lucky_number_generator_helper(odd_numbers, y);
		y++;
		odd_numbers = lucky_number_generator(odd_numbers, systematic_removal);
	}
	
	std::cout << findLower(odd_numbers, number) << " " << findHigher(odd_numbers, number) << std::endl;





	return 0;
}
