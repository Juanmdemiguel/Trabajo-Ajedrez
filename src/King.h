#pragma once
#include "Piece.h"
#include "Model.h"

class King : public piece
{
public:
	King(Punto2D pos, bool c, int d) : piece(pos, c, "resources/model/King.obj", d) {}
};

