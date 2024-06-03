#include "Archbishop.h"
void Archbishop::getPosibles(Punto2D pos, Board& tablero) {

	int reach = 10;
	double fila = (int)pos.x - 1;     //Traduce el punto 2D a posiciones matriciales
	double columna = (int)pos.z - 1;

	piece::getEle(pos, tablero);
	piece::getDiagonal(pos, reach, tablero);
}
