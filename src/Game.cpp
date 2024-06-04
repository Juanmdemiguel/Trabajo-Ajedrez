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
	for (double i = 1; i <= 10; ++i) {
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


	ocuparCasillas();
}


void Game::selecciona()
{
	bool aux;

	if (turno) {
		for (auto b : blancas) {

			if (b->get_pos() == Click) b->getPosibles(b->get_pos(), board);
			
			aux = b->mueve(Click, b->getVectorPosibles(),board);
			
			if (aux) mov = aux;

			//cout << mov << endl;
		}
	}
	if (!turno) {
		for (auto n : negras) {
	
			if (n->get_pos() == Click) n->getPosibles(n->get_pos(), board);

			aux = n->mueve(Click, n->getVectorPosibles(),board);

			if (aux) mov = aux;

			//cout << mov << endl;
		}
	}
}

void Game::ClearSelec()
{
	for (double i = 1; i <= fil; i++) {
		for (double j = 1; j <= col; j++) board.getTile({ j,i }).setposible(false);
	}
}

void Game::ocuparCasillas() {
	Punto2D c;
	for (double i = 1; i < fil + 1; i++) {
		for (double j = 1; j < col + 1; j++) {
			c = { j,i };
			for (auto k : blancas) if (k->get_pos() == c) board.getTile({ j,i }).setocupada(1);
			for (auto k : negras) if (k->get_pos() == c) board.getTile({ j,i }).setocupada(0);
		}
	}
}