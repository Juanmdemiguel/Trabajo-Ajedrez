#pragma once
#include "Piece.h"
#include "Model.h"
class Archbishop: public piece
{
public:
	Archbishop(Punto2D pos, bool c, int d) : piece(pos, c, d) { tipo = ARCHBISHOP; } //Cambiar este modelo
};

