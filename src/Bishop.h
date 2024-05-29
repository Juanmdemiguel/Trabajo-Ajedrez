#pragma once
#include "Piece.h"
#include "Model.h"

class Bishop: public piece
{
	Model bishop;

public:
	Bishop(Punto2D pos, bool c, int d) : piece(pos, c, "resources/model/Bishop.obj", d) {}
};

