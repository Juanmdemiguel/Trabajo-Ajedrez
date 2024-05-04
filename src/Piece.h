#pragma once
#include "Punto2D.h"
#include "Model.h"
#include "Board.h"
class piece
{
//Se empiezan definiendo las piezas en una enumeraci�n. M�s tarde se cambiar�.
	enum class TipoPieza {pawn,king,queen,bishop,rook,knight,cancellor,archbishop};
	Punto2D posicion;
	Model Pawn;
public:

//Constructor para inicializar los distintos modelos
	piece() : Pawn("resources/model/Pawn.obj") {}

//M�todos
	void dibuja1Pieza(Punto2D posicion, Model modelo);
	void elige(TipoPieza p, Punto2D posicion);
	void dibujaPiezas(Board tablero);

};

