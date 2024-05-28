#pragma once
#include "ETSIDI.h"
#include"Punto2D.h"

class Comentario
{
	Punto2D p1{};		//Esquina superior derecha
	bool BotonSonido{};	//Indica si es de sonido el botón para poder tachar el cuadro o no

public:

	void setEsquina(Punto2D punto) { p1 = punto; }

	Punto2D getEsquinaDrchaCuadro() { return p1; }

	void dibuja( bool sonido, int ventana, int n_com);
	void creaComentario(bool sonido, int ventana, int n_com);
	//void dibujaTexto(int menu, int numCuad);
	void setSound() { BotonSonido = true; }
	bool getSound() { return BotonSonido; }
	void cargaTextura(int ventana, int n_com, bool sonido);
};

