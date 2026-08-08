#pragma once
#include<iostream>
using std::string;

class Board
{
public:
	static const int W = 8; //board width
	static const int H = 8; //board height
	Board(const string& filename);
	void print() const;
	int wipeLine(int y, int x, int cap, bool vertical = false);
	void swapRows(int r1, int r2);
	int getStones() const;
private:
	int stones;
	char cells[H][W];
	void loadFromFile(const string& filename);
};