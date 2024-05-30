#pragma once
#include "Tile.h"
#define col 10
#define fil 8

class Board
{
	Tile board[fil][col];

public:
//Constructor
	Board();
//Métodos
	Tile& getTile(Punto2D pos);
	void dibuja();
	void detectpieza(Punto2D esfera);
	void getDiagonal(Punto2D pos, int reach = 10);
	void getHorizontal(Punto2D pos, int reach = 10);
//Amigos
};

