#pragma once
#include "Piece.h"
#include "Model.h"

class Bishop: public piece
{
public:
//Constructor
	Bishop(Punto2D pos, bool c, int t, int v) : piece(pos, c, t, v) { tipo = BISHOP; }
	void getPosibles(Board& tablero);

};

