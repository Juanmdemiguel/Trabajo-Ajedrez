#pragma once
#include "Piece.h"
#include "Model.h"
class Archbishop: public piece
{
	Model bishop;
public:
	Archbishop(Punto2D pos, bool c, int d) : piece(pos, c, "resources/model/Knight.obj", d), bishop("resources/model/Bishop.obj") {} //Cambiar este modelo
	void dibuja1Pieza(Board& tablero);
};

