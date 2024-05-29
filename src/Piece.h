#pragma once
#include "Punto2D.h"
#include "Board.h"
#include "freeglut.h"
#include "Model.h"
#include <iostream>

class piece
{
	Punto2D posicion;
//Se define el color de las piezas. 0 para negro y 1 para blanco.
	bool color;
	Model modelo;

public:

//Constructor para dar posición genérica y color a la pieza correspondiente
	piece() = default;
	piece(Punto2D pos, bool c, std::string objFilePath) : modelo(objFilePath) { posicion = pos, color = c; };

//Métodos
	void dibuja1Pieza(Board& tablero);

//Amigos
	friend class Tile;
};

