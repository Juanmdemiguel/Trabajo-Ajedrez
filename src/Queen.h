#pragma once
#include "Piece.h"
#include "Model.h"

class Queen: public piece
{
public:
//Constructor
	Queen(Punto2D pos, bool c, int d) : piece(pos, c, d) { tipo = QUEEN; }
	void getHorizontal(Punto2D pos, int reach);
};

