
#include<iostream>
#include "JewelHunter.h"
using namespace std;

JewelHunter::JewelHunter(string t) :Adventurer(t){
	setCapacity(6);
}

void JewelHunter::getInputs(string prompt, int& y, int& x, char& dir) {
	bool success = false;
	while (!success) {
		cout << prompt;
		if (!getInt(y)) {
			continue;
		}
		if (!getInt(x)) {
			continue;
		}
		cin >> dir;
		if (dir != 'h' && dir != 'v') {
			cout << "Invalid input for direction!" << endl;
			continue;
		}
		success = true;
	}
}

int JewelHunter::hunt(Board& board) {
	int y, x;
	char dir;
	getInputs("Enter(y,x,h/v): ", y, x, dir);
	if (dir == 'h') {
		return board.wipeLine(y, x, getCapacity(), false);
	}
	else if (dir == 'v') {
		return board.wipeLine(y, x, getCapacity(), true);
	}
}

string JewelHunter::info() {
	string s;
	s = getTeam() + ": JewelHunter, capacity: 6";
	return s;
}
