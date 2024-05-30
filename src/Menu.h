#pragma once
#include "freeglut.h"
#include "ETSIDI.h"
#include "Comentario.h"
#include "Game.h"

class Menu
{
	bool menu = true, sonido = true, tope = false;
	bool boton{};
	enum VENTANA { INICIO = 0, TEMATICA, VISION, COMENZAR } ventana{ INICIO };
	enum TEMATICA { SW=0, T2, T3 } tematica{ SW };
	enum VISION { _2D = 0, _3D } vision{ _3D };
	Comentario comentario1, comentario2, comentario3, comentario4, comentario5, comentario6, comentario7;
	Punto2D r;		//Guarda coordenadas del ratón

public:
//Métodos
  //void gestionaMenu();
	void dibujaFondo();
	const bool getMenu() { return menu; }
	const bool getSonido() { return sonido; }
	const bool getBoton() { return boton; }
	void setCoord(Punto2D p) { r = p; }
	void setMenu(const bool& valor) { menu = valor; }
	void setSonido(const bool& valor) { sonido = valor; }
	void setBoton(const bool& valor) { boton = valor; }
	void iniciaMenu();
	void clickBotonesMenu();
	void musica() { (sonido) ? ETSIDI::playMusica("resources/sounds/menu.mp3", true) : ETSIDI::stopMusica(); };
	void Tema();
//Amigos
	friend class Coordinator;

};