#pragma once
#include "freeglut.h"
#include "math.h"
#include "Menu.h"

class Camara
{
	double posx;
	double posy;
	double posz;

	double arriba = 0;
	double abajo = 0;
	double zoomin = 0;
	double zoomout = 0;
	bool rotar = FALSE;
	bool cambionegro = FALSE;
	bool modolibre = FALSE;
	bool estatico = TRUE;

public:
	Camara();
	void set_pos(double _posx, double _posy, double _posz);
	void dibuja(Menu& principal);
	void actuador(Menu& principal, unsigned char key);
	void rota(Menu& principal);
	void zoom(Menu& principal, unsigned char key);
	void vertical(Menu& principal, unsigned char key);
	void cambio_modo_libre(Menu& principak, unsigned char key);

};

