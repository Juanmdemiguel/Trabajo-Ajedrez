#pragma once
#include "Game.h"

class Mouse
{
	//int x, y, click_izq;
	double x{}, y{};
public:
	void movimiento(int x, int y1, Game& juego, Punto2D& esfera);
	void seleccion(Game& juego, int boton, int state);
	void setCoordenadas(int x1, int y1)
	{
		x = x1;
		y = y1;
	}
	double getCoordenadaX() {return x;}
	double getCoordenadaY() { return y; }
};

