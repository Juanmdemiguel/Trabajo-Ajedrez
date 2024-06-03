#include "Queen.h"

void Queen::getPosibles(Punto2D pos, int reach, Board& tablero) {

	double fila = (int)pos.x - 1;     //Traduce el punto 2D a posiciones matriciales
	double columna = (int)pos.z - 1;

	for (double i = 0; i < fil; i++) {
		for (double j = 0; j < col; j++) 
			tablero.getTile({i,j}).setposible(true);
	}
/*
	for (int i = 1; i <= reach; i++) { //asigna posible a las casillas en horizontal y vertical

		if ((fila + i) < fil)
			tablero.getTile({ fila + i,columna }).setposible(true);

		if ((fila - i) >= 0)
			tablero.getTile({ fila - i,columna }).setposible(true);

		if ((columna + i) < col)
			tablero.getTile({ fila,columna + i }).setposible(true);

		if ((columna - i) >= 0)
			tablero.getTile({ fila,columna - i }).setposible(true);
	}

	for (int i = 1; i <= reach; i++) { //asigna a las matrices en la diagonal el estatus de posible
		if ((fila + i) < fil && (columna + i) < col)
			tablero.getTile({ fila + i,columna + i }).setposible(true);

		if ((fila - i) >= 0 && (columna - i) >= 0)
			tablero.getTile({ fila - i,columna - i }).setposible(true);
	
		if ((fila - i) >= 0 && (columna + i) < col)
			tablero.getTile({ fila - i,columna + i }).setposible(true);

		if ((fila + i) < fil && (columna - i) >= 0)
			tablero.getTile({ fila + i,columna - i }).setposible(true);
	}*/
}