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
	Punto2D Click;
	bool turno = true; 
public:
	//Métodos
	Board& getboard() { return board; };
	void musica(bool sonido, char tema[]) { (sonido == true) ? ETSIDI::playMusica(tema, true) : ETSIDI::stopMusica(); };
	void dibujaJuego(int d);
	void inicializa(int t, int v);
	void SetClick(Punto2D C) { Click = C; };
<<<<<<< Updated upstream
	void selecciona();
	void ClearSelec();
	//Amigos
	void posibles();
	void Listo() { turno = !turno; }
=======
	void posibles();
	void ocuparCasillas();
	//Amigos

>>>>>>> Stashed changes

};

