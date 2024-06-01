#pragma once
#include "Piece.h"
#include "Model.h"

class Rook : public piece
{
public:
//Constructor
	Rook(Punto2D pos, bool c, int d) : piece(pos, c, d) { tipo = ROOK; }
	void getHorizontal(Punto2D pos, int reach);
};

