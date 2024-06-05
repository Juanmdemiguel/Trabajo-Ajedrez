#include "Pawn.h"

void Pawn::getPosibles(Punto2D pos, Board& tablero) {


	int reach = 10;
	double columna = (int)pos.x;     //Traduce el punto 2D a posiciones matriciales
	double fila = (int)pos.z;
	bool d1 = false, d2 = false, d3 = false, d4 = false;

	if (color) {
		pos.x == 2 ? reach = 2 : reach = 1;
		for (int i = 1; i <= reach; i++) {
			
			//Pone a posible las casillas que tiene de frente, pero no a comestibles
			if ((columna + i) <= 8 && int(color) != tablero.getTile({ fila ,columna + i }).getocupada())
			{
				tablero.getTile({ fila,columna + i }).setposible(true);
				posibles.push_back({ fila,columna + i });//col
			}
		}
	}
	if (!color) {
		pos.x == 7 ? reach = 2 : reach = 1;
		for (int i = 1; i <= reach; i++) {

			//Pone a posible las casillas que tiene de frente, pero no a comestibles
			if ((columna - i) >= 0 && int(color) != tablero.getTile({ fila ,columna - i }).getocupada())
			{
				tablero.getTile({ fila,columna - i }).setposible(true);
				posibles.push_back({ fila,columna - i });//col
			}
		}
	}


	//Implementación de comer las piezas
	if (color) {
		//Diagonal superior derecha vista desde blanco
		if ((fila + 1) <= 10 && (columna + 1) <= 8) { //fil col

			//Si la casilla de la diagonal está ocupada por una pieza del otro color, entonces la pone como comestible
			if (tablero.getTile({ fila + 1,columna + 1 }).getocupada() != int(color) && tablero.getTile({ fila + 1,columna + 1 }).getocupada() != 2)
				tablero.getTile({ fila + 1,columna + 1 }).setcomestible(true), posibles.push_back({ fila + 1,columna + 1 });
		}
		
		//Diagonal superior izquierda vista desde blanco
		if ((fila - 1) >= 1 && (columna + 1) <= 8) {
			if (tablero.getTile({ fila - 1,columna + 1 }).getocupada() != int(color) && tablero.getTile({ fila - 1,columna + 1 }).getocupada() != 2)
				tablero.getTile({ fila - 1,columna + 1 }).setcomestible(true), posibles.push_back({ fila - 1,columna + 1 });
		}
		
	}
	
	if (!color) {

		//Diagonal superior derecha vista desde negro
		if ((fila - 1) >= 1 && (columna - 1) >= 1) { //fil col

			//Si la casilla de la diagonal está ocupada por una pieza del otro color, entonces la pone como comestible
			if (tablero.getTile({ fila - 1,columna - 1 }).getocupada() != int(color) && tablero.getTile({ fila - 1,columna - 1 }).getocupada() != 2)
				tablero.getTile({ fila - 1,columna - 1 }).setcomestible(true), posibles.push_back({ fila - 1,columna - 1 });
		}

		//Diagonal superior izquierda vista desde negro
		if ((fila + 1) <= 10 && (columna - 1) >= 1) {
			if (tablero.getTile({ fila + 1,columna - 1 }).getocupada() != int(color) && tablero.getTile({ fila + 1,columna - 1 }).getocupada() != 2)
				tablero.getTile({ fila + 1,columna - 1 }).setcomestible(true), posibles.push_back({ fila + 1,columna - 1 });
		}
	}

}

