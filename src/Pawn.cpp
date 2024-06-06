#include "Pawn.h"

void Pawn::getPosibles(Board& tablero) {


	int reach = 10;
	double columna = (int)posicion.x;     //Traduce el punto 2D a posiciones matriciales
	double fila = (int)posicion.z;

	//IMPLEMENTACIÓN DEL MOVIMIENTO (NO SE PUEDE EMPLEAR LA GENERAL DE PIECE YA QUE ES PROPIA DEL PEÓN Y DEPENDE DEL COLOR Y DE SU POSICIÓN INICIAL)

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


	//IMPLEMENTACIÓN DE COMER LAS PIEZAS (NO SE PUEDE EMPLEAR LA GENERAL DE PIECE YA QUE ES PROPIA DEL PEÓN)

	if (color) {
		//Diagonal superior derecha vista desde blanco
		if ((fila + 1) <= 10 && (columna + 1) <= 8) { //fil col

			//Si la casilla de la diagonal está ocupada por una pieza del otro color, entonces la pone como comestible
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

			//Si la casilla de la diagonal está ocupada por una pieza del otro color, entonces la pone como comestible
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

int Pawn::promocionar(Punto2D pos)
{
	unsigned char key;

	if (pos.x == 1 || pos.x == 8)
	{
		promocion = TRUE;
		if (promocion)
		{
			cout << "Q: queen, B: bishop, R:rook, K:knight, A:archbishop, C:chancellor" << endl;
			cin >> key;

			if (key == 'Q' || key == 'q') //Cambia peon por reina
			{
				promocion = FALSE;
				return 1;
			}
			if (key == 'B' || key == 'b') //Cambia peon por alfil
			{
				promocion = FALSE;
				return 2;
			}
			if (key == 'R' || key == 'r') //Cambia peon por torre
			{
				promocion = FALSE;
				return 3;
			}
			if (key == 'K' || key == 'k') //Cambia peon por caballo
			{
				promocion = FALSE;
				return 4;
			}
			if (key == 'A' || key == 'a') //Cambia peon por arzobispo
			{
				promocion = FALSE;
				return 5;
			}
			if (key == 'C' || key == 'c') //Cambia peon por canciller
			{
				promocion = FALSE;
				return 6;
			}

			if (key == 'N' || key == 'n') //Cambia peon por canciller
			{
				promocion = FALSE;
				return 7;
			}
		}
	}
}

