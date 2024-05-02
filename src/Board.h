#pragma once

#include "Tile.h"

#define col 10
#define fil 8


class Board
{
	Tile board[fil][col];

public:
//Constructor de Board
	Board();
//Métodos de Board
	void dibuja();
	Tile getTile(Punto2D pos);
};

