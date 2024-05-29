#pragma once
#include "Piece.h"
#include "Model.h"
class Chancellor: public piece
{
	Model Rook;
public:
	Chancellor(Punto2D pos, bool c) : piece(pos, c, "resources/model/Knight.obj"), Rook("resources/model/Rook.obj") {} //Cambiar con otro modelo
};

