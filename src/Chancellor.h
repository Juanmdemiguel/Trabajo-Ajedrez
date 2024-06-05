#pragma once
#include "Piece.h"
#include "Model.h"
class Chancellor: public piece
{
public:
//Constructor
	Chancellor(Punto2D pos, bool c, int t, int v) : piece(pos, c, t, v) { tipo = CHANCELLOR; } //Cambiar con otro modelo
	void getPosibles(Punto2D pos, Board& tablero);
};

