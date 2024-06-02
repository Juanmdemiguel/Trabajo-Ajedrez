#pragma once
#include "Piece.h"
#include "Model.h"

class King : public piece
{
public:
//Constructor
	King(Punto2D pos, bool c, int d) : piece(pos, c, d) { tipo = KING; }
	void getPosibles(Punto2D pos, int reach, Board& tablero);
};