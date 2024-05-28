#pragma once
#include "freeglut.h"
#include "ETSIDI.h"
#include "Comentario.h"

class Menu
{
	bool menu = true, sonido = true;
	bool boton{};
	enum VENTANA { INICIO = 0, TEMATICA, VISION, COMENZAR } ventana{ INICIO };
	enum TEMATICA { SW, T2, T3 } tematica{ SW };
	enum VISION { _2D, _3D } vision{ _2D };
	Comentario comentario1, comentario2, comentario3, comentario4, comentario5, comentario6, comentario7;
	
	Punto2D r;		//Guarda coordenadas del rat�n


public:

	void gestionaMenu();
	void dibujaFondo();
	bool getMenu() { return menu; }
	bool getSonido() { return sonido; }
	bool getBoton() { return boton; }
	void setCoord(Punto2D p) { r = p; }

	void setMenu(const bool& valor) { menu = valor; }
	void setSonido(const bool& valor) { sonido = valor; }
	void setBoton(const bool& valor) { boton = valor; }

	void iniciaMenu();
	void clickBotonesMenu();
	
	void musica();

	void Tema();
	friend class Coordinator;

};