#pragma once
#include "freeglut.h"
#include "Menu.h"
#include "Model.h"
#include "Board.h"
#include "ListaPiezas.h"
#include "cstring"
#include <iostream>

class Game
{
	Board board;
	ListaPiezas blancas;
	ListaPiezas negras;

public:
	Board& getboard();
	void dibujaJuego(int d);
	void musica(bool sonido, char tema[]);
	void inicializa(int t, int v);

};

