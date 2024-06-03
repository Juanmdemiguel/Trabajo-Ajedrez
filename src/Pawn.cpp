#include "Pawn.h"

void Pawn::getPosibles(Punto2D pos, Board& tablero) {

	int reach = 10;
	double columna = (int)pos.x;     //Traduce el punto 2D a posiciones matriciales
	double fila = (int)pos.z;

	vector <Punto2D> posibles{};

	if (color) {
		pos.x == 2 ? reach = 2 : reach = 1;
		for (int i = 1; i <= reach; i++) {
			if ((columna + i) <= 8)	tablero.getTile({ fila,columna + i }).setposible(true), posibles.push_back({ fila,columna + i});//col
		}
	}
	if (!color) {
		pos.x == 7 ? reach = 2 : reach = 1;
		for (int i = 1; i <= reach; i++) {
			if ((columna - i) >= 0)	tablero.getTile({ fila,columna - i }).setposible(true), posibles.push_back({ fila,columna - i });//col
		}
	}
	//piece::getDiagonal(pos,reach,tablero);

	/*for (auto p : posibles)
		cout << p.x << p.z << endl;*/

	mueve(pos, posibles);
}

void Pawn::mueve(Punto2D pos, vector <Punto2D> posibles)
{
	for (auto p : posibles)
	{
		if ((int)pos.x == p.x && (int)pos.z == p.z)
		{
			posicion.x = p.x;
			posicion.z = p.z;
		}
			
	}
	
}