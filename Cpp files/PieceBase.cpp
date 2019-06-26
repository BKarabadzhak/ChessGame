#include "stdafx.h"
#include "PieceBase.h"

PieceBase::PieceBase(char _name, char _colour, int _x, int _y, bool _availability)
{
	name = _name;
	colour = _colour;
	current_axis_x = _x;
	current_axis_y = _y;
	availability = _availability;
}

void PieceBase::removeFromChessboard() { availability = false; }

bool PieceBase::changeXY(int _x, int _y)
{
	if (GetAvailability()) {
		if (correctMove(_x, _y)) {
			SetX(_x);
			SetY(_y);
			return true;
		}
		else 
			return false;
	}
	else
		return false;
}

void PieceBase::SetX(int _x) { current_axis_x = _x; }

void PieceBase::SetY(int _y) { current_axis_y = _y; }

int& PieceBase::GetX() { return current_axis_x; }

int& PieceBase::GetY() { return current_axis_y; }

char& PieceBase::GetColour() { return colour; }

bool& PieceBase::GetAvailability() { return availability; }

char& PieceBase::GetName() { return name; }