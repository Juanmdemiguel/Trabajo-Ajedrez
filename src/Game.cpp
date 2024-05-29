#include"Game.h"

Board& Game::getboard()
{
	return board;
}


void Game::dibujaJuego(int d) {	//Funcion dibujaJuego provisional, se añade a clase Juego/Game cuando se desarrolle
	//Dibuja el tablero
	board.dibuja();

	//Dibuja todas las piezas --> FALTA CONCRETAR EL MÉTODO
	blancas.cambiaTematica(d);
	negras.cambiaTematica(d);
	blancas.dibuja(board);
    negras.dibuja(board);
}

void Game::musica(bool sonido, char tema[])
{	
		(sonido == true) ? ETSIDI::playMusica(tema, true) : ETSIDI::stopMusica();
}

void Game::inicializa(int d)
{
	for (double i = 1; i <= 10; ++i)
	{
		blancas.agregar(new Pawn({ i,2 }, 1, d));
		cout << 1;
		negras.agregar(new Pawn({ i,7 }, 0, d));
	}
	//Blancas
	blancas.agregar(new Rook({ 1,1 }, 1, d));
	blancas.agregar(new Rook({ 10,1 }, 1, d));
	blancas.agregar(new Knight({ 2,1 }, 1, d));
	blancas.agregar(new Knight({ 9,1 }, 1, d));
	blancas.agregar(new Archbishop({ 3,1 }, 1, d));
	blancas.agregar(new Chancellor({ 8,1 }, 1, d));
	blancas.agregar(new Bishop({ 4,1 }, 1, d));
	blancas.agregar(new Bishop({ 7,1 }, 1, d));
	blancas.agregar(new Queen({ 5,1 }, 1, d));
	blancas.agregar(new King({ 6,1 }, 1, d));
	//Negras
	blancas.agregar(new Rook({ 1,8 }, 0, d));
	blancas.agregar(new Rook({ 10,8 }, 0, d));
	blancas.agregar(new Knight({ 2,8 }, 0, d));
	blancas.agregar(new Knight({ 9,8 }, 0, d));
	blancas.agregar(new Archbishop({ 3,8 }, 0, d));
	blancas.agregar(new Chancellor({ 8,8 }, 0, d));
	blancas.agregar(new Bishop({ 4,8 }, 0, d));
	blancas.agregar(new Bishop({ 7,8 }, 0, d));
	blancas.agregar(new Queen({ 5,8 }, 0, d));
	blancas.agregar(new King({ 6,8 }, 0, d));
	

}