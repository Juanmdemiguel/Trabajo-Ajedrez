#pragma once
#include "Piece.h"
#include "Model.h"
class Archbishop: public piece
{
	Model bishop;
public:
	Archbishop(Punto2D pos, bool c) : piece(pos, c, "resources/model/Knight.obj"), bishop("resources/model/Bishop.obj") {} //Cambiar este modelo
};

