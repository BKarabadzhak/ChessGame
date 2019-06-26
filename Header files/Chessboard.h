#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include "vector_t.h"
#include "Player.h"

class Chessboard {
	int length;
	int width;
	bool** chessboard_square;		
	Player* player;
public:
	Chessboard(Player&, Player&);
	~Chessboard();
	bool isFree(int, int);	
	void makeItFree(int, int);	
	void makeItOccupied(int, int);		
	bool continueGame();		
	Player& GetFirstPlayer();		
	Player& GetSecondPlayer();
	Player& changePlayer(int);
	bool correctMoveHelper(Player, PieceBase*, int, int);
	void print(int&, int&, int);
	void printHelper1(PieceBase*&, int, int, int, int);
	void printHelper2(PieceBase*&, int, int, int, int);
	void printHelper3(PieceBase*&, int, int, int, int);
	void printHelper4(PieceBase*&, int, int, int, int);
};

#endif