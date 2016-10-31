#include"ChessBoard.h"
#include "TicTacToe.h"
int main() {
	while (1) {
		TicTacToe game;
		game.start();
		cout << "play again(Y or y):" << endl;
		char c;
		cin >> c;
		if (c != 'y'&&c !='Y') 
			break;
	}
}