#pragma once
#include "freeglut.h"
#include "Menu.h"
#include "Model.h"
#include "Board.h"
#include "ListaPiezas.h"
#include "cstring"
#include <iostream>
#include "ETSIDI.h"


class Game
{
	Board board;
	ListaPiezas blancas;
	ListaPiezas negras;
	Punto2D Click;
	bool turno = true; 
	bool mov{}; //Solo pasa de turno si ya has movido. No puedes mover si ya has movido. DEBERIA EMPEZAR EN FALSE, ESTA EN TRUE PARA PODER PASAR 
	//TERMINAR DE IMPLEMENTAR CUANDO SE HAGA EL MOVIMIENTO. Y BORRAR ESTO AL IMPLEMENTAR 
public:
	//Métodos
	Board& getboard() { return board; };
	void musica(bool sonido, char tema[]) { (sonido == true) ? ETSIDI::playMusica(tema, true) : ETSIDI::stopMusica(); };
	void dibujaJuego(int tema, int vision);
	void inicializa(int t, int v);
	void SetClick(Punto2D C) { Click = C; };
	void selecciona(int t, int v);
	void ClearSelec();
	void Listo() { turno = !turno; }
	bool& getMov() { return mov; }
	void setMov(bool _mov) { mov = _mov; }
	bool Promocion(int tipo, piece *pieza, int t, int v);

	bool comprobEnroqueCorto();
	bool comprobEnroqueLargo();
	bool comprobJaque(bool c);

	void Comer();
	void MueveSonido() { ETSIDI::play("resources/sounds/caminar/pasos1.wav"); }

	//Amigos

};

