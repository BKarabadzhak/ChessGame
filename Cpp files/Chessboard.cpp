#include "stdafx.h"
#include "Chessboard.h"
#include "SetColor.h"
#include <conio.h>
#include <iostream>

#define COUNT_OF_PLAYER 2
#define FIRST_PLAYER 0
#define SECOND_PLAYER 1
#define LENGTH_OF_CHESSBOARD 8
#define WIDTH_OF_CHESSBOARD 8
#define FIRST_OCCUPIED_LINE_FOR_FIRST_PLAYER 6
#define SECOND_OCCUPIED_LINE_FOR_FIRST_PLAYER 7
#define FIRST_OCCUPIED_LINE_FOR_SECOND_PLAYER 1
#define SECOND_OCCUPIED_LINE_FOR_SECOND_PLAYER 0
#define NAME_PAWN 'P'
#define NAME_KNIGHT 'k'
#define SPACE_CODE 32
#define ENTER_CODE 13
#define UP_ARROW 72
#define DOWN_ARROW 80
#define LEFT_ARROW 75
#define RIGHT_ARROW 77
#define BLACK_COLOR 0
#define BLUE_COLOR 1
#define LIGHT_BLUE_COLOR 9
#define LIGHT_MAGENTA_COLOR 13
#define WHITE_COLOR 15
#define PLACEMENT_OF_KING 12

Chessboard::Chessboard(Player& pl1, Player& pl2) : length(LENGTH_OF_CHESSBOARD), width(WIDTH_OF_CHESSBOARD)
{
	player = new Player[COUNT_OF_PLAYER];
	player[FIRST_PLAYER] = pl1;
	player[SECOND_PLAYER] = pl2;

	chessboard_square = new bool*[length];
	for (int i = 0; i < length; i++) {
		chessboard_square[i] = new bool[length];
		for (int j = 0; j < length; j++) {
			if (i == FIRST_OCCUPIED_LINE_FOR_FIRST_PLAYER || i == SECOND_OCCUPIED_LINE_FOR_FIRST_PLAYER ||
				i == FIRST_OCCUPIED_LINE_FOR_SECOND_PLAYER || i == SECOND_OCCUPIED_LINE_FOR_SECOND_PLAYER)
				chessboard_square[i][j] = false;
			else
				chessboard_square[i][j] = true;
		}
	}
}

bool Chessboard::isFree(int _x, int _y) { return chessboard_square[_y][_x]; }

void Chessboard::makeItFree(int _x, int _y) { chessboard_square[_y][_x] = true; }

void Chessboard::makeItOccupied(int _x, int _y) { chessboard_square[_y][_x] = false; }

bool Chessboard::continueGame() { return (player[FIRST_PLAYER].pb[PLACEMENT_OF_KING]->GetAvailability() && 
	player[SECOND_PLAYER].pb[PLACEMENT_OF_KING]->GetAvailability()) ? true : false; }

Player& Chessboard::GetFirstPlayer() { return player[FIRST_PLAYER]; }
Player& Chessboard::GetSecondPlayer() { return player[SECOND_PLAYER]; }

Player& Chessboard::changePlayer(int i) { return i % 2 == 0 ? player[FIRST_PLAYER] : player[SECOND_PLAYER]; }

bool Chessboard::correctMoveHelper(Player _pl, PieceBase* _pb, int finish_x, int finish_y)
{
	int start_x = _pb->GetX();
	int start_y = _pb->GetY();

	if (_pb->GetName() == NAME_PAWN) {
		if ((start_x != finish_x && start_y != finish_y && _pl.findPieces(finish_x, finish_y) == 0 && isFree(finish_x, finish_y)) ||
			start_x == finish_x && start_y != finish_y && _pl.findPieces(finish_x, finish_y) == 0 && !isFree(finish_x, finish_y))
			return false;
		else
			return true;
	}

	else if (_pb->GetName() == NAME_KNIGHT)
		return true;

	else if (start_x == finish_x && start_y == finish_y)
		return false;

	else if (start_x == finish_x && start_y > finish_y) {
		for (int i = start_y - 1; i > finish_y; i--)
		{
			if (!isFree(start_x, i))
				return false;
		}
	}

	else if (start_x == finish_x && start_y < finish_y)
	{
		for (int i = start_y + 1; i < finish_y; i++) {
			if (!isFree(start_x, i))
				return false;
		}
	}

	else if (start_y == finish_y && finish_x > start_x)		
	{
		for (int i = start_x + 1; i < finish_x; i++) {
			if (!isFree(i, start_y))
				return false;
		}
	}

	else if (start_y == finish_y && finish_x < start_x)		
	{
		for (int i = start_x - 1; i > finish_x; i--) {
			if (!isFree(i, start_y))
				return false;
		}
	}

	else if (finish_x > start_x && finish_y < start_y)		
	{
		for (int i = start_x + 1, j = start_y - 1; i < finish_x, j > finish_y; i++, j--) {
			if (!isFree(i, j))
				return false;
		}
	}

	else if (start_x > finish_x && finish_y < start_y)		
	{
		for (int i = start_x - 1, j = start_y - 1; i > finish_x, j > finish_y; i--, j--) {
			if (!isFree(i, j))
				return false;
		}
	}

	else if (start_x > finish_x && finish_y > start_y)		
	{
		for (int i = start_x - 1, j = start_y + 1; i > finish_x, j < finish_y; i--, j++) {
			if (!isFree(i, j))
				return false;
		}
	}

	else if (finish_x > start_x && finish_y > start_y)		
	{
		for (int i = start_x + 1, j = start_y + 1; i < finish_x, j < finish_y; i++, j++) {
			if (!isFree(i, j))
				return false;
		}
	}

	return true;
}

