#include "stdafx.h"
#include <iostream>
#include "Chessboard.h"
#include "Player.h"
#include "gotoxy.h"

#define COUNT_OF_PLAYER 2
#define WHITE 'w'
#define BLACK 'b'
#define PLACEMENT_SECOND_LINE_FOR_PAWN_PLAYER_1 6
#define PLACEMENT_SECOND_LINE_FOR_PAWN_PLAYER_2 1
#define PLACEMENT_FIRST_LINE_FOR_PAWN_PLAYER_1 7
#define PLACEMENT_FIRST_LINE_FOR_PAWN_PLAYER_2 0
#define COUNT_PIECES_IN_LINE 8
#define FIRST_PLAYER 0
#define SECOND_PLAYER 1
#define NAME_OF_PAWN 'P'
#define NAME_OF_KING 'K'
#define NAME_OF_QUEEN 'Q'
#define NAME_OF_BISHOP 'b'
#define NAME_OF_KNIGHT 'k'
#define NAME_OF_ROOK 'L'
/* the first player is at the bottom of the chessboard, the second is at the top */

//Errors
#define ERR_0 0		//select the piece and place again
#define ERR_2 2		//choose your piece
#define ERR_3 3		//no error

void addPiecesForPlayers(Player* pl) {

	char arrColour[] = { WHITE, BLACK };

	int arrForPawn[] = { PLACEMENT_SECOND_LINE_FOR_PAWN_PLAYER_1, PLACEMENT_SECOND_LINE_FOR_PAWN_PLAYER_2 };
	int arrPlacementForOtherPieces[] = { PLACEMENT_FIRST_LINE_FOR_PAWN_PLAYER_1, PLACEMENT_FIRST_LINE_FOR_PAWN_PLAYER_2 };

	for (int i = 0; i < COUNT_OF_PLAYER; i++) {
		for (int j = 0; j < COUNT_PIECES_IN_LINE; j++) {
			pl[i].addPawn(NAME_OF_PAWN, arrColour[i], j, arrForPawn[i], true, arrForPawn[i]);
		}
		pl[i].addRook(NAME_OF_ROOK, arrColour[i], 0, arrPlacementForOtherPieces[i], true);
		pl[i].addKnight(NAME_OF_KNIGHT, arrColour[i], 1, arrPlacementForOtherPieces[i], true);
		pl[i].addBishop(NAME_OF_BISHOP, arrColour[i], 2, arrPlacementForOtherPieces[i], true);
		pl[i].addQueen(NAME_OF_QUEEN, arrColour[i], 3, arrPlacementForOtherPieces[i], true);
		pl[i].addKing(NAME_OF_KING, arrColour[i], 4, arrPlacementForOtherPieces[i], true);
		pl[i].addBishop(NAME_OF_BISHOP, arrColour[i], 5, arrPlacementForOtherPieces[i], true);
		pl[i].addKnight(NAME_OF_KNIGHT, arrColour[i], 6, arrPlacementForOtherPieces[i], true);
		pl[i].addRook(NAME_OF_ROOK, arrColour[i], 7, arrPlacementForOtherPieces[i], true);
	}
}

void Moving(Chessboard& cb, int& X, int& Y, Player player, Player* pl, PieceBase* p, bool& selectionResult) {

	if (cb.isFree(X, Y)) {
		if (cb.correctMoveHelper(player, p, X, Y)) {
			if (p->changeXY(X, Y) == true)
				selectionResult = true;
		}
	}

	else if (player.findPieces(X, Y) != 0) 
		selectionResult = false;

	else
	{
		if (cb.correctMoveHelper(player, p, X, Y)) {

			if (player.GetColour() == WHITE)
			{
				if (p->changeXY(X, Y) == true) {
					pl[SECOND_PLAYER].findPieces(X, Y)->removeFromChessboard();
					selectionResult = true;
				}
			}

			else
			{
				if (p->changeXY(X, Y) == true) {
					pl[FIRST_PLAYER].findPieces(X, Y)->removeFromChessboard();
					selectionResult = true;
				}
			}
		}
	}
}

int main()
{
	Player* pl = new Player[COUNT_OF_PLAYER];

	addPiecesForPlayers(pl);

	pl[FIRST_PLAYER].SetColour(WHITE);
	pl[SECOND_PLAYER].SetColour(BLACK);

	Chessboard cb(pl[FIRST_PLAYER], pl[SECOND_PLAYER]);

	PieceBase* p;
	Player player = pl[FIRST_PLAYER];
	bool selectionResult;

	int X, Y, i = 0, tmp1, tmp2, c;
	while (cb.continueGame())
	{
		selectionResult = false;

		X = 0, Y = 0, tmp1 = 0, tmp2 = 0, c = 0;

		while (!selectionResult) {
			if (c == 0)
				cb.print(X, Y, ERR_3); 
			else
				cb.print(X, Y, ERR_0); 

			p = player.findPieces(X, Y);
			while (p == 0) {
				cb.print(X, Y, ERR_2);
				p = player.findPieces(X, Y);
			}

			tmp1 = X;
			tmp2 = Y;

			cb.print(X, Y, ERR_3);

			Moving(cb, X, Y, player, pl, p, selectionResult);

			c++;
		}

		cb.makeItFree(tmp1, tmp2);
		cb.makeItOccupied(X, Y);

		i++;
		player = cb.changePlayer(i);
	}

	gotoxy(20, 5);
	std::cout << "Game finished";
}