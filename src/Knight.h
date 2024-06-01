#pragma once
#include "Piece.h"
#include "Model.h"

class Knight: public piece
{
public:
//Constructor
	Knight(Punto2D pos, bool c, int d) : piece(pos, c, d) { tipo = KNIGHT; }
	void getHorizontal(Punto2D pos, int reach);
};