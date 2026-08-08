#pragma once
#include<iostream>
#include "Board.h"
using std::string;

class Hunter {
public:
	Hunter(string t);
	string getTeam();
	void setTeam(string t);
	bool getInt(int& num);
	virtual int hunt(Board& board) = 0;
	virtual string info();
private:
	string team;
};
