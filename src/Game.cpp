#include"Game.h"

void Game::dibujaJuego(int d) {	//Funcion dibujaJuego provisional, se añade a clase Juego/Game cuando se desarrolle
	//Dibuja el tablero
	board.dibuja();

	blancas.cambiaTematica(d);
	negras.cambiaTematica(d);
	//Dibuja todas las piezas --> FALTA CONCRETAR EL MÉTODO
	blancas.dibuja(board);
    negras.dibuja(board);
}

void Game::inicializa(int t, int v)
{
	for (double i = 1; i <= 10; ++i){
		blancas.agregar(new Pawn({ i,2 }, 1, t));
		negras.agregar(new Pawn({ i,7 }, 0, t));
	}
	//Blancas
	blancas.agregar(new Rook({ 1,1 }, 1, t));
	blancas.agregar(new Rook({ 10,1 }, 1, t));
	blancas.agregar(new Knight({ 2,1 }, 1, t));
	blancas.agregar(new Knight({ 9,1 }, 1, t));
	blancas.agregar(new Archbishop({ 3,1 }, 1, t));
	blancas.agregar(new Chancellor({ 8,1 }, 1, t));
	blancas.agregar(new Bishop({ 4,1 }, 1, t));
	blancas.agregar(new Bishop({ 7,1 }, 1, t));
	blancas.agregar(new Queen({ 5,1 }, 1, t));
	blancas.agregar(new King({ 6,1 }, 1, t));
	//Negras
	negras.agregar(new Rook({ 1,8 }, 0, t));
	negras.agregar(new Rook({ 10,8 }, 0, t));
	negras.agregar(new Knight({ 2,8 }, 0, t));
	negras.agregar(new Knight({ 9,8 }, 0, t));
	negras.agregar(new Archbishop({ 3,8 }, 0, t));
	negras.agregar(new Chancellor({ 8,8 }, 0, t));
	negras.agregar(new Bishop({ 4,8 }, 0, t));
	negras.agregar(new Bishop({ 7,8 }, 0, t));
	negras.agregar(new Queen({ 5,8 }, 0, t));
	negras.agregar(new King({ 6,8 }, 0, t));
}