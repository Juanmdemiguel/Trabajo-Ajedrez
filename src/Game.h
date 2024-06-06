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

	long jugador1{}, jugador2{};	//long ints de jugadores

	bool comida = false;  //Para comprobar si funciona el fin. QUITAR CUANDO SE COMPLETE EL JAQUE MATE

public:
	//Métodos
	Board& getboard() { return board; };
	void musica(bool sonido, char tema[]) { (sonido == true) ? ETSIDI::playMusica(tema, true) : ETSIDI::stopMusica(); };
	void dibujaJuego(int tema, int vision);
	void inicializa(int t, int v);
	void SetClick(Punto2D C) { Click = C; };
	void selecciona(int t, int v, bool cambio);
	void ClearSelec();
	void Listo() { turno = !turno; }
	bool& getMov() { return mov; }
	void setMov(bool _mov) { mov = _mov; }

	bool Promocion(int tipo, piece *pieza, int t, int v);

	bool comprobEnroqueCorto();
	bool comprobEnroqueLargo();
	bool comprobJaque(bool c, bool& DobleAmenaza, Punto2D& Maton);

	void SonidoComer();
	void MueveSonido() { ETSIDI::play("resources/sounds/caminar/pasos1.wav"); }

	//Método de comer
	bool comer(ListaPiezas& negras, piece* blancas);

	//Implementa el final de la partida
	bool finPartida();

	bool comprobJaqueMate(bool c);
	bool MataMaton(Punto2D Maton, bool color);

	int asignaPuntos(int pieza, double tiempo);

	long PuntosJ1() { return jugador1; }
	long PuntosJ2() { return jugador2; }

	//Amigos

};

