#pragma once
#include "Piece.h"
#include "Model.h"
class Pawn : public piece
{
	bool promocion{};

public:
	//Constructor
	Pawn(Punto2D pos, bool c, int t, int v) : piece(pos, c, t, v) { tipo = PAWN; }
	void getPosibles(Board& tablero);
	void setPromocion() override { promocion = true; };
	bool getPromocion() override { return promocion; };
};

