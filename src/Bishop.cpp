#include "Bishop.h"

void Bishop::getPosibles(Punto2D pos, Board& tablero) {

	int reach = 10;
	double fila = (int)pos.x - 1;     //Traduce el punto 2D a posiciones matriciales
	double columna = (int)pos.z - 1;

	piece::getDiagonal(pos,reach,tablero);
}