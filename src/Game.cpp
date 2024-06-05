#include"Game.h"

<<<<<<< Updated upstream

void Game::dibujaJuego(int d) {	//Funcion dibujaJuego provisional, se añade a clase Juego/Game cuando se desarrolle
=======
void Game::dibujaJuego(int tema, int vision) {	//Funcion dibujaJuego provisional, se añade a clase Juego/Game cuando se desarrolle

>>>>>>> Stashed changes
	//Dibuja el tablero
	board.dibuja();
	blancas.cambiaTematica(tema);
	negras.cambiaTematica(tema);

	blancas.cambiaVision(vision);
	negras.cambiaVision(vision);

	//Dibuja todas las piezas --> FALTA CONCRETAR EL MÉTODO
	blancas.dibuja(board);
	negras.dibuja(board);
	

}

void Game::inicializa(int t, int v)
{
	for (double i = 1; i <= 10; ++i) {
		blancas.agregar(new Pawn({ i,2 }, 1, t, v));
		negras.agregar(new Pawn({ i,7 }, 0, t, v));
	}
	//Blancas
	blancas.agregar(new Rook({ 1,1 }, 1, t, v));
	blancas.agregar(new Rook({ 10,1 }, 1, t, v));
	blancas.agregar(new Knight({ 2,1 }, 1, t, v));
	blancas.agregar(new Knight({ 9,1 }, 1, t, v));
	blancas.agregar(new Archbishop({ 3,1 }, 1, t, v));
	blancas.agregar(new Chancellor({ 8,1 }, 1, t, v));
	blancas.agregar(new Bishop({ 4,1 }, 1, t, v));
	blancas.agregar(new Bishop({ 7,1 }, 1, t, v));
	blancas.agregar(new Queen({ 5,1 }, 1, t, v));
	blancas.agregar(new King({ 6,1 }, 1, t, v));
	//Negras
	negras.agregar(new Rook({ 1,8 }, 0, t, v));
	negras.agregar(new Rook({ 10,8 }, 0, t, v));
	negras.agregar(new Knight({ 2,8 }, 0, t, v));
	negras.agregar(new Knight({ 9,8 }, 0, t, v));
	negras.agregar(new Archbishop({ 3,8 }, 0, t, v));
	negras.agregar(new Chancellor({ 8,8 }, 0, t, v));
	negras.agregar(new Bishop({ 4,8 }, 0, t, v));
	negras.agregar(new Bishop({ 7,8 }, 0, t, v));
	negras.agregar(new Queen({ 5,8 }, 0, t, v));
	negras.agregar(new King({ 6,8 }, 0, t, v));

}


void Game::selecciona()
{
	bool aux, comp{};
	int p = 0;

	if (turno) {
		for (auto b : blancas) {

			if (b->get_pos() == Click) b->getPosibles(b->get_pos(), board);

			aux = b->mueve(Click, b->getVectorPosibles(), board);


			if (aux) mov = aux;

			if (aux)
			{
				if (b->get_pos().x == 8) {
					unsigned char key;
					p = b->promocionar(b->get_pos());
					comp = Promocion(p, b, 1);
				}
				mov = aux;
			}
			if (comp) break;

			//cout << mov << endl;

		}
	}
	if (!turno) {
		for (auto n : negras) {
			
			if (n->get_pos() == Click) n->getPosibles(n->get_pos(), board);

			aux = n->mueve(Click, n->getVectorPosibles(),board);


			if (aux) mov = aux;

			if (aux)
			{
				if (n->get_pos().x == 1) {
					unsigned char key;
					p = n->promocionar(n->get_pos());
					comp = Promocion(p, n, 1);
				}
				mov = aux;
			}
			if (comp) break;

		}
	}
}

void Game::ClearSelec()
{
	for (double i = 1; i <= fil; i++) {
		for (double j = 1; j <= col; j++) board.getTile({ j,i }).setposible(false), board.getTile({ j,i }).setcomestible(false);
	}
}


bool Game::Promocion(int tipo, piece *pieza, int t)
{

	switch (tipo)
	{
	case 1:
		if (!pieza->getColor()) 
		{
			negras.agregar(new Queen(pieza->get_pos() , pieza->getColor(), t));
			negras.eliminar(pieza);
		}
		else
		{
			blancas.agregar(new Queen( pieza->get_pos() , pieza->getColor(), t));
			blancas.eliminar(pieza);
		}
			return true;
		break;

	case 2:
		if (!pieza->getColor()) 
		{
			negras.agregar(new Bishop({ pieza->get_pos() }, pieza->getColor(), t));
			negras.eliminar(pieza);
		}
		else
		{
			blancas.agregar(new Bishop({ pieza->get_pos() }, pieza->getColor(), t));
			blancas.eliminar(pieza);
		}
			return true;
		break;

	case 3:
		if (!pieza->getColor())
		{
			negras.agregar(new Rook({ pieza->get_pos() }, pieza->getColor(), t));
			negras.eliminar(pieza);
		}
		else
		{
			blancas.agregar(new Rook({ pieza->get_pos() }, pieza->getColor(), t));
			blancas.eliminar(pieza);
		}
			return true;
		break;

	case 4:
		if (!pieza->getColor()) 
		{
			negras.agregar(new Knight({ pieza->get_pos() }, pieza->getColor(), t));
			negras.eliminar(pieza);
		}
		else
		{
			blancas.agregar(new Knight({ pieza->get_pos() }, pieza->getColor(), t));
			blancas.eliminar(pieza);
		}
			return true;
		break;

	case 5:
		if (!pieza->getColor()) 
		{
			negras.agregar(new Archbishop({ pieza->get_pos() }, pieza->getColor(), t));
			negras.eliminar(pieza);
		}
		else
		{
			blancas.agregar(new Archbishop({ pieza->get_pos() }, pieza->getColor(), t));
			blancas.eliminar(pieza);
		}
		return true;
		break;

	case 6:
		if (!pieza->getColor())
		{
			negras.agregar(new Chancellor({ pieza->get_pos() }, pieza->getColor(), t));
			negras.eliminar(pieza);
			
		}
		else 
		{
			blancas.agregar(new Chancellor({ pieza->get_pos() }, pieza->getColor(), t));
			blancas.eliminar(pieza);
		}
		return true;
		break;
	}
	return false;
}

