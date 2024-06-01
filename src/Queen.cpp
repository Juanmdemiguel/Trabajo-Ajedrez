#include "Queen.h"

void Queen::getHorizontal(Punto2D pos, int reach) {

	int fila = (int)pos.x - 1;     //Traduce el punto 2D a posiciones matriciales
	int columna = (int)pos.z - 1;

	for (int i = 1; i <= reach; i++) { //asigna a las matrices en la diagonal el estatus de posible
		/*
		if ((fila + i) < fil)
			board[fila + i][columna].posible = true;

		if ((fila - i) >= 0)
			board[fila - i][columna].posible = true;

		if ((columna + i) < col)
			board[fila][columna + i].posible = true;

		if ((columna - i) >= 0)
			board[fila][columna - i].posible = true;
			*/
	}
}