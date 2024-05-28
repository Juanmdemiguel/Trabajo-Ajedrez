#pragma once
#include "Piece.h"
#include "Model.h"
class Chancellor: public piece
{
	Model chancellor;
public:
	Chancellor(Punto2D pos, bool c) : piece(pos, c), chancellor("resources/model/Pawn.obj") {} //Cambiar con otro modelo
};

