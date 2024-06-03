#include "King.h"

void King::getPosibles(Punto2D pos, Board& tablero) {

	int reach = 1;
	double fila = (int)pos.x - 1;     //Traduce el punto 2D a posiciones matriciales
	double columna = (int)pos.z - 1;
	
	piece::getDiagonal(pos,reach,tablero);
	piece::getHorizontal(pos,reach,tablero);
}