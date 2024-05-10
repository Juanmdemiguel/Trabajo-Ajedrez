#pragma once
#include "ETSIDI.h"
#include"Punto2D.h"

class Comentario
{
	Punto2D p1{};		//Esquina abajo izquierda
	Punto2D p2{};		//Esquina superior derecha
	bool BotonSonido{};	//Indica si es de sonido el botón para poder tachar el cuadro o no

public:

	void setPosicionCuadro(Punto2D punto1, Punto2D punto2){
		p1 = punto1;
		p2 = punto2;
	}
	Punto2D getEsquinaIzqdaCuadro() { return p1; }
	Punto2D getEsquinaDrchaCuadro() { return p2; }

	void dibujaComentario(bool BotonSonido, bool sonido);
	void dibujaTexto(int menu, int numCuad);
	void setSound() { BotonSonido = true; }
	bool getSound() { return BotonSonido; }
};

