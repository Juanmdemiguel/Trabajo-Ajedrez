#pragma once
#include "freeglut.h"
#include "ETSIDI.h"

class Menu
{
	bool menu = true, sonido = true;
	bool boton{};

public:

	bool getMenu() { return menu; }
	bool getSonido() { return sonido; }
	bool getBoton() { return boton; }
	void setMenu(bool valor) { menu = valor; }
	void setSonido(bool valor) { sonido = valor; }
	void setBoton(bool valor) { boton = valor; }
	void iniciaMenu(bool menu, bool sonido);
	void clickBotonesMenu(double x, double y);

};