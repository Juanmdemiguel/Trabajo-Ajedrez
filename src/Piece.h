#pragma once
#include "Punto2D.h"
#include "Board.h"
#include "freeglut.h"
#include "Model.h"
#include <iostream>

class piece
{
protected:
	Punto2D posicion;
	//Se define el color de las piezas. 0 para negro y 1 para blanco.
	bool color;
	int tematica; //Star Wars ETSIDI...         Selecciona el como visualizar la pieza
	enum TIPO { PAWN, ROOK, BISHOP, KNIGHT, KING, QUEEN, ARCHBISHOP, CHANCELLOR } tipo;

	inline static Model King{ "resources/model/King.obj" };
	inline static Model Queen{ "resources/model/Queen.obj" };
	inline static Model Bishop{ "resources/model/Bishop.obj" };
	inline static Model Rook{ "resources/model/Rook.obj" };
	inline static Model Knight{ "resources/model/Knight.obj" };
	inline static Model Pawn{ "resources/model/Pawn.obj" };

public:
	//Constructor para dar posición genérica y color a la pieza correspondiente
	piece(Punto2D pos, bool c, int d) { posicion = pos, color = c; tematica = d; }
	//Métodos
	void dibuja1Pieza(Board& tablero);
	void cambiaTematica(int d) { tematica = d; }
	void dibujaSprite(Board& tablero);
	void dibujaModelo(Board& tablero) const;
	virtual void getPosibles(Punto2D pos, int reach, Board& tablero) = 0;
	//Amigos
};