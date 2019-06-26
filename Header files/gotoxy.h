#ifndef GOTOXY_H
#define GOTOXY_H
#include <Windows.h>

void gotoxy(short x, short y)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { x, y };
	SetConsoleCursorPosition(hStdOut, coord);
}

#endif