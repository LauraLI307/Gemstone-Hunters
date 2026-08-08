#pragma once
#include<iostream>
#include "Board.h"
#include "JewelHunter.h"
using std::string;

class MasterMiner :public JewelHunter {
public:
	MasterMiner(string t);
	void getInputs(string prompt, char& swap, int& r1, int& r2);
	virtual int hunt(Board& board);
	void swapRows(Board& board);
	virtual string info();
};

