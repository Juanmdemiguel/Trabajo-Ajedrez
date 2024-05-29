#pragma once
#include "Game.h"
#include "Model.h"
#include "Board.h"
#include "camara.h"
#include "Piece.h"
#include "Mouse.h"

class Coordinator
{
	enum Estado { MENU, JUEGO} estado{};
public:
	Menu principal; 
	Camara camara;
	Game juego;
	Mouse raton;
	Punto2D esfera; 
	char music[50];

	void Dibuja(); 
	void Temp(int value);
	void Click(int _button, int state, int _x, int _y);
	void Mouse(int x, int y1);
	void Teclado(unsigned char key, int x_t, int y_t);
	void Inicializa();
};

