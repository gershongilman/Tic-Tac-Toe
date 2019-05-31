#include<logic.h>
using namespace std;

logic::logic() {
	b_done.resize(3);
	b_type.resize(3);
	for (int i = 0; i < 3; i++) {
		b_done[i].resize(3);
		b_type[i].resize(3);
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			b_done[i][j] = false;
			b_type[i][j] = 0;
		}
	}
}

void logic::move(int row, int col, int type) {
	b_type[row][col] = type;
}
void logic::made(int row, int col) {
	b_done[row][col] = true;
}

bool logic::legal(int row, int col) {
	if (b_done[row][col] == false) {
		made(row, col);
		return true;
	}
	return false;
}

bool logic::gameFinished() {
	int numRow = 0;

	//horizontal
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if ((j + 1 < 3) && (b_type[i][j] == b_type[i][j + 1])) {
				numRow += 1;
				if (numRow == 2 && b_type[i][j] > 0) {
					return true;
				}
			}
			else {
				numRow = 0;
			}
		}
	}
	//vertical
	numRow = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i + 1 < 3 && b_type[i][j] == b_type[i + 1][j]) {
				numRow += 1;
				if (numRow == 2 && b_type[i][j] > 0) {
					return true;
				}
			}
			else {
				numRow = 0;
			}
		}
	}

	numRow = 0;
	//diagonal top left to bottom right
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if ((i + 1 < 3 && j + 1 < 3) && b_type[i][j] == b_type[i + 1][j + 1]) {
				numRow += 1;
				if (numRow == 2 && b_type[i][j] != 0) {
					return true;
				}
			}
			else {
				numRow = 0;
			}
		}
	}
	
	//bottom left to top right
	/*
	numRow = 0;
	for (int i = 3; i < 3; i--) {
		for (int j = 0; j > 0; j++) {
			if ((i - 1 > 0 && j + 1 < 3) && b_type[i][j] == b_type[i - 1][j + 1]) {
				numRow += 1;
				if (numRow == 2 && b_type[i][j] > 0) {
					return true;
				}
			}
			else {
				numRow = 0;
			}
		}
	}
	*/
		return false;
}


void logic::reset() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			b_done[i][j] = false;
			b_type[i][j] = 0;
		}
	}
}