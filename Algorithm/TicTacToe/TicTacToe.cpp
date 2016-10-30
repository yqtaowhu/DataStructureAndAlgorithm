#include "TicTacToe.h"
void TicTacToe::start() {
	Role firstPlace = chooseFirstPlace();
	if (firstPlace == Comp) {  // Choose computer to be the first
		compPlace();
	}
	while (1) {
		board.print();
		if (handleGameOver()) break;
		humanPlace();
		board.print();
		if (handleGameOver()) break;
		compPlace();
	}
}
Role TicTacToe::chooseFirstPlace() {
	int choose;
	while (1) {
		cout << "who will place first" << endl;
		cout << "0 : human first " << endl;
		cout << "1 : computer first" << endl;
		cin >> choose;
		if (choose == 0 || choose == 1) {
			cout << endl;
			break;
		}
		else
			cout << "error,please enter again" << endl;
	}
	return (Role)choose;
}
//
void TicTacToe::humanPlace() {
	int pos = getPlacePosition();
	board.placeHuman(pos);
	cout << "Your choice:" << endl;
}
//
int TicTacToe::getPlacePosition() {
	int m, n,pos;
	while (1) {
		cout << "It is your turn, please input where you want :" << endl;
		cout << "for example: 2 2 mean you want to add position 2 row,2 col:" << endl;
		cin >> m >> n;
		if (m < 0 || m>3 || n < 0 || n>3)
			cout << "error,please input again:" << endl;
		else {
			pos = (m - 1) * 3 + n - 1;
			if (board.isEmpty(pos))
				break;
			else
				cout << "error,please input again:" << endl;
		}
	}
	return pos;
}
//
void TicTacToe::compPlace() {
	int bestMove = getBestMove();
	board.placeComp(bestMove);
	cout << "the computer choice is: " << endl;
}
int TicTacToe::getBestMove() {
	int bestMove = 0, value = 0;
	findCompMove(bestMove,value,HumanWin, CompWin);
	return bestMove;
}
void TicTacToe::findCompMove(int& bestMove,int &value, int alpha, int beta) {
	if (board.isFull())
		value = Draw;
	else if (board.immediateComWin(bestMove))
		value = CompWin;
	else {
		value = alpha;
		for (int i = 0; i < GridNuber&&value < beta; i++) {
			if (board.isEmpty(i)) {
				board.placeComp(i);
				int tmp = -1, response = -1;  // Tmp is useless
				findHumanMove(tmp, response, value, beta);
				board.unPlace(i);
				if (response > value) {
					value = response;
					bestMove = i;
				}
			}
		}
	}
}

void TicTacToe::findHumanMove(int& bestMove,int & value, int alpha, int beta) {
	if (board.isFull())
		value=Draw;
	else if (board.immediateHumanWin(bestMove)){
		value=HumanWin;
	}
	else {
		value = beta; 
		for (int i = 0; i < GridNuber&&value>alpha; i++) {
			if (board.isEmpty(i)) {
				board.placeHuman(i);
				int tmp = -1, response = -1;  // Tmp is useless
				findCompMove(tmp, response, alpha, value);
				board.unPlace(i);
				if (response <value) {
					value = response;
					bestMove = i;
				}
			}
		}
	}
}
//
bool TicTacToe::gameIsOver(bool &draw, Role &win) {
	if (board.canWin(Comp_Char)) {
		win =Comp ;
		draw = false;
		return true;
	}
	else if (board.canWin(Human_Char)) {
		win = Human;
		draw = false;
		return true;
	}
	else if (board.isFull()) {
		draw = true;
		return true;
	}
	else {
		return false;
	}
}

bool TicTacToe::handleGameOver()  {
	bool draw = false;
	Role whoWin = Human;
	if (gameIsOver(draw, whoWin)) {
		if (draw) {
			cout << "Draw!" << endl;
		}
		else {
			if (whoWin == Comp) {
				cout << "You lose!" << endl;
			}
			else if (whoWin == Human) {
				cout << "Congratulations! You defeat the computer." << endl;
			}
		}
		return true;
	}
	else {
		return false;
	}
}