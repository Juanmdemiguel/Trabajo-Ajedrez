#include "Bishop.h"

void Bishop::getPosibles(Punto2D pos, int reach, Board& tablero) {

	double fila = (int)pos.x - 1;     //Traduce el punto 2D a posiciones matriciales
	double columna = (int)pos.z - 1;

	for (int i = 1; i <= reach; i++) { //asigna a las matrices en la diagonal el estatus de posible
		if ((fila + i) < fil && (columna + i) < col)
			tablero.getTile({ fila + i,columna + i }).setposible(true);

		if ((fila - i) >= 0 && (columna - i) >= 0)
			tablero.getTile({ fila - i,columna - i }).setposible(true);

		if ((fila - i) >= 0 && (columna + i) < col)
			tablero.getTile({ fila - i,columna + i }).setposible(true);

		if ((fila + i) < fil && (columna - i) >= 0)
			tablero.getTile({ fila + i,columna - i }).setposible(true);
	}
}