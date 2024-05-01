#pragma once
#include "Punto2D.h"
#include "Model.h"
#include "Board.h"
class piece
{
//Se empiezan definiendo las piezas en una enumeraci�n. M�s tarde se cambiar�
	enum class piezas {pawn,king,queen,bishop,rook,knight,cancellor,archbishop};
	Punto2D posicion;
public:
//M�todos
	void mueve(Punto2D posicion, Model modelo);
	void elige(piezas p, Punto2D posicion);
};

