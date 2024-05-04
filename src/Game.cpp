#include"Game.h"

void Game::dibujaJuego(piece piezas) {	//Funcion dibujaJuego provisional, se a�ade a clase Juego/Game cuando se desarrolle
	
	//Dibuja el tablero
	board.dibuja();

	//Dibuja todas las piezas
	piezas.dibujaPiezas(board);
}

void Game::musica(bool sonido, int tema)
{
	switch (tema) //A�adir pistas de m�sica seg�n tem�tica elegida en el men�
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