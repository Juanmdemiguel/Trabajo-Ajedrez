#pragma once
#include "Game.h"

class Mouse
{
	//int x, y, click_izq;
	double z{}, x{};
public:
	void movimiento(int x, int y1, Game& juego, Punto2D& esfera, bool menu);
	void seleccion(Game& juego, int boton, int state);
	void setCoordenadas(double x1, double y1)
	{
		z = x1;
		x = y1;
	}
	double getCoordenadaZ() {return z;}
	double getCoordenadaX() { return x;}
};

