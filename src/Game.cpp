#include"Game.h"

void Game::dibujaJuego(piece piezas) {	//Funcion dibujaJuego provisional, se añade a clase Juego/Game cuando se desarrolle
	
	//Dibuja el tablero
	board.dibuja();

	//Dibuja todas las piezas
	piezas.dibujaPiezas(board);
}

void Game::musica(bool sonido, int tema)
{
	switch (tema) //Añadir pistas de música según temática elegida en el menú
	{
	case 0:
		(sonido == true) ? ETSIDI::playMusica("sounds/marchav2.mp3", true) : ETSIDI::stopMusica();
		break;
	case 1:
		break;
	case 2:
		break;
		//...
	}
		


}