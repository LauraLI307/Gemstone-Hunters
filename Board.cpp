#include<iostream>
#include"Board.h"
#include<fstream>
#include<cstdlib>
using namespace std;

using namespace std;

Board::Board(const string& filename) : stones(H* W),
cells{
	'A','B','B','B','B','B','B','B',
	'A','C','C','C','C','D','D','D',
	'A','E','E','E','B','E','C','B',
	'A','B','E','B','B','E','C','B',
	'A','B','E','D','D','E','C','B',
	'A','C','E','F','F','E','F','B',
	'A','D','A','B','B','E','C','B',
	'A','C','A','B','B','D','C','B'
}
{
	if (filename != "")
		loadFromFile(filename);
}

void Board::loadFromFile(const string& filename) {
	ifstream fin(filename);
	if (fin.fail()) {
		cout << "File could not be opened.";
		exit(1);
	}
	else {
		int number = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
                fin>>cell[i][j];
				number += 1;
			}
		}
	}
	fin.close();
}

// print the game board on the screen
void Board::print() const {
	cout << " ";
	for (int i = 0; i < W; i++)
		cout << " " << i;
	cout << endl;
	for (int i = 0; i < H; i++) {
		cout << i;
		for (int j = 0; j < W; j++) {
			cout << " " << cells[i][j];
		}
		cout << endl;
	}
}

int Board::wipeLine(int y, int x, int cap, bool vertical) {
	int score = 0;
	if (y < 0 || y >= H || x < 0 || x >= W || cells[y][x] == '.') {
		return 0;
	}
	if (vertical) {
		for (int i = y - 1; (i >= 0) && (i >= y - cap + 1); i--) {
			if (cells[i][x] == cells[y][x]) {
				cells[i][x] = '.';
				score++;
			}
			else {
				break;
			}
		}
		score++;
		if (score == cap) {
			cells[y][x] = '.';
			stones -= score;
			return score;
		}
		else if (score < cap) {
			for (int i = y + 1; i < H && score < cap; i++) {
				if (cells[i][x] == cells[y][x]) {
					cells[i][x] = '.';
					score++;
				}
				else {
					break;
				}
			}
		}
		cells[y][x] = '.';
		stones -= score;
		return score;
	}
	else {
		for (int i = x - 1; (i >= 0)&&(i >= x - cap + 1) ; i--) {
			if (cells[y][i] == cells[y][x]) {
				cells[y][i] = '.';
				score++;
			}
			else {
				break;
			}
		}
		score++;
		if (score == cap) {
			cells[y][x] = '.';
			stones -= score;
			return score;
		}
		else if (score < cap) {
			for (int i = x + 1;  i < W && score<cap; i++) {
				if (cells[y][i] == cells[y][x]) {
					cells[y][i] = '.';
					score++;
				}
			}
		}
		cells[y][x] = '.';
		stones = stones - score;
		return score;
	}
}

void Board::swapRows(int r1, int r2) {
	char tmp[W];
	for (int i = 0; i < W; i++) {
		tmp[i] = cells[r1][i];
	}
	for (int i = 0; i < W; i++) {
		cells[r1][i] = cells[r2][i];
	}
	for (int i = 0; i < W; i++) {
		cells[r2][i] = tmp[i];
	}
}

int Board::getStones() const {
	return stones;
}


