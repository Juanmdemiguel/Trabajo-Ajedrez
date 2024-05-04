#pragma once
#include "freeglut.h"
#include "Menu.h"
#include "Model.h"
#include "Board.h"
#include "Piece.h"

class Game
{
	Board board;
public:

	Board& getboard();
	void dibujaJuego(piece piezas);
	void musica(bool sonido, int tema);

};

