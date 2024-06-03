#include "Pawn.h"

void Pawn::getPosibles(Punto2D pos, int reach, Board& tablero) 
{


	double columna = (int)pos.x;     //Traduce el punto 2D a posiciones matriciales
	double fila = (int)pos.z;

	if (color) {
		pos.x == 2 ? reach = 2 : reach = 1;
		for (int i = 1; i <= reach; i++) {
			if ((columna + i) <= 8)	tablero.getTile({ fila,columna + i }).setposible(true);//col
		}
	}
	if (!color) {
		pos.x == 7 ? reach = 2 : reach = 1;
		for (int i = 1; i <= reach; i++) {
			if ((columna - i) >= 0)	tablero.getTile({ fila,columna - i }).setposible(true);//col
		}
	}
	

	//piece::getDiagonal(pos,reach,tablero);
}