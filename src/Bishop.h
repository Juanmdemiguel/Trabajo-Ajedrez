#pragma once
#include "Piece.h"
#include "Model.h"

class Bishop: public piece
{
public:
	Bishop(Punto2D pos, bool c, int d) : piece(pos, c, d) { tipo = BISHOP; }
};

