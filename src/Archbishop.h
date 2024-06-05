#pragma once
#include "Piece.h"
#include "Model.h"

class Archbishop: public piece
{
public:
//Constructor
	Archbishop(Punto2D pos, bool c, int t, int v) : piece(pos, c, t, v) { tipo = ARCHBISHOP; } //Cambiar este modelo
	void getPosibles(Punto2D pos, Board& tablero);
};

