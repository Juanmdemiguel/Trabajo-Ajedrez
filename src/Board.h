#pragma once
#include "Tile.h"
#define col 10
#define fil 8

class Board
{
	Tile board[fil][col];
	int tematica{};

public:
//Constructor
	Board();
//Métodos
	Tile& getTile(Punto2D pos);
	void dibuja(bool tematica);
	void detectpieza(Punto2D esfera);
//Amigos
};

