#pragma once
#include "ETSIDI.h"
#include"Punto2D.h"

class Comentario
{
	Punto2D p1{};		//Esquina abajo izquierda
	Punto2D p2{};		//Esquina superior derecha

public:

	void setPosicionCuadro(Punto2D punto1, Punto2D punto2){
		p1 = punto1;
		p2 = punto2;
	}
	Punto2D getEsquinaIzqdaCuadro() { return p1; }
	Punto2D getEsquinaDrchaCuadro() { return p2; }

	void dibujaComentario(bool sonido);
	void dibujaTexto(int menu, int numCuad);
};

