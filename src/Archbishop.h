#pragma once
#include "Piece.h"
#include "Model.h"
class Archbishop: public piece
{
	Model archbishop;
public:
	Archbishop(Punto2D pos, bool c) : piece(pos, c), archbishop("resources/model/Pawn.obj") {} //Cambiar este modelo
};

