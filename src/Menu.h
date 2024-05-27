#pragma once
#include "freeglut.h"
#include "ETSIDI.h"
#include "Comentario.h"

class Menu
{
	bool menu = true, sonido = true, comienzo = true;
	bool boton{};
	enum VENTANA { INICIO = 0, TEMATICA, VISION, COMENZAR } ventana{ INICIO };
	enum TEMATICA { SW, T2, T3 } tematica{ SW };
	int Ventana = 0;
	Comentario comentario1, comentario2, comentario3, comentario4, comentario5, comentario6;


public:

	void gestionaMenu();
	void dibujaFondo();
	bool getMenu() { return menu; }
	bool getSonido() { return sonido; }
	bool getBoton() { return boton; }
	int getVentana() { return Ventana; }


	void setMenu(bool valor) { menu = valor; }
	void setSonido(bool valor) { sonido = valor; }
	void setBoton(bool valor) { boton = valor; }
	void setVentana(int valor) { Ventana = valor; }

	void iniciaMenu(bool menu, bool sonido);
	void clickBotonesMenu(double x, double y);
	void clickBotonesMenu2(double x, double z, Comentario comentario);
	void musica(bool sonido);

	void Tema();
	friend class Coordinator;

};