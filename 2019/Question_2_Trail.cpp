#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include<utility>


//fuck you recursion

class Game {
public:
	int x;
	int y;
	char face = 'U';
	std::vector<int> pathX;
	std::vector<int> pathY;

	int trailRate;

	int new_x;
	int new_y;


	void moveUp() {
		y = y + 1;
	}

	void moveDown() {
		y = y - 1;
	}

	void moveRight() {
		x = x + 1;
	}

	void moveLeft() {
		x = x - 1;
	}

	void moveNewUp() {
		new_y = y + 1;
		new_x = x;
	}
	void moveNewDown() {
		new_y = y - 1;
		new_x = x;
	}
	void moveNewRight() {
		new_x = x + 1;
		new_y = y;
	}
	void moveNewLeft() {
		new_x = x - 1;
		new_y = y;
	}

	void moveHelper() {
		switch (face) {
		case 'U':
			moveUp();
			break;
		case 'D':
			moveDown();
			break;
		case 'R':
			moveRight();
			break;
		case 'L':
			moveLeft();
			break;
		}
	}

	void moveChecker() {
		switch (face) {
		case 'U':
			moveNewUp();
			break;
		case 'D':
			moveNewDown();
			break;
		case 'R':
			moveNewRight();
			break;
		case 'L':
			moveNewLeft();
			break;
		}
	}

	void faceHelper(char ch) {
		std::vector<char> facings = { 'U', 'R', 'D', 'L' };
		// 0    1    2    3
		int current_index;
		int new_index;
		char new_face;

		//Left - 1;
		// Right + 1;

		for (int i = 0; i < 4; i++) {
			if (facings[i] == face) {
				current_index = i;
			}
		}
		if (ch == 'L') {
			new_index = (current_index + 3) % 4;
			if (new_index == -1) {
				new_index = 3;
				new_face = facings[new_index];
				face = new_face;
			}
			else {
				new_face = facings[new_index];
				face = new_face;
			}
		}
		if (ch == 'R') {
			new_index = (current_index + 1) % 4;
			new_face = facings[new_index];
			face = new_face;
		}


	}

	void pathTrack() {
		if (pathX.size() >= trailRate - 1) {
			pathX.erase(pathX.begin());
			pathX.push_back(x);
		}
		else {
			pathX.push_back(x);
		}

		if (pathY.size() >= trailRate - 1) {
			pathY.erase(pathY.begin());
			pathY.push_back(y);
		}
		else {
			pathY.push_back(y);
		}
	}

	void AuxiliaryMoves() {
		char ch = 'R';
		bool canMove = false;

		for (int i = 0; i < 4; i++) {
			faceHelper(ch);
			moveChecker();
			if (isValid()) {
				canMove = true;
				pathTrack();
				moveHelper();
				break;
			}

		}
		if (canMove) {
			return;
		}
		else {
			//Game Over
			std::cout << "(" << x << ", " << y << ")" << std::endl;
			std::cout << "Cannot make any more moves" << std::endl;
			exit(0);
		}


	}

	bool isValid() {
		//We have new x and new y
		//Check if present in both coord vectors

		for (int i = 0; i < pathX.size(); i++) {
			if (new_x == pathX[i] && new_y == pathY[i]) {
				return false;
			}
		}
		return true;
	}





};




int main() {
	std::string commands;
	std::string str;
	std::stringstream ss;
	int moves;
	char ch;

	int trailRate;


	std::getline(std::cin, str);
	ss << str;
	ss >> trailRate;
	ss >> commands;
	ss >> moves;

	//Initialise game
	Game game;
	game.trailRate = trailRate;
	game.x = 0;
	game.y = 0;
	game.face = 'U';
	int counter = moves;

		for (int x = 0; x < commands.size(); x++) {
			if (counter == 0) {
				break;
			}
			ch = commands[x];
			game.faceHelper(ch);
			game.moveChecker();
			if (game.isValid()) {
				game.pathTrack();
				game.moveHelper();
			} else{
				game.AuxiliaryMoves();

			}
			counter--;
		}

		while (counter != 0) {
			for (int x = 0; x < commands.size(); x++) {
				if (counter == 0) {
					break;
				}
				ch = commands[x];
				game.faceHelper(ch);
				game.moveChecker();
				if (game.isValid()) {
					game.pathTrack();
					game.moveHelper();
				}
				else {
					game.AuxiliaryMoves();

				}
				counter--;
			}
		}
	
	std::cout << "(" << game.x << ", " << game.y << ")" << std::endl;









	return 0;
}
