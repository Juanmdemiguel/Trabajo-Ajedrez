#pragma once
#include "Piece.h"
#include "Model.h"

class Bishop: public piece
{
public:
//Constructor
	Bishop(Punto2D pos, bool c, int d) : piece(pos, c, d) { tipo = BISHOP; }
	void getHorizontal(Punto2D pos, int reach);
};

