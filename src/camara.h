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
	bool vistaPuntuaciones{};
	bool fin = false; //Para gestionar el fin del juego

public:
//Constructor
	Camara() { posx = -20.0; posy = 40.0; posz = 15.0; };
//M�todos
	void set_pos(double _posx, double _posy, double _posz) { posx = _posx; posy = _posy; posz = _posz; };
	void dibuja(Menu& principal);
	void actuador(Menu& principal, bool& _rotate);
	void rota(Menu& principal);
	void zoom(Menu& principal, unsigned char key);
	void vertical(Menu& principal, unsigned char key);
	bool Cambiando() { return !estatico; }
	bool getPuntuaciones() { return vistaPuntuaciones; }
	void setVistaPuntuaciones(bool c) { vistaPuntuaciones = c; }

	void setfin(const bool& f) { fin = f; }
	bool getfin() { return fin; }
	
	void setRotar(const bool& rot) { rotar = rot; }
//Amigos

};

