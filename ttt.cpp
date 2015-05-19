#include <iostream>
#include <iomanip>
#include "ttt.h"

using namespace std;

TicTacToe::TicTacToe(){

     for (int i = 0; i < 3; ++i)
    {
	    for (int j = 0; j < 3 ; ++j)
	    {
		    board[i][j] = ' '; //tüm arrayı boş initilaze ettim
	    }
    }
}

bool TicTacToe::validMove(int row, int column){//row ve column un 0 2 arası olmasını kontrol et (bool deger döndürür)

	return row >= 0 && row < 3  && column >= 0 && column < 3 && board[row][column]== ' '; //if else ile =true vs demene gerek yok func tipinden dolayı, bunu düsünmeyi unutma!
}

TicTacToe::Status TicTacToe::gameStatus(){

//capraz kazandı mı kontrol
	if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[1][1])//sag üstten sol alta
	{
		return WIN;
	}
	else if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[0][2] == board[2][0])//sol üstten sag alta
	{
		return WIN;
	}
//satır kazandı mı kontrol et
	for (int i = 0; i < 3; ++i)
	{
	    if ( board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][0] == board[i][2])
	    {
		     return WIN;
	    }
	}
//sutun kazandı mı kontrol et 
	for (int i = 0; i < 3; ++i)
	{
	    if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[0][i] == board[2][i])
	    {
		     return WIN;
	    }
	}
//oyun bitti mi kontrol et(contiune icin)
	for (int row = 0; row < 3; row++)
	{
		for (int column = 0; column < 3; column++)
		{
			board[row][column] = ' ';
		}

		
		return CONTINUE;
	}
return DRAW;
}

void TicTacToe::printBoard(){



	/*cout << endl;
	cout << "      0    1    2   "<<endl;
	cout << "        |     |     " << endl;
	cout <<" 0 " << "   "  << "  |  " << "   |  " << endl;

	cout << "'   _____|_____|_____" << endl;
	cout << "        |     |     " << endl;

	cout << " 1 " << "   "  << "  |  "  << "   |  "  << endl;

	cout << "   _____|_____|_____" << endl;
	cout << "        |     |     " << endl;

	cout <<" 2 " << "   "  << "  |  " << "   |  " << endl;

	cout << "        |     |     " << endl << endl;*/

	cout << "   0    1    2"<<endl;

	for (int row = 0; row < 3; ++row)
	{
		cout << row;

		for (int column = 0; column < 3 ; ++column)
		{
			cout << setw(3) << static_cast<char> (board[row][column]);
			if ( column != 2)
			{
				/* code */cout << "| ";
			}
        }
			if ( row != 2)
			{
				/* code */ cout << endl << "____|____|____" << endl<<"    |    |    "<<endl;
			}
		
	}

	cout << endl;

}

void TicTacToe::makeMove(){
	printBoard();
	while(true)
	{
	if (xoMove('X'))

		break;

	else if(xoMove('O'))

		break;
	}
}

bool TicTacToe::xoMove(int sembol){//yukarıdaki x i veya o yu sembol olarak alıyor

	int x,y;
	do
	{
		cout << "Player " << static_cast <char> (sembol) << " enter move: ";
		cin >> x >> y;
		cout << endl;

	} while (!validMove(x,y));//koordinatların 0 1 2 ye uygun olup olmadıgını kontrol edip calıstırıyor

	board[x][y] = sembol;

	printBoard();

	Status xoStatus = gameStatus();//gameStatusten gelen sonucu yeni bir objeye attı

	if ( xoStatus == WIN)
	{
		cout << "Player " << static_cast <char> (sembol) << " wins!" << endl << endl;
		return true;
	}
	else if ( xoStatus == DRAW)
	{
		cout << "Game is a draw." << endl;
		return true;
	}
	else
		return false;
}
