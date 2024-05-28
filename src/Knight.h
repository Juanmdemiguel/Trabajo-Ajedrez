#pragma once
#include "Piece.h"
#include "Model.h"
class Knight: public piece
{
	Model knight;
public:
	Knight(Punto2D pos, bool c) : piece(pos, c), knight("resources/model/Knight.obj") {}
};

