#include "Pawn.h"

void Pawn::getPosibles(Board& tablero) {


	int reach = 10;
	double columna = (int)posicion.x;     //Traduce el punto 2D a posiciones matriciales
	double fila = (int)posicion.z;

	//IMPLEMENTACI�N DEL MOVIMIENTO (NO SE PUEDE EMPLEAR LA GENERAL DE PIECE YA QUE ES PROPIA DEL PE�N Y DEPENDE DEL COLOR Y DE SU POSICI�N INICIAL)

	if (color) {
		posicion.x == 2 ? reach = 2 : reach = 1;
		for (int i = 1; i <= reach; i++) {

			//Pone a posible las casillas que tiene solamente de frente, pero no a comestibles
			if ((columna + i) <= 8 && tablero.getTile({ fila ,columna + i }).getocupada() == 2)
			{
				if (reach == 2 && !(tablero.getTile({ fila ,columna + 1 }).getocupada() == 2))break;
				tablero.getTile({ fila,columna + i }).setposible(true);
				posibles.push_back({ fila,columna + i });//col
			}
		}
	}
	if (!color) {
		posicion.x == 7 ? reach = 2 : reach = 1;
		for (int i = 1; i <= reach; i++) {

			//Pone a posible las casillas que tiene solamente de frente, pero no a comestibles
			if ((columna - i) >= 0 && tablero.getTile({ fila ,columna - i }).getocupada() == 2)
			{
				if (reach == 2 && !(tablero.getTile({ fila ,columna - 1 }).getocupada() == 2))break;
				tablero.getTile({ fila,columna - i }).setposible(true);
				posibles.push_back({ fila,columna - i });//col
			}
		}
	}


	//IMPLEMENTACI�N DE COMER LAS PIEZAS (NO SE PUEDE EMPLEAR LA GENERAL DE PIECE YA QUE ES PROPIA DEL PE�N)

	if (color) {
		//Diagonal superior derecha vista desde blanco
		if ((fila + 1) <= 10 && (columna + 1) <= 8) { //fil col

			//Si la casilla de la diagonal est� ocupada por una pieza del otro color, entonces la pone como comestible
			if (tablero.getTile({ fila + 1,columna + 1 }).getocupada() != int(color) && tablero.getTile({ fila + 1,columna + 1 }).getocupada() != 2) {
				tablero.getTile({ fila + 1,columna + 1 }).setcomestible(true), posibles.push_back({ fila + 1,columna + 1 });
				tablero.getTile({ fila + 1,columna + 1 }).setposible(true);
			}
		}

		//Diagonal superior izquierda vista desde blanco
		if ((fila - 1) >= 1 && (columna + 1) <= 8) {
			if (tablero.getTile({ fila - 1,columna + 1 }).getocupada() != int(color) && tablero.getTile({ fila - 1,columna + 1 }).getocupada() != 2) {
				tablero.getTile({ fila - 1,columna + 1 }).setcomestible(true), posibles.push_back({ fila - 1,columna + 1 });
				tablero.getTile({ fila - 1,columna + 1 }).setposible(true);
			}
		}

	}

	if (!color) {

		//Diagonal superior derecha vista desde negro
		if ((fila - 1) >= 1 && (columna - 1) >= 1) { //fil col

			//Si la casilla de la diagonal est� ocupada por una pieza del otro color, entonces la pone como comestible
			if (tablero.getTile({ fila - 1,columna - 1 }).getocupada() != int(color) && tablero.getTile({ fila - 1,columna - 1 }).getocupada() != 2) {
				tablero.getTile({ fila - 1,columna - 1 }).setcomestible(true), posibles.push_back({ fila - 1,columna - 1 });
				tablero.getTile({ fila - 1,columna - 1 }).setposible(true);
			}
		}

		//Diagonal superior izquierda vista desde negro
		if ((fila + 1) <= 10 && (columna - 1) >= 1) {
			if (tablero.getTile({ fila + 1,columna - 1 }).getocupada() != int(color) && tablero.getTile({ fila + 1,columna - 1 }).getocupada() != 2) {
				tablero.getTile({ fila + 1,columna - 1 }).setcomestible(true), posibles.push_back({ fila + 1,columna - 1 });
				tablero.getTile({ fila + 1,columna - 1 }).setposible(true);
			}
		}
	}

}

