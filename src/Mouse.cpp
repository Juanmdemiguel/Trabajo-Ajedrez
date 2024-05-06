#include "Mouse.h"



void Mouse::movimiento(int x, int y1, Game& juego, Punto2D& esfera)
{
	float y = 600 - y1;
	Punto2D s;
	if (x > map(y, 125, 431, 117, 190) && x < map(y, 125, 431, 682, 610))
	{
		vector<vector<double>> matriz = {
		{map(y, 125, 431, 117, 190) * map(y, 125, 431, 117, 190), map(y, 125, 431, 117, 190), 1, 0},
		{400 * 400, 400, 1, 15},
		{map(y, 125, 431, 682, 610) * map(y, 125, 431, 682, 610), map(y, 125, 431, 682, 610), 1, 30}
		};
		esfera.x = map2(matriz, x);
	}
	if (y > 120 && y < 430)
	{
		vector<vector<double>> matriz1 = {
		{123 * 123, 123, 1, 0},
		{300 * 300, 300, 1, 12},
		{430 * 430, 430, 1, 24}
		};
		esfera.z = map2(matriz1, y);
	}

	juego.getboard().detectpieza(esfera);
}
void Mouse::seleccion(Game& juego, int boton)
{
	for (float i = 1; i < col + 1; i++) {
		for (float j = 1; j < fil + 1; j++)
		{
			juego.getboard().getTile({ i,j }).getpiezapuntada(boton);
			if (juego.getboard().getTile({ i,j }).getseleccionada() == true)
				cout << i << " " << j << endl;
		}
	}
}