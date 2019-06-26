#include "stdafx.h"
#include "Pieces.h"
#include <stdlib.h>

#define WHITE_COLOR 'w'
#define BLACK_COLOR 'b'

King::King(char _name, char _colour, int _x, int _y, bool _availability) : PieceBase(_name, _colour, _x, _y, _availability) {  }

bool King::correctMove(int _finishAxisX, int _finishAxisY)
{
	return (((abs(GetX() - _finishAxisX) == 1) && ((GetY() - _finishAxisY) == 0)) ||
		((abs(GetY() - _finishAxisY) == 1) && ((GetX() - _finishAxisX) == 0)) ||
		((abs(GetX() - _finishAxisX) == 1) && (abs(GetY() - _finishAxisY) == 1))) ? true : false;
}

Queen::Queen(char _name, char _colour, int _x, int _y, bool _availability) : PieceBase(_name, _colour, _x, _y, _availability) {  }

bool Queen::correctMove(int _finishAxisX, int _finishAxisY)
{
	return ((GetX() == _finishAxisX) || (GetY() == _finishAxisY) ||
		(abs(GetX() - _finishAxisX) == abs(GetY() - _finishAxisY))) ? true : false;
}

Bishop::Bishop(char _name, char _colour, int _x, int _y, bool _availability) : PieceBase(_name, _colour, _x, _y, _availability) {  }

bool Bishop::correctMove(int _finishAxisX, int _finishAxisY)
{
	return (abs(GetX() - _finishAxisX) == abs(GetY() - _finishAxisY)) ? true : false;
}

Knight::Knight(char _name, char _colour, int _x, int _y, bool _availability) : PieceBase(_name, _colour, _x, _y, _availability) {  }

bool Knight::correctMove(int _finishAxisX, int _finishAxisY)
{
	return (abs(GetX() - _finishAxisX)*abs(GetY() - _finishAxisY) == 2) ? true : false;
}

Rook::Rook(char _name, char _colour, int _x, int _y, bool _availability) : PieceBase(_name, _colour, _x, _y, _availability) {  }

bool Rook::correctMove(int _finishAxisX, int _finishAxisY)
{
	return (GetX() == _finishAxisX || GetY() == _finishAxisY) ? true : false;
}

Pawn::Pawn(char _name, char _colour, int _x, int _y, bool _availability, int _axis_second_line) : PieceBase(_name, _colour, _x, _y, _availability)
{
	axisSecondLine = _axis_second_line;
}

bool Pawn::correctMove(int _finishAxisX, int _finishAxisY)
{
	char c = GetColour();

	return ((c == WHITE_COLOR && ((GetY() - _finishAxisY == 2 && GetY() == GetAxisSecondLine() && GetX() == _finishAxisX) ||
		((GetY() - _finishAxisY == 1 && GetX() == _finishAxisX) ||
		(abs(GetX() - _finishAxisX)) == GetY() - _finishAxisY && GetY() - _finishAxisY == 1))) ||
		c == BLACK_COLOR && ((_finishAxisY - GetY() == 2 && GetY() == GetAxisSecondLine() && GetX() == _finishAxisX) ||
		(_finishAxisY - GetY() == 1 && GetX() == _finishAxisX) ||
			(abs(GetX() - _finishAxisX) == _finishAxisY - GetY() && _finishAxisY - GetY() == 1))) ? true : false;
}

int& Pawn::GetAxisSecondLine() { return axisSecondLine; }