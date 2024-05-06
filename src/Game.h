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
	
public:
	char music[50];

	Board& getboard();
	void dibujaJuego(piece& piezas);
	void musica(bool sonido, char tema[]);
	void inicializa();

};

