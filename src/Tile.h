#pragma once

#include "Punto2D.h"
#include "freeglut.h"
class Tile
{
	bool color;
	bool ocupada = false;
	bool seleccionada = false;
	int tam = 3;
	Punto2D posicion;

public:

//Métodos
	void Dibuja(int i, int j); //Dibuja la casilla. Recibe las coordenadas como argumento
	void setPos(int row, int col);

//Amigos
	friend class Board;
};

