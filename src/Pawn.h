#pragma once
#include "Piece.h"
#include "Model.h"
class Pawn : public piece
{
	bool promocion{};

public:
	//Constructor
	Pawn(Punto2D pos, bool c, int d) : piece(pos, c, d) { tipo = PAWN; }
	void getPosibles(Punto2D pos, Board& tablero);
	int promocionar(Punto2D pos) override;

};

