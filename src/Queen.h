#pragma once
#include "Piece.h"
#include "Model.h"

class Queen: public piece
{
public:
	Queen(Punto2D pos, bool c, int d) : piece(pos, c, "resources/model/Queen.obj", d) {}
};

