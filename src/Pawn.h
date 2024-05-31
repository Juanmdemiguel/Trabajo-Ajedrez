#pragma once
#include "Piece.h"
#include "Model.h"
class Pawn : public piece
{
public:
	//Constructor
	Pawn(Punto2D pos, bool c, int d) : piece(pos, c, d) { tipo = PAWN; }
	void CompruebaMovRook(Punto2D pos, int reach, Board tablero);
	friend class Board;
};

