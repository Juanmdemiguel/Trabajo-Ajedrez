#include "Queen.h"

void Queen::getPosibles(Board& tablero) {

	int reach = 10;

	piece::getDiagonal(reach,tablero);
	piece::getHorizontal(reach,tablero);

}