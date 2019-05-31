#pragma once

#include <vector>
using namespace std;

class logic {
public:
	logic();
	void move(int row, int col, int type);
	void made(int row, int col);
	bool legal(int row,int col);
	bool gameFinished();
	void reset();
private:
	bool checkLine(int i0, int j0, int di, int dj) const;
	vector<vector<int>> b_type;
	vector<vector<bool>> b_done; //is the move made in that square;
};