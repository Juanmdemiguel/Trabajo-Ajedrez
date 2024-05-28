#pragma once
#include "Piece.h"
#include "Model.h"

class King : public piece
{
	Model king;

public:
	King(Punto2D pos, bool c) : piece(pos, c), king("resources/model/King.obj") {}
};

