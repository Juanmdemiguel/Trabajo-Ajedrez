#include"Game.h"


void Game::dibujaJuego(int tema, int vision) {	//Funcion dibujaJuego provisional, se añade a clase Juego/Game cuando se desarrolle

	//Dibuja el tablero
	board.dibuja(tema);

	//Dibuja las piezas según la temática y modo de visualización
	blancas.cambiaTematica(tema);
	negras.cambiaTematica(tema);
	blancas.cambiaVision(vision);
	negras.cambiaVision(vision);

	//Dibuja piezas en el tablero
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


void Game::selecciona(int t, int v, bool cambio)
{
	bool aux, comp{};
	int p = 0;

	if (turno && !cambio) {
		for (auto b : blancas) {
			if (b->get_pos() == Click) b->getPosibles(board);

			if (Click == Punto2D({ 2,1 }) && b->getTipo() == 4 && comprobEnroqueLargo() && b->mueve(Click, b->getVectorPosibles(), board)) {
				for (auto a : blancas) {
					if (a->getTipo() == 1 && a->get_pos() == Punto2D({ 1,1 })) {
						a->setPos({3,1});
					}
				}
				mov = 1;
			}
			if (Click == Punto2D({ 9, 1}) && b->getTipo() == 4 && comprobEnroqueCorto() && b->mueve(Click, b->getVectorPosibles(), board)) {
				for (auto a : blancas) {
					if (a->getTipo() == 1 && a->get_pos() == Punto2D({10,1}) ) {
						a->setPos({ 8,1 });
					}
				}
				mov = 1;
			}

			else aux = b->mueve(Click, b->getVectorPosibles(), board);

			if (aux)
			{
				if (b->get_pos().x == 8) {
					p = b->promocionar(b->get_pos());
					comp = Promocion(p, b, t, v);
				}
				
				// Se realiza el método de comer una vez se ha movido comprobando las piezas blancas
				comer(negras, b);
				mov = aux;
				MueveSonido();
			}
			if (comp) break;
		}
	}

	if (!turno && !cambio) {

		for (auto n : negras) {
			if (n->get_pos() == Click) n->getPosibles(board);
			if (Click == Punto2D({ 2,8 }) && n->getTipo() == 4 && comprobEnroqueLargo() && n->mueve(Click, n->getVectorPosibles(), board)) {
				for (auto a : negras) {
					if (a->getTipo() == 1 && a->get_pos() == Punto2D({ 1,8 })) {
						a->setPos({ 3,8 });
					}
				}
				mov = true;
			}
			if (Click == Punto2D({ 9, 8 }) && n->getTipo() == 4 && comprobEnroqueCorto() && n->mueve(Click, n->getVectorPosibles(), board)) {
				for (auto a : negras) {
					if (a->getTipo() == 1 && a->get_pos() == Punto2D({ 10,8 })) {
						a->setPos({ 8,8 });
					}
				}
				mov = 1;
			}
			else aux = n->mueve(Click, n->getVectorPosibles(),board);

			if (aux)
			{
				if (n->get_pos().x == 1) {
					p = n->promocionar(n->get_pos());
					comp = Promocion(p, n, t, v);
				}

				//Se realiza el método de comer una vez se ha movido comprobando las piezas negras
				comer(blancas, n);

				mov = aux;
				MueveSonido();
			}
			if (comp) break;
		}
	}
	comprobEnroqueCorto();
	comprobEnroqueLargo();
}

void Game::ClearSelec()
{
	//Se limpian todas las casillas que eran posibles o comestibles
	for (double i = 1; i <= fil; i++) {
		for (double j = 1; j <= col; j++) board.getTile({ j,i }).setposible(false), board.getTile({ j,i }).setcomestible(false);
	}
}

bool Game::Promocion(int tipo, piece *pieza, int t, int v)
{

	switch (tipo)
	{
	case 1:
		if (!pieza->getColor()) 
		{
			negras.agregar(new Queen(pieza->get_pos() , pieza->getColor(), t, v));
			negras.eliminar(pieza);
		}
		else
		{
			blancas.agregar(new Queen( pieza->get_pos() , pieza->getColor(), t, v));
			blancas.eliminar(pieza);
		}
			return true;
		break;

	case 2:
		if (!pieza->getColor()) 
		{
			negras.agregar(new Bishop({ pieza->get_pos() }, pieza->getColor(), t, v));
			negras.eliminar(pieza);
		}
		else
		{
			blancas.agregar(new Bishop({ pieza->get_pos() }, pieza->getColor(), t, v));
			blancas.eliminar(pieza);
		}
			return true;
		break;

	case 3:
		if (!pieza->getColor())
		{
			negras.agregar(new Rook({ pieza->get_pos() }, pieza->getColor(), t, v));
			negras.eliminar(pieza);
		}
		else
		{
			blancas.agregar(new Rook({ pieza->get_pos() }, pieza->getColor(), t, v));
			blancas.eliminar(pieza);
		}
			return true;
		break;

	case 4:
		if (!pieza->getColor()) 
		{
			negras.agregar(new Knight({ pieza->get_pos() }, pieza->getColor(), t, v));
			negras.eliminar(pieza);
		}
		else
		{
			blancas.agregar(new Knight({ pieza->get_pos() }, pieza->getColor(), t, v));
			blancas.eliminar(pieza);
		}
			return true;
		break;

	case 5:
		if (!pieza->getColor()) 
		{
			negras.agregar(new Archbishop({ pieza->get_pos() }, pieza->getColor(), t, v));
			negras.eliminar(pieza);
		}
		else
		{
			blancas.agregar(new Archbishop({ pieza->get_pos() }, pieza->getColor(), t, v));
			blancas.eliminar(pieza);
		}
		return true;
		break;

	case 6:
		if (!pieza->getColor())
		{
			negras.agregar(new Chancellor({ pieza->get_pos() }, pieza->getColor(), t, v));
			negras.eliminar(pieza);
			
		}
		else 
		{
			blancas.agregar(new Chancellor({ pieza->get_pos() }, pieza->getColor(), t, v));
			blancas.eliminar(pieza);
		}
		return true;
		break;
	}
	return false;
}

bool Game::comprobEnroqueCorto()
{
	//Blancas
	bool rookb = 0, kingb = 0, vaciob = 1; //Condiciones a tener en cuenta
	Punto2D c1b = { 7,1 }, c2b = { 8,1 }, c3b = { 9,1 }; //Coordenadas que deben estar vacias
	//Negras
	bool rookn = 0, kingn = 0, vacion = 1; //Condiciones a tener en cuenta
	Punto2D c1n = { 7,8 }, c2n = { 8,8 }, c3n = { 9,8 }; //Coordenadas que deben estar vacias

	for (auto k : blancas) {
		if (k->getTipo() == 1 && !k->getMov1() && k->get_pos().z == 10) rookb = 1; //Torre * No movida * TorreEnrroqueCorto
		if (k->getTipo() == 4 && !k->getMov1()) kingb = 1;
		if (vaciob == 1) k->get_pos() == c1b ? vaciob = 0 : (k->get_pos() == c2b ? vaciob = 0 : (k->get_pos() == c3b ? vaciob = 0 : vaciob = 1));
		if (vacion == 1) k->get_pos() == c1n ? vacion = 0: (k->get_pos() == c2n ? vacion = 0 : (k->get_pos() == c3n ? vacion = 0 : vacion = 1));
	}
	for (auto k : negras) {
		if (k->getTipo() == 1 && !k->getMov1() && k->get_pos().z == 10) rookn = 1; //Torre * No movida * TorreEnrroqueCorto
		if (k->getTipo() == 4 && !k->getMov1()) kingn = 1;
		if (vaciob == 1) k->get_pos() == c1b ? vaciob = 0 : (k->get_pos() == c2b ? vaciob = 0 : (k->get_pos() == c3b ? vaciob = 0 : vaciob = 1));
		if (vacion == 1) k->get_pos() == c1n ? vacion = 0 : (k->get_pos() == c2n ? vacion = 0 : (k->get_pos() == c3n ? vacion = 0 : vacion = 1));
	}

	if (rookb == 1 && kingb == 1 && vaciob == 1) { for (auto k : blancas) if (k->getTipo() == 4) k->set_EnroqueCorto(true);}
	else { for (auto k : blancas) if (k->getTipo() == 4) k->set_EnroqueCorto(false);}
	if (rookn == 1 && kingn == 1 && vacion == 1) { for (auto k : negras) if (k->getTipo() == 4) k->set_EnroqueCorto(true);}
	else { for (auto k : negras) if (k->getTipo() == 4) k->set_EnroqueCorto(false);}

	if ((rookb == 1 && kingb == 1 && vaciob == 1) || (rookn == 1 && kingn == 1 && vacion == 1))return true;
	else return false;
}

bool Game::comprobEnroqueLargo()
{
	//Blancas
	bool rookb = 0, kingb = 0, vaciob = 1; //Condiciones a tener en cuenta
	Punto2D c1b = { 5,1 }, c2b = { 4,1 }, c3b = { 3,1 }, c4b = { 2,1 }; //Coordenadas que deben estar vacias
	//Negras
	bool rookn = 0, kingn = 0, vacion = 1; //Condiciones a tener en cuenta
	Punto2D c1n = { 5,8 }, c2n = { 4,8 }, c3n = { 3,8 }, c4n = { 2,8 }; //Coordenadas que deben estar vacias

	for (auto k : blancas) {
		if (k->getTipo() == 1 && !k->getMov1() && k->get_pos().z == 1) rookb = 1; //Torre * No movida * TorreEnrroqueLargo
		if (k->getTipo() == 4 && !k->getMov1()) kingb = 1;
		if (vaciob == 1) k->get_pos() == c1b ? vaciob = 0 : (k->get_pos() == c2b ? vaciob = 0 : (k->get_pos() == c3b ? vaciob = 0 : (k->get_pos() == c4b ? vaciob = 0 : vaciob = 1)));
		if (vacion == 1) k->get_pos() == c1n ? vacion = 0 : (k->get_pos() == c2n ? vacion = 0 : (k->get_pos() == c3n ? vacion = 0 : (k->get_pos() == c4n ? vacion = 0 : vacion = 1)));
	}
	for (auto k : negras) {
		if (k->getTipo() == 1 && !k->getMov1() && k->get_pos().z == 1) rookn = 1; //Torre * No movida * TorreEnrroqueLargo
		if (k->getTipo() == 4 && !k->getMov1()) kingn = 1;
		if (vaciob == 1) k->get_pos() == c1b ? vaciob = 0 : (k->get_pos() == c2b ? vaciob = 0 : (k->get_pos() == c3b ? vaciob = 0 : (k->get_pos() == c4b ? vaciob = 0 : vaciob = 1)));
		if (vacion == 1) k->get_pos() == c1n ? vacion = 0 : (k->get_pos() == c2n ? vacion = 0 : (k->get_pos() == c3n ? vacion = 0 : (k->get_pos() == c4n ? vacion = 0 : vacion = 1)));
	}

	if (rookb == 1 && kingb == 1 && vaciob == 1) { for (auto k : blancas) if (k->getTipo() == 4) k->set_EnroqueLargo(true); }
	else { for (auto k : blancas) if (k->getTipo() == 4) k->set_EnroqueLargo(false); }
	if (rookn == 1 && kingn == 1 && vacion == 1) { for (auto k : negras) if (k->getTipo() == 4) k->set_EnroqueLargo(true); }
	else { for (auto k : negras) if (k->getTipo() == 4) k->set_EnroqueLargo(false); }

	if ((rookb == 1 && kingb == 1 && vaciob == 1) || (rookn == 1 && kingn == 1 && vacion == 1))return true;
	else return false;
}

bool Game::comprobJaque(bool c)
{
	bool bit = 0;
	if (c)
	{
		for (auto b : blancas) {
			if (b->getTipo() == 4) {
				for (auto n : negras) {
					n->getPosibles(board);
					for (int i = 0; i < n->getVectorPosibles().size(); i++)
						if (b->get_pos() == n->getVectorPosibles()[i]) bit = 1;
					n->cleanVector();
					ClearSelec();
					if (bit) return 1;
				}
				return 0;
			}
		}
	}
	if (!c)
	{
		for (auto n : negras) {
			if (n->getTipo() == 4) {
				for (auto b : blancas) {
					b->getPosibles(board);
					for (int i = 0; i < b->getVectorPosibles().size(); i++)
						if (n->get_pos() == b->getVectorPosibles()[i]) bit = 1;
					b->cleanVector();
					ClearSelec();
					if (bit)return 1;
				}
				return 0;
			}
		}
	}
}

void Game::Comer()
{
	int	valor = ETSIDI::lanzaDado(5); //valor valdra entre 0 y 5 entero

	switch (valor)
	{
	case 0: ETSIDI::play("resources/sounds/disparo/s1.wav"); valor = 10; break;
	case 1: ETSIDI::play("resources/sounds/disparo/s2.wav"); valor = 10; break;
	case 2: ETSIDI::play("resources/sounds/disparo/s3.wav"); valor = 10; break;
	case 3: ETSIDI::play("resources/sounds/disparo/s4.wav"); valor = 10; break;
	case 4: ETSIDI::play("resources/sounds/disparo/s5.wav"); valor = 10; break;
	case 5: ETSIDI::play("resources/sounds/disparo/s6.wav"); valor = 10; break;
		
	}
}

//IMPLEMENTACIÓN DE COMER LAS PIEZAS. SI LA POSICIÓN DE LA PIEZA QUE SE HA MOVIDO ES LA MISMA QUE LA CONTRARIA, SE ELIMINA LA CONTRARIA

void Game::comer(ListaPiezas& p1, piece* p2)
{
	for (auto n : p1)
	{
		if (n->get_pos() == p2->get_pos())
		{
			p1.eliminar(n);
			break;
		}
	}
}

