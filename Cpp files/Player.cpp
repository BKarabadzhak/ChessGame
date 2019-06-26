#include "stdafx.h"
#include "Player.h"

Player::Player() : startAxisX(0), startAxisY(0), finishAxisX(0), finishAxisY(0), countOfAvailablePieces(0), colour(' ') {}

Player::Player(const Player& p)
{
	startAxisX = p.startAxisX;
	startAxisY = p.startAxisY;
	finishAxisX = p.finishAxisX;
	finishAxisY = p.finishAxisY;
	countOfAvailablePieces = p.countOfAvailablePieces;
	colour = p.colour;
	pb = p.pb;
}

Player& Player::operator=(const Player& p)
{
	startAxisX = p.startAxisX;
	startAxisY = p.startAxisY;
	finishAxisX = p.finishAxisX;
	finishAxisY = p.finishAxisY;
	countOfAvailablePieces = p.countOfAvailablePieces;
	colour = p.colour;
	pb = p.pb;
	return *this;
}

int& Player::GetCountOfAvailablePieces() { return countOfAvailablePieces; }

PieceBase* Player::findPieces(int _x, int _y)
{
	for (int i = 0; i < pb.GetCount(); i++) {
		if (pb[i]->GetAvailability() && pb[i]->GetX() == _x && pb[i]->GetY() == _y)
			return pb[i];
	}
	return 0;
}

void Player::addKing(char _name, char _colour, int _x, int _y, bool _availability)
{
	pb.Add(new King(_name, _colour, _x, _y, _availability));
	countOfAvailablePieces++;
}

void Player::addQueen(char _name, char _colour, int _x, int _y, bool _availability)
{
	pb.Add(new Queen(_name, _colour, _x, _y, _availability));
	countOfAvailablePieces++;
}

void Player::addBishop(char _name, char _colour, int _x, int _y, bool _availability)
{
	pb.Add(new Bishop(_name, _colour, _x, _y, _availability));
	countOfAvailablePieces++;
}

void Player::addKnight(char _name, char _colour, int _x, int _y, bool _availability)
{
	pb.Add(new Knight(_name, _colour, _x, _y, _availability));
	countOfAvailablePieces++;
}

void Player::addRook(char _name, char _colour, int _x, int _y, bool _availability)
{
	pb.Add(new Rook(_name, _colour, _x, _y, _availability));
	countOfAvailablePieces++;
}

void Player::addPawn(char _name, char _colour, int _x, int _y, bool _availability, int _axis_second_line)
{
	pb.Add(new Pawn(_name, _colour, _x, _y, _availability, _axis_second_line));
	countOfAvailablePieces++;
}

void Player::SetColour(char _col) { colour = _col; }

char& Player::GetColour() { return colour; }