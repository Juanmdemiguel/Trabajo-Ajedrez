#pragma once

#include "Tile.h"

#define col 10
#define fil 8
#define square 3

class Board
{
	Tile board[fil][col];

public:
//Constructor de Board
	Board();
//Métodos de Board
	void dibuja();
};

