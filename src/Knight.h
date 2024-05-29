#pragma once
#include "Piece.h"
#include "Model.h"
class Knight: public piece
{
public:
	Knight(Punto2D pos, bool c, int d) : piece(pos, c, "resources/model/Knight.obj", d){}
};

