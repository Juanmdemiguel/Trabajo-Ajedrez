#include"Game.h"
#include "cstring"

Board& Game::getboard()
{
	return board;
}

void Game::inicializa()
{
	//Switch de modo de juego
	char cancion[] = "resources/sounds/marchav2.mp3";
	//Fin de switch
	strcpy_s(music, cancion);

	board.initPath();

}

void Game::dibujaJuego(piece piezas) {	//Funcion dibujaJuego provisional, se añade a clase Juego/Game cuando se desarrolle
	
	//Dibuja el tablero
	board.dibuja();

	//Dibuja todas las piezas
	piezas.dibujaPiezas(board);
}

void Game::musica(bool sonido, char tema[])
{	
		(sonido == true) ? ETSIDI::playMusica(tema, true) : ETSIDI::stopMusica();
}