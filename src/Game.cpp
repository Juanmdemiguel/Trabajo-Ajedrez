#include"Game.h"

Board& Game::getboard()
{
	return board;
}


void Game::dibujaJuego() {	//Funcion dibujaJuego provisional, se a�ade a clase Juego/Game cuando se desarrolle
	//Dibuja el tablero
	board.dibuja();

	//Dibuja todas las piezas --> FALTA CONCRETAR EL M�TODO
	//blancas.dibuja();
    // negras.dibuja();
}

void Game::musica(bool sonido, char tema[])
{	
		(sonido == true) ? ETSIDI::playMusica(tema, true) : ETSIDI::stopMusica();
}