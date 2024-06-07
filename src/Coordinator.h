#pragma once
#include "Game.h"
#include "Model.h"
#include "Board.h"
#include "camara.h"
#include "Piece.h"
#include "Mouse.h"
#include "freeglut.h"
#include <string>
#include <fstream>
#include <filesystem>
#include <iostream>
#include <chrono>
#include <thread>

class Coordinator
{
	enum Estado { MENU, JUEGO, FIN, PROMOCION} estado{MENU};

public:
	Menu principal; 
	Camara camara;
	Game juego;
	Mouse raton;
	Punto2D esfera; 
	char music[50];

//Métodos
	void Temp(int value) { camara.rota(principal); };
	void Mouse(int x, int y1) { raton.movimiento(x, y1, juego, esfera, principal.getMenu()); };
	void Dibuja(); 
	void Click(int _button, int state, int _x, int _y);
	void Teclado(unsigned char key, int x_t, int y_t);
	void MouseToGame();
	void PasaTurno();
	void CompruebaMusica();
	void Puntuaciones();
	void CreaFicheroPuntuaciones();
	void MenuPromocion();

};

