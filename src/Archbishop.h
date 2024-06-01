#pragma once
#include "Piece.h"
#include "Model.h"

class Archbishop: public piece
{
public:
//Constructor
	Archbishop(Punto2D pos, bool c, int d) : piece(pos, c, d) { tipo = ARCHBISHOP; } //Cambiar este modelo
	void getHorizontal(Punto2D pos, int reach);
};

