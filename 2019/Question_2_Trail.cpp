#include <iostream>
#include <utility>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>


//God fucking help me, there's a bug to do with the rotations required after a move not being able to be met. Need to fix but lack motivation..

class Game {
public:
	//Variables
	std::pair<int, int> coordinates;
	char facing;
	std::vector<std::pair<int, int>> path;
	int game_path_vanish;
	std::pair<int, int> next_coordinates;
	char auxFace;
	bool endProgramBool = false;

	//Drivers to initialise the game
	void coordinatesDriver(){
		coordinates.first = 0; //x
		coordinates.second = 0; //y

	}

	void facingDriver() {
		facing = 'U';
	}

	void pathDriver(int path_vanish) {
		game_path_vanish = path_vanish;
		path.push_back(coordinates);
	}

	//Move commands
	void MoveUp() {
		coordinates.second = coordinates.second + 1;
	}
	void MoveDown() {
		coordinates.second = coordinates.second - 1;
	}
	void MoveLeft() {
		coordinates.first = coordinates.first - 1;
	}
	void MoveRight() {
		coordinates.first = coordinates.first + 1;
	}

	void nextUp() {
		next_coordinates.second = next_coordinates.second + 1;
	}
	void nextDown() {
		next_coordinates.second = next_coordinates.second - 1;
	}
	void nextLeft() {
		next_coordinates.first = next_coordinates.first - 1;
	}
	void nextRight() {
		next_coordinates.first = next_coordinates.first + 1;
	}

	void decideMove() {
		if (facing == 'U') {
			nextUp();
			if (availablePath()) {
				MoveUp();
				path_adder();
			}
			else {
				auxMoves();
			}
		}
		else if (facing == 'R') {
			nextRight();
			if (availablePath()) {
				MoveRight();
				path_adder();
			}
			else {
				auxMoves();
			}
		}
		else if (facing == 'L') {
			nextLeft();
			if (availablePath()) {
				MoveLeft();
				path_adder();
			}
			else {
				auxMoves();
			}
		}
		else if (facing == 'D') {
			nextDown();
			if (availablePath()) {
				MoveDown();
				path_adder();
			}
			else {
				auxMoves();
			}
		}
	}

	void auxMoves() {
		if (auxFace == 'R') {
			endProgram();

		}
		auxFace = 'R';
		changeFace(auxFace);
		decideMove();

	}

	void endProgram() {
		endProgramBool = true;
	}

	void changeFace(char ch) {
		if (ch == 'L') {
			if (facing == 'U') {
				facing = 'L';
				decideMove();
			}
			else if (facing == 'R') {
				facing = 'U';
				decideMove();
			}
			else if (facing == 'D') {
				facing = 'R';
				decideMove();
			} 
			else if (facing == 'L') {
				facing = 'D';
				decideMove();
			}
		}
		else if (ch == 'R') {
				if (facing == 'U') {
					facing = 'R';
					decideMove();
				}
				else if (facing == 'R') {
					facing = 'D';
					decideMove();
				}
				else if (facing == 'D') {
					facing = 'L';
					decideMove();

				}
				else if (facing == 'L') {
					facing = 'U';
					decideMove();
				}
			}
		
		else if (ch == 'F') {
			decideMove();
		}
	}

	//Path commands
	void path_adder() {
		if (Is_Path_Full() == true) {
			path.erase(path.begin());
			path.push_back(coordinates);
		}
		else {
			path.push_back(coordinates);
		}
	}

	bool availablePath(){
		for (int i = 0; i < path.size(); i++) {
			if (path[i].first == next_coordinates.first && path[i].second == next_coordinates.second) {
				return false;
			}
		}
		return true;
	}

	bool Is_Path_Full() {
		if (path.size() == game_path_vanish) {
			return true;
		}
		else {
			return false;
		}
	}

	//Utility commands
	void printCurrent() {
		std::cout << "(" << coordinates.first << ", " << coordinates.second << ")" << std::endl;
		std::cout << facing;
	}


};

int main() {
	//Declaring inputs for use
	int path_vanish;
	std::string commands;
	int moves;
	char ch;

	//Now onto inputting
	std::string str;
	std::stringstream ss;

	std::getline(std::cin, str);
	ss << str;
	ss >> path_vanish;
	ss >> commands;
	ss >> moves;

	//Initialise game
	Game game;
	game.coordinatesDriver();
	game.facingDriver();
	game.pathDriver(path_vanish);

	for (int i = 0; i < moves; i++) {
		for (int y = 0; y < commands.size(); y++) {
			if (game.endProgramBool == true) {
				game.printCurrent();
				return 0;
			}
			if (commands[y] == 'F') {
				ch = 'F';
				game.changeFace(ch);
			} if (commands[y] == 'L') {
				ch = 'L';
				game.changeFace(ch);
			} if (commands[y] == 'R') {
				ch = 'R';
				game.changeFace(ch);
			}
		}

	}
	game.printCurrent();
	

	return 0;
}
