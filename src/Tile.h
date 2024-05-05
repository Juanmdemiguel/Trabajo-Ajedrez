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
	bool posible = false;
	int tam = square;
	Punto2D posicion;


public:

//Métodos
	void Dibuja(int i, int j, char blancas[], char negras[], char selec[]); //Dibuja la casilla. Recibe las coordenadas como argumento
	void setPos(int col, int row);
	Punto2D getCenter();
	bool esta_ocupado();
	void ocupamiento(bool);
	void selecciona(bool);

	//Amigos
	friend class Board;
	friend class Game;
	friend class Piece;
};

