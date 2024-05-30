#pragma once
#include "Piece.h"
#include "Model.h"
class Pawn: public piece
{
	//Model pawn;
public:
	Pawn(Punto2D pos, bool c, int d) : piece(pos, c, d) { tipo = PAWN; }
};

