#pragma once
#include "Piece.h"
#include "Model.h"

class Queen: public piece
{
	Model queen;

public:
	Queen(Punto2D pos, bool c) : piece(pos, c), queen ("resources/model/Queen.obj") {}
};

