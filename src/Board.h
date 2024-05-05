#pragma once

#include "Tile.h"

#define col 10
#define fil 8


class Board
{
	Tile board[fil][col];
	char WhiteTile[50];
	char BlackTile[50];
	char SelecTile[50];

public:
//Constructor de Board
	Board();
//Métodos de Board
	void dibuja();
	Tile& getTile(Punto2D pos);
	void detectpieza(Punto2D esfera);
	void initPath();
	void getDiagonal(Punto2D pos, int reach = 10);
//Amigos
	friend class Game;
};

