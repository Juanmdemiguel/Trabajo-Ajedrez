#pragma once
#include "Game.h"

class Mouse
{
	//int x, y, click_izq;
public:
	void movimiento(int x, int y1, Game& juego, Punto2D& esfera);
	void seleccion(Game& juego, int boton, int state);
};

