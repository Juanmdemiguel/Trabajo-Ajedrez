#pragma once
#include "Piece.h"
#include "Model.h"

class Queen: public piece
{
public:
//Constructor
	Queen(Punto2D pos, bool c, int t, int v) : piece(pos, c, t, v) { tipo = QUEEN; }
	void getPosibles(Punto2D pos, Board& tablero);
};

