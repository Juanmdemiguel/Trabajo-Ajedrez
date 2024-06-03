#include "Queen.h"

void Queen::getPosibles(Punto2D pos, Board& tablero) {

	int reach = 10;
	double fila = (int)pos.x;     //Traduce el punto 2D a posiciones matriciales
	double columna = (int)pos.z;

	piece::getDiagonal(pos,reach,tablero);
	piece::getHorizontal(pos,reach,tablero);

}