#pragma once
#include "Piece.h"
#include "Model.h"

class Knight: public piece
{
public:
//Constructor
	Knight(Punto2D pos, bool c, int t, int v) : piece(pos, c, t, v) { tipo = KNIGHT; }
	void getPosibles(Board& tablero);
};