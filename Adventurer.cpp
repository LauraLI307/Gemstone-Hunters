
#include<iostream>
#include "Adventurer.h"
using namespace std;

Adventurer::Adventurer(string t) :Hunter(t),capacity(3) {}

int Adventurer::getCapacity() {
	return capacity;
}

void Adventurer::setCapacity(int cap) {
	capacity = cap;
}

void Adventurer::getInputs(string prompt, int& y, int& x) {
	bool success = false;
	while (!success) {
		cout << prompt;
		if (!getInt(y)) {
			continue;
		}
		if (!getInt(x)) {
			continue;
		}
		success = true;
	}
}

int Adventurer::hunt(Board& board) {
	int x, y;
	getInputs("Enter(y,x): ", y, x);
	return board.wipeLine(y, x, getCapacity(), false);
}

string Adventurer::info(){
	string s;
	s = getTeam()+": Adventurer, capacity: 3";
	return s;
}
