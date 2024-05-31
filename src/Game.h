#pragma once
#include "freeglut.h"
#include "Menu.h"
#include "Model.h"
#include "Board.h"
#include "ListaPiezas.h"
#include "cstring"
#include <iostream>
#include "Mouse.h"

class Game
{
	Board board;
	ListaPiezas blancas;
	ListaPiezas negras;
	bool turno = true;


public:
//Métodos
	Board& getboard() { return board; };
	void musica(bool sonido, char tema[]) { (sonido == true) ? ETSIDI::playMusica(tema, true) : ETSIDI::stopMusica(); };
	void dibujaJuego(int d);
	void inicializa(int t, int v);
	void seleccion(Mouse raton);
//Amigos

};

