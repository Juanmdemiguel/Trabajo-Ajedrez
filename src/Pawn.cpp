#include "Pawn.h"

void Pawn::getPosibles(Punto2D pos, Board& tablero) {


	int reach = 10;
	double columna = (int)pos.x;     //Traduce el punto 2D a posiciones matriciales
	double fila = (int)pos.z;


	if (color) {
		pos.x == 2 ? reach = 2 : reach = 1;
		for (int i = 1; i <= reach; i++) {
			if ((columna + i) <= 8 && int(color) != tablero.getTile({ fila ,columna + i }).getocupada())
			{
				tablero.getTile({ fila,columna + i }).setposible(true);
				posibles.push_back({ fila,columna + i });//col
				if (tablero.getTile({ fila ,columna + i }).getposible() && tablero.getTile({ fila ,columna + i }).getocupada() != int(color) && tablero.getTile({ fila ,columna + i }).getocupada() != 2)
					tablero.getTile({ fila ,columna + i }).setcomestible(true);
			}
		}
	}
	if (!color) {
		pos.x == 7 ? reach = 2 : reach = 1;
		for (int i = 1; i <= reach; i++) {
			if ((columna - i) >= 0 && int(color) != tablero.getTile({ fila ,columna - i }).getocupada())
			{
				tablero.getTile({ fila,columna - i }).setposible(true);
				posibles.push_back({ fila,columna - i });//col
				if (tablero.getTile({ fila,columna - i }).getposible() && tablero.getTile({ fila,columna - i }).getocupada() != int(color) && tablero.getTile({ fila,columna - i }).getocupada() != 2)
					tablero.getTile({ fila,columna - i }).setcomestible(true);
			}
		}
	}

	//piece::getDiagonal(pos,reach,tablero);

	/*for (auto p : posibles)
		cout << p.x << p.z << endl;*/


}

