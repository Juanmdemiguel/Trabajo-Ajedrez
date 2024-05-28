#pragma once
#include "Piece.h"
#include "Model.h"

class Bishop: public piece
{
	Model bishop;

public:
	Bishop(Punto2D pos, bool c) : piece(pos, c),  bishop("resources/model/Bishop.obj") {}
};

