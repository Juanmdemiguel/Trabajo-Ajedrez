#pragma once
#include "Punto2D.h"
#include "freeglut.h"
#include "ETSIDI.h"
#include "math.h"
#include <iostream>
#include "cstring"
#define square 3

class Tile
{
	bool color;
	int ocupada = 2; //informa si no hay ninguna pieza (2), si hay una negra (0) o si hay una blanca (1) 
	bool apuntada = false; //informa si el ratón la está apuntando
	bool posible = false; //informa si es un posible movimiento de una pieza
	bool comestible = false;
	int tam = square;
	Punto2D posicion;

public:
	//Métodos
	void Dibuja(int i, int j, bool tematica); //Dibuja la casilla. Recibe las coordenadas como argumento
	void setPos(const int& col, const int& row) { this->posicion = { (double)col,(double)row }; };
	Punto2D getCenter();
	int getocupada() { return ocupada; };
	void setocupada(const int& s) { ocupada = s; };
	void apunta(const bool& s) { apuntada = s; };
	void setposible(bool p) { posible = p; };
	bool getposible() { return posible; };
	void setcomestible(bool p) { comestible = p; };
	bool getcomestible() { return comestible; };
	//Amigos

	friend class Board;
};


