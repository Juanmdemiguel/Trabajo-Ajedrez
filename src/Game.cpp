#include"Game.h"

Board& Game::getboard()
{
	return board;
}

void Game::inicializa()
{
	board.initPath();
}

void Game::dibujaJuego() {	//Funcion dibujaJuego provisional, se añade a clase Juego/Game cuando se desarrolle
	//Dibuja el tablero
	board.dibuja();
	//Dibuja todas las piezas
	piezas.dibujaPiezas(board);
}

void Game::musica(bool sonido, char tema[])
{	
		(sonido == true) ? ETSIDI::playMusica(tema, true) : ETSIDI::stopMusica();
}