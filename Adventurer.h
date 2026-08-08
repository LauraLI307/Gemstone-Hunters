#pragma once
#include<iostream>
#include "Board.h"
#include "Hunter.h"
using std::string;

class Adventurer :public Hunter {
public:
	Adventurer(string t);
	int getCapacity();
	void setCapacity(int cap);
	void getInputs(string prompt, int& y, int& x);
	virtual int hunt(Board& board);
	virtual string info();
private:
	int capacity;
};
