#ifndef PIECEBASE_H
#define PIECEBASE_H

class PieceBase {
	char name;
	char colour;
	int current_axis_x; 
	int current_axis_y;
	bool availability; 
public:
	PieceBase(char, char, int, int, bool);
	void removeFromChessboard();
	bool changeXY(int, int);
	void SetX(int);
	void SetY(int);
	int& GetX();
	int& GetY();
	char& GetColour();
	bool& GetAvailability();
	char& GetName();
	virtual bool correctMove(int, int) = 0; 
};

#endif