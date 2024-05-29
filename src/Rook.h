#pragma once
#include "Piece.h"
#include "Model.h"

class Rook : public piece
{
	//Model rook;

public:
	Rook(Punto2D pos, bool c, int d) : piece(pos, c, "resources/model/Rook.obj", d) {}
		
};

