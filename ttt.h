#include <iostream>

using namespace std;

class TicTacToe
{
private:

	enum Status
	{
		WIN, DRAW, CONTINUE
	};

	int board[3][3] ;

public:
	TicTacToe();
	void makeMove();
	void printBoard();
	bool validMove(int, int);
	bool xoMove(int);
	Status gameStatus();
	
};