void Chessboard::printHelper1(PieceBase*& pb, int b, int a, int j, int i)
{
	if (isFree(j, i)) {
		SetColor(BLACK_COLOR, LIGHT_BLUE_COLOR);
		std::cout << ' ';
		SetColor(BLACK_COLOR, WHITE_COLOR);
		std::cout << ' ';
	}
	else {
		pb = player[FIRST_PLAYER].findPieces(b, a);
		if (pb != 0) { 
			SetColor(BLACK_COLOR, LIGHT_BLUE_COLOR);
			std::cout << ' ';
			SetColor(LIGHT_MAGENTA_COLOR, WHITE_COLOR);
			std::cout << pb->GetName();
		}
		else { 
			pb = player[SECOND_PLAYER].findPieces(b, a);
			SetColor(BLACK_COLOR, LIGHT_BLUE_COLOR);
			std::cout << ' ';
			SetColor(BLUE_COLOR, WHITE_COLOR);
			std::cout << pb->GetName();
		}
	}
}

void Chessboard::printHelper2(PieceBase*& pb, int b, int a, int j, int i)
{
	if (isFree(j, i)) {
		SetColor(BLACK_COLOR, WHITE_COLOR);
		std::cout << "  ";
	}
	else {
		PieceBase* pb;
		pb = player[FIRST_PLAYER].findPieces(j, i);
		if (pb != 0) {
			SetColor(BLACK_COLOR, WHITE_COLOR);
			std::cout << ' ';
			SetColor(LIGHT_MAGENTA_COLOR, WHITE_COLOR);
			std::cout << pb->GetName();
		}
		else { 
			pb = player[SECOND_PLAYER].findPieces(j, i);
			SetColor(BLACK_COLOR, WHITE_COLOR);
			std::cout << ' ';
			SetColor(BLUE_COLOR, WHITE_COLOR);
			std::cout << pb->GetName();
		}
	}
}

void Chessboard::printHelper3(PieceBase*& pb, int b, int a, int j, int i)
{
	if (isFree(j, i)) {
		SetColor(BLACK_COLOR, LIGHT_BLUE_COLOR);
		std::cout << ' ';
		SetColor(BLACK_COLOR, BLACK_COLOR);
		std::cout << ' ';
	}
	else {
		PieceBase* pb;
		pb = player[FIRST_PLAYER].findPieces(b, a);
		if (pb != 0) {  
			SetColor(BLACK_COLOR, LIGHT_BLUE_COLOR);
			std::cout << ' ';
			SetColor(LIGHT_MAGENTA_COLOR, BLACK_COLOR);
			std::cout << pb->GetName();
		}
		else { 
			pb = player[SECOND_PLAYER].findPieces(b, a);
			SetColor(BLACK_COLOR, LIGHT_BLUE_COLOR);
			std::cout << ' ';
			SetColor(BLUE_COLOR, BLACK_COLOR);
			std::cout << pb->GetName();
		}
	}
}

void Chessboard::printHelper4(PieceBase*& pb, int b, int a, int j, int i)
{
	if (isFree(j, i)) {
		std::cout << "  ";
		SetColor(WHITE_COLOR, BLACK_COLOR);
	}
	else {
		PieceBase* pb;
		pb = player[FIRST_PLAYER].findPieces(j, i);
		if (pb != 0) {  
			SetColor(BLACK_COLOR, BLACK_COLOR);
			std::cout << ' ';
			SetColor(LIGHT_MAGENTA_COLOR, BLACK_COLOR);
			std::cout << pb->GetName();
		}
		else { 
			pb = player[SECOND_PLAYER].findPieces(j, i);
			SetColor(BLACK_COLOR, BLACK_COLOR);
			std::cout << ' ';
			SetColor(BLUE_COLOR, BLACK_COLOR);
			std::cout << pb->GetName();
		}
	}
}

void Chessboard::print(int& q, int& w, int error)
{
	int a = 0, b = 0, i, j, z = 1;

	while (z != SPACE_CODE)	
	{
		if (z == ENTER_CODE) { q = b, w = a; return; }

		if (z == UP_ARROW) { 
			if (a == 0)
				a = 7;
			else
				a--;
		}
		if (z == DOWN_ARROW) { 
			if (a == 7)
				a = 0;
			else
				a++;
		}
		if (z == LEFT_ARROW) { 
			if (b == 0)
				b = 7;
			else
				b--;
		}
		if (z == RIGHT_ARROW) { 
			if (b == 7)
				b = 0;
			else
				b++;
		}
		system("cls");

		PieceBase* pb; 

		for (i = 0; i < WIDTH_OF_CHESSBOARD; i++)
		{
			for (j = 0; j < LENGTH_OF_CHESSBOARD; j++)
			{
				pb = nullptr;
				if (((j + i) % 2) == 0 && i == a && j == b)  
					printHelper1(pb, b, a, j, i);

				else if (((j + i) % 2) == 0)  
					printHelper2(pb, b, a, j, i);

				else if (((j + i) % 2) == 1 && i == a && j == b) 
					printHelper3(pb, b, a, j, i);

				else if (((j + i) % 2) == 1)  
					printHelper4(pb, b, a, j, i);

				SetColor(WHITE_COLOR, BLACK_COLOR);
			}
			std::cout << std::endl;
		}

		if (error == 0)
			std::cout << std::endl << "Error running. Choose a new piece and place to move.";

		if (error == 2)
			std::cout << std::endl << "Error selecting a shape. Choose your piece";

		z = _getch();
	}
}

Chessboard::~Chessboard() {
	for (int i = 0; i < WIDTH_OF_CHESSBOARD; i++)
		delete[]chessboard_square[i];
	delete[]chessboard_square;

	delete[]player;
}