#ifndef PIECES_H
#define PIECES_H
#include "PieceBase.h"

class King : public PieceBase 
{
public:
	King(char, char, int, int, bool);
	bool correctMove(int, int) override;
};

class Queen : public PieceBase
{
public:
	Queen(char, char, int, int, bool);
	bool correctMove(int, int) override;
};

class Bishop : public PieceBase		
{
public:
	Bishop(char, char, int, int, bool);
	bool correctMove(int, int) override;
};

class Knight : public PieceBase		
{
public:
	Knight(char, char, int, int, bool);
	bool correctMove(int, int) override;
};

class Rook : public PieceBase		
{
public:
	Rook(char, char, int, int, bool);
	bool correctMove(int, int) override;
};

class Pawn : public PieceBase		
{
	int axisSecondLine;	
public:
	Pawn(char, char, int, int, bool, int);
	bool correctMove(int, int) override;
	int& GetAxisSecondLine();
};

#endif 