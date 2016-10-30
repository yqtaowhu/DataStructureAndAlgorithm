#include"ChessBoard.h"
#include "TicTacToe.h"
int main() {
	TicTacToe game;
	while (1) {
		game.start();
		cout << "play again(Y or y):" << endl;
		char c;
		cin >> c;
		if (c != 'y'&&c !='Y') 
			break;
	}
}