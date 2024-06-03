#include "Knight.h"

void Knight::getPosibles(Punto2D pos, Board& tablero) {

	int reach = 10;
	int fila = (int)pos.x - 1;     //Traduce el punto 2D a posiciones matriciales
	int columna = (int)pos.z - 1;

	piece::getEle(pos, tablero);
}