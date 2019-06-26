#ifndef PLAYER_H
#define PLAYER_H
#include "vector_t.h"
#include "PieceBase.h"
#include "Pieces.h"

class Player {
	int startAxisX;
	int startAxisY;
	int finishAxisX;
	int finishAxisY;
	int countOfAvailablePieces;
	char colour;
	Vector<PieceBase*> pb;	
public:
	Player();
	Player(const Player&);
	Player& operator=(const Player&);
	int& GetCountOfAvailablePieces();
	PieceBase* findPieces(int, int); 
	void addKing(char, char, int, int, bool);
	void addQueen(char, char, int, int, bool);
	void addBishop(char, char, int, int, bool);
	void addKnight(char, char, int, int, bool);
	void addRook(char, char, int, int, bool);
	void addPawn(char, char, int, int, bool, int);	
	void SetColour(char);
	char& GetColour();
	friend class Chessboard;
};

#endif