#pragma once
#include "Punto2D.h"
#include "Model.h"
#include "Board.h"

class piece
{
//Se empiezan definiendo las piezas en una enumeración. Más tarde se cambiará.
	enum class TipoPieza {pawn,king,queen,bishop,rook,knight,cancellor,archbishop};
	Punto2D posicion;
	Tile casilla;
//Se define el color de las piezas. 0 para negro y 1 para blanco.
	bool color;
	Model Pawn;
	Model Tie;
public:

//Constructor para inicializar los distintos modelos
	piece() : Pawn("resources/model/Pawn.obj"), Tie("resources/model/tie_UV.obj") {}

//Métodos
	void dibuja1Pieza(Punto2D posicion, Model modelo, TipoPieza pieza, Board tablero);
	void elige(TipoPieza p, Punto2D posicion);
	void dibujaPiezas(Board tablero);
	void ocupado(Tile casilla);
//Amigos
	friend class Tile;
};

