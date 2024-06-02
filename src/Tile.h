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
	bool ocupada = false; //informa si hay una pieza encima
	bool apuntada = false; //informa si el ratón la está apuntando
	bool posible = false; //informa si es un posible movimiento de una pieza
	int tam = square;
	Punto2D posicion;

public:
	//Métodos
	void Dibuja(int i, int j); //Dibuja la casilla. Recibe las coordenadas como argumento
	void setPos(const int& col, const int& row) { this->posicion = { (double)col,(double)row }; };
	Punto2D getCenter();
	bool getocupada() { return ocupada; };
	void setocupada(const bool& s) { ocupada = s; };
	void apunta(const bool& s) { apuntada = s; };
	void setposible(bool p) { posible = p; };
	bool getposible() { return posible; };
	//Amigos

	friend class Board;
};


