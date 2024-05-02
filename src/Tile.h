#pragma once

#include "Punto2D.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include "math.h"
#define square 3

class Tile
{
	bool color;
	bool ocupada = false;
	bool seleccionada = false;
	int tam = square;
	Punto2D posicion;

public:

//Métodos
	void Dibuja(int i, int j); //Dibuja la casilla. Recibe las coordenadas como argumento
	void setPos(int row, int col);
	Punto2D getCenter();
	bool esta_ocupado();
//Amigos
	friend class Board;
};

