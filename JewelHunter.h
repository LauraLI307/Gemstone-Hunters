#pragma once
#include<iostream>
#include"Board.h"
#include"Adventurer.h"
using std::string;

class JewelHunter :public Adventurer {
public:
	JewelHunter(string t);
	void getInputs(string prompt, int& y, int& x, char& dir);
	virtual int hunt(Board& board);
	virtual string info();
};
