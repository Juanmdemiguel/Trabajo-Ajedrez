#pragma once
#include "Game.h"

class Mouse
{
	double z{}, x{};
	Punto2D Click;
public:
	//Métodos
	void movimiento(int x, int y1, Game& juego, Punto2D& esfera, bool menu);
	void seleccion(Game& juego, int boton, int state);
	void setCoordenadas(double x1, double y1) { z = x1; x = y1; }
	const double getCoordenadaZ() { return z; }
	const double getCoordenadaX() { return x; }
	Punto2D getClick() { return Click; };
	//Amigos
};

