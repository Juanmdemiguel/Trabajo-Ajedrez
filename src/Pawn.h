#pragma once
#include "Piece.h"
#include "Model.h"
class Pawn: public piece
{
	Model pawn;
public:
	Pawn(Punto2D pos, bool c) : piece(pos,c), pawn("resources/model/Pawn.obj") {}
};

