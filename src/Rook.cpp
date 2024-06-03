#include "Rook.h"

void Rook::getPosibles(Punto2D pos, Board& tablero) {

	int reach = 10;
	double fila = (int)pos.x;     //Traduce el punto 2D a posiciones matriciales
	double columna = (int)pos.z;

	piece::getHorizontal(pos,reach,tablero);
}