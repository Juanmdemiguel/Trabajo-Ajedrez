#pragma once
#include "Piece.h"
#include "Model.h"

class Rook : public piece
{
	Model rook;

public:
	Rook(Punto2D pos, bool c) : piece(pos, c), rook("resources/model/Rook.obj") {}
		
};

