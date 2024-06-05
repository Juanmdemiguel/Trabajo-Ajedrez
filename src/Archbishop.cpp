#include "Archbishop.h"
void Archbishop::getPosibles(Board& tablero) {
	int reach = 10;
	piece::getEle(tablero);
	piece::getDiagonal(reach, tablero);
}
