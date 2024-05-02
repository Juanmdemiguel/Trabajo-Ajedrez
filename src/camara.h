#pragma once
#include "freeglut.h"
#include "math.h"
#include "Menu.h"

class Camara
{
	double posx;
	double posy;
	double posz;
	double mirax;
	double miray;
	double miraz;
	bool rotar = FALSE;

public:
	Camara();
	void set_pos(double _posx, double _posy, double _posz);
	void dibuja(Menu& principal);
	void actuador(Menu& principal, unsigned char key);
	void rota(Menu& principal);
	void zoom(Menu& principal, unsigned char key);
	void vertical(Menu& principal, unsigned char key);

};

