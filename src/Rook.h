#pragma once
#include "Piece.h"
#include "Model.h"

class Rook : public piece
{
public:
//Constructor
	Rook(Punto2D pos, bool c, int t, int v) : piece(pos, c, t, v) { tipo = ROOK; }
	void getPosibles(Punto2D pos, Board& tablero);
};

