#pragma once
#include <vector>
#include <iostream>
using namespace std;
class tictactoe
{
private:
	vector<vector<char>> board{ {'-','-','-'}, {'-','-','-'}, {'-','-','-'} };
public:
	void input(int col, int row, char inp) {
		board[col][row] = inp;//cos fuck 0
	}
	void print() {
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				cout << board[j][i];
				cout << " ";
			}
			cout << endl;
		}
	}
	bool checkWin(char c) {
		if (board[0][0] == c && board[1][0] == c && board[2][0] == c)return true;
		else if (board[0][1] == c && board[2][1] == c && board[2][1] == c)return true;
		else if (board[0][2] == c && board[2][2] == c && board[2][2] == c)return true;

		else if (board[0][0] == c && board[0][1] == c && board[0][2] == c)return true;
		else if (board[1][0] == c && board[1][1] == c && board[1][2] == c)return true;
		else if (board[2][0] == c && board[2][1] == c && board[2][2] == c)return true;

		else if (board[0][0] == c && board[1][1] == c && board[2][2] == c)return true;
		else if (board[2][0] == c && board[1][1] == c && board[0][2] == c)return true;
		else return false;
	}

};

