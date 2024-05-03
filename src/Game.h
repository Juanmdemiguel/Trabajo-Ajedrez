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
	void dibujaJuego(piece piezas);
};

