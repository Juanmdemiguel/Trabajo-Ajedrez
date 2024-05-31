#include "Pawn.h"

void Pawn::CompruebaMovRook(Punto2D pos, int reach, Board tablero) {

	double fila = (int)pos.x - 1.0;     //Traduce el punto 2D a posiciones matriciales
	double columna = (int)pos.z - 1.0;

	for (double i = 1.0; i <= reach; i++) { //asigna a las matrices en la diagonal el estatus de posible
		if ((fila + i) < fil)
			tablero.getTile({ i,columna }).set_posible(true);
		if ((fila - i) >= 0)
			tablero.getTile({ -i,columna }).set_posible(true);

		if ((columna + i) < col)
			tablero.getTile({ fila,i }).set_posible(true);

		if ((columna - i) >= 0)
			tablero.getTile({ fila,-i }).set_posible(true);
	}
