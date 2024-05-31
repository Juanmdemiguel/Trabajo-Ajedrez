#pragma once
#include "Game.h"

class Mouse
{
	double z{}, x{};
public:
	//Métodos
	void movimiento(int x, int y1, Game& juego, Punto2D& esfera, bool menu);
	void seleccion(Game& juego, int boton, int state) const;
	void setCoordenadas(double x1, double y1) { z = x1; x = y1; }
	const double getCoordenadaZ() { return z; }
	const double getCoordenadaX() { return x; }
	//Amigos
};

