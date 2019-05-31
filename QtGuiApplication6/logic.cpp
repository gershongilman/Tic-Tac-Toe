#include<logic.h>
using namespace std;

logic::logic() {
	b_done.resize(3);
	b_type.resize(3);
	for (int i = 0; i < 3; i++) {
		b_done[i].resize(3);
		b_type[i].resize(3);
	}

	reset();
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

// assume (i0,j0) is on the border
bool logic::checkLine(int i0, int j0, int di, int dj) const 
{
	int val = b_type[i0][j0];
	if (val == 0)
		return false;

	int numSame = 0;
	for (int k = 0; k < 3; k++) {
		if (b_type[i0 + k * di][j0 + k * dj] == val)
			numSame++;
	}
	return (numSame == 3);
}




bool logic::gameFinished() {
	int numRow = 0;

	//horizontal
	for (int i = 0; i < 3; i++) {
		if (checkLine(i, 0, 0, 1))
			return true;
	}

	//vertical
	for (int i = 0; i < 3; i++) {
		if (checkLine(0, i, 1, 0))
			return true;
	}

    //diagonal 1
	if (checkLine(0, 0, 1, 1))
			return true;
	//diagonal 2
	if (checkLine(0, 2, 1, -1))
		return true;

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