#include "King.h"

void King::getPosibles(Board& tablero) {

	int reach = 1;

	piece::getDiagonal(reach, tablero);
	piece::getHorizontal(reach, tablero);

	if (color) {
		if (enroqueCorto)tablero.getTile({ 9,1 }).setposible(true), posibles.push_back({ 9,1 });
		if (enroqueLargo)tablero.getTile({ 2,1 }).setposible(true), posibles.push_back({ 2,1 });
	}
	if (!color) {
		if (enroqueCorto)tablero.getTile({ 9,8 }).setposible(true), posibles.push_back({ 9,8 });
		if (enroqueLargo)tablero.getTile({ 2,8 }).setposible(true), posibles.push_back({ 2,8 });
	}
}