#pragma once
#include "Punto2D.h"
#include "Model.h"
#include "Board.h"
#include "freeglut.h"
#include <iostream>

class piece
{
//Se empiezan definiendo las piezas en una enumeración. Más tarde se cambiará.
	enum class TipoPieza {pawn,king,queen,bishop,rook,knight,cancellor,archbishop};
	Punto2D posicion;

//Se define el color de las piezas. 0 para negro y 1 para blanco.
	bool color;

	Model Pawn;
	Model Bishop;
	Model Knight;
	Model Rook;
	Model King;
	Model Queen;

public:

//Constructor para inicializar los distintos modelos
	piece() : Pawn("resources/model/Pawn.obj"), Bishop("resources/model/Bishop.obj"), 
			Knight("resources/model/Knight.obj"), Rook("resources/model/Rook.obj"), 
	 King("resources/model/King.obj"), Queen("resources/model/Queen.obj") {}
	
//Métodos
	void dibuja1Pieza(Punto2D posicion, Model modelo, TipoPieza pieza, Board& tablero);
	void elige(TipoPieza p, Punto2D posicion);
	void dibujaPiezas(Board& tablero);
//Amigos
	friend class Tile;
};

