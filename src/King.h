#pragma once
#include "Piece.h"
#include "Model.h"

class King : public piece
{
	bool enroqueCorto = 0; //Posibilidad de enroque corto = 1
	bool enroqueLargo = 0; //Posibilidad de enroque largo = 1
public:
//Constructor
	King(Punto2D pos, bool c, int t, int v) : piece(pos, c, t, v) { tipo = KING; }
	void getPosibles(Board& tablero);
	bool getMov1() override { return mov1; }
	void set_EnroqueCorto(bool c) { enroqueCorto = c; };
	void set_EnroqueLargo(bool c) { enroqueLargo = c; };
};