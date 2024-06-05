#include "Chancellor.h"

void Chancellor::getPosibles(Board& tablero) {

	int reach = 10;

	piece::getEle(tablero);
	piece::getHorizontal(reach, tablero);
}