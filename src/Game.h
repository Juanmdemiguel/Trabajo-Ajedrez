#pragma once
#include "freeglut.h"
#include "Menu.h"
#include "Model.h"
#include "Board.h"
#include "Piece.h"
#include "cstring"
#include <iostream>

class Game
{
	Board board;
	piece piezas;

public:
	Board& getboard();
	void dibujaJuego();
	void musica(bool sonido, char tema[]);

};

