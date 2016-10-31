#Objects : 
OBJS = main.o TicTacToe.o ChessBoard.o

#Complier:
CC=g++ -std=c++11

TicTacToe : $(OBJS)
	$(CC) -o TicTacToe $(OBJS)
main.o : main.cpp
	$(CC) -c main.cpp
TicTacToe.o : TicTacToe.cpp
	$(CC) -c TicTacToe.cpp
ChessBoard.o : ChessBoard.cpp
	$(CC) -c ChessBoard.cpp 
clear :
	rm $(OBJS)
run : 
	./TicTacToe 
