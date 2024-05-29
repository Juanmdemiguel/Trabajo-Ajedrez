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
	Model modelo;
	int tematica; //Star Wars ETSIDI...         Selecciona el como visualizar la pieza

public:

//Constructor para dar posición genérica y color a la pieza correspondiente
	piece() = default;
	piece(Punto2D pos, bool c, std::string objFilePath, int d) : modelo(objFilePath) { posicion = pos, color = c; tematica = d;  }

//Métodos
	virtual void dibuja1Pieza(Board& tablero);
	void cambiaTematica(int d) { tematica = d; }

//Amigos
	friend class Tile;
};

