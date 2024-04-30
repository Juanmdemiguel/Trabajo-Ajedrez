#pragma once
#include "freeglut.h"
#define col 10
#define fil 8
#define square 3

class Board
{
public:
	bool board[fil][col];


	void inicializa();
	void dibuja();
};

