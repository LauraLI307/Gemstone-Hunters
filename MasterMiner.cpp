
#include<iostream>
#include "MasterMiner.h"
using namespace std;

MasterMiner::MasterMiner(string t):JewelHunter(t){
	setCapacity(Board::H*Board::W);
}

void MasterMiner::getInputs(string prompt, char& swap, int& r1, int& r2) {
	bool success = false;
	while (!success) {
		cout << prompt;
		cin >> swap;
		if (swap != 'y' && swap != 'n') {
			cout << "Invalid input!" << endl;
			continue;
		}
		if (swap == 'n') {
			return;
		}
		if (!getInt(r1)) {
			continue;
		}
		if (!getInt(r2)) {
			continue;
		}
		success = true;
	}
}

int MasterMiner::hunt(Board& board){
	return JewelHunter::hunt(board);
}

void MasterMiner::swapRows(Board& board) {
	char swap;
	int r1, r2;
	getInputs("Swap rows? ", swap, r1, r2);
	if (swap == 'y') {
		board.swapRows(r1, r2);
	}
}

string MasterMiner::info() {
	string s;
	s = getTeam() + ": MasterMiner";
	return s;
}
