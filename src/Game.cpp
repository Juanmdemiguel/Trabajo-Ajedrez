#include"Game.h"


void Game::dibujaJuego(int tema, int vision) {	//Funcion dibujaJuego provisional, se a�ade a clase Juego/Game cuando se desarrolle

	//Dibuja el tablero
	board.dibuja(tema);

	//Dibuja las piezas seg�n la tem�tica y modo de visualizaci�n
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
	double tiempo; //No necesario almacenar el tiempo 0, se crea esta variable auxiliar que se destruye al final de inicializa
	tiempo = cronometro(0);

	//Se establece el turno inicial para las blancas
	turno = true;

	//Se resetea la puntuaci�n
	setPuntuacion();

	//Agrega los peones de los dos colores
	for (double i = 1; i <= 10; ++i) {
		blancas.agregar(new Pawn({ i,2 }, 1, t, v));
		negras.agregar(new Pawn({ i,7 }, 0, t, v));
	}

	//Agrega las piezas blancas
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

	//Agrega las piezas negras
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

	//Resetea el final del juego para que solo se active cuando toque
	finJuego = false;
}


void Game::selecciona(int t, int v, bool cambio)
{
	bool aux{}, comp{};
	int p = 0;

	if (turno && !cambio) {
		for (auto b : blancas) {
			if (b->get_pos() == Click) {
				b->cleanVector();
				b->getPosibles(board);
			}
			Limitador(1);

			if (Click == Punto2D({ 2,1 }) && b->getTipo() == 4 && comprobEnroqueLargo() && b->mueve(Click, b->getVectorPosibles(), board)) {
				for (auto a : blancas) {
					if (a->getTipo() == 1 && a->get_pos() == Punto2D({ 1,1 })) {
						a->setPos({3,1});
						board.getTile({1,1}).setocupada(2);
						board.getTile({3,1}).setocupada(1);
					}
				}
				mov = 1;
				MueveSonido();
			}
			if (Click == Punto2D({ 9, 1}) && b->getTipo() == 4 && comprobEnroqueCorto() && b->mueve(Click, b->getVectorPosibles(), board)) {
				for (auto a : blancas) {
					if (a->getTipo() == 1 && a->get_pos() == Punto2D({10,1}) ) {
						a->setPos({ 8,1 });
						board.getTile({ 10,1 }).setocupada(2);
						board.getTile({ 8,1 }).setocupada(1);
					}
				}
				mov = 1;
				MueveSonido();
			}

			else aux = b->mueve(Click, b->getVectorPosibles(), board);

			if (aux)
			{
				//Se realiza el m�todo de comer una vez se ha movido comprobando las piezas blancas, y si se ha comido se gestiona el sonido al comer
				if (comer(negras, b)) SonidoComer();

				if (b->get_pos().x == 8) {
					b->setPromocion();

					//Se activa la promoci�n para gestionarlo en el coordinador
					if(b->getPromocion())promocionActivada = true;
				}

				mov = aux;
				MueveSonido();
			}
			if (comp) break;
		}

		//El juego finaliza cuando hay jaque mate, ganan las blancas
		if (mov)
		{
			comprobJaqueMate(0);

			//Gesti�n del fin del juego
			if (comprobJaqueMate(0))
			{
				//Ganan blancas
				QuienGana = true;
				//Se eliminan las piezas sobrantes
				eliminarPiezas();
				//Se limpian las casillas del tablero
				ClearCasillas();
				//Finaliza el juego
				finJuego = true;
			}
		}
	}

	if (!turno && !cambio) {

		for (auto n : negras) {
			if (n->get_pos() == Click) {
				n->cleanVector();
				n->getPosibles(board);
			}
			Limitador(0);

			//Realiza el enroque
			if (Click == Punto2D({ 2,8 }) && n->getTipo() == 4 && comprobEnroqueLargo() && n->mueve(Click, n->getVectorPosibles(), board)) {
				for (auto a : negras) {
					if (a->getTipo() == 1 && a->get_pos() == Punto2D({ 1,8 })) {
						a->setPos({ 3,8 });
						board.getTile({ 1,8 }).setocupada(2);
						board.getTile({ 3,8 }).setocupada(0);
					}
				}
				mov = 1;
				MueveSonido();
			}

			//Realiza el enroque
			if (Click == Punto2D({ 9, 8 }) && n->getTipo() == 4 && comprobEnroqueCorto() && n->mueve(Click, n->getVectorPosibles(), board)) {
				for (auto a : negras) {
					if (a->getTipo() == 1 && a->get_pos() == Punto2D({ 10,8 })) {
						a->setPos({ 8,8 });
						board.getTile({ 10,8 }).setocupada(2);
						board.getTile({ 8,8 }).setocupada(0);
					}
				}
				mov = 1;
				MueveSonido();
			}
			else aux = n->mueve(Click, n->getVectorPosibles(),board);

			if (aux)
			{
				//Se realiza el m�todo de comer una vez se ha movido comprobando las piezas negras, y si se ha comido se gestiona el sonido al comer
				if (comer(blancas, n)) SonidoComer();

				if (n->get_pos().x == 1) {
					n->setPromocion();

					//Se activa la promoci�n para gestionarlo en el coordinador
					if (n->getPromocion())promocionActivada = true;
				}
				mov = aux;
				MueveSonido();
			}
			if (comp) break;
		}

		//El juego finaliza cuando hay jaque mate, ganan las negras
		if (mov)
		{
			comprobJaqueMate(1);

			//Gesti�n del fin del juego
			if (comprobJaqueMate(1))
			{
				//Ganan negras
				QuienGana = false;
				//Elimina las piezas sobrantes
				eliminarPiezas();
				//Se limpian las casillas del tablero
				ClearCasillas();
				//Finaliza el juego
				finJuego = true;
			}
		}
	}
	//Comprueba el enroque
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

//Realiza la promoci�n del pe�n para todo el tipo de piezas
void Game::Promocion(int t, int v, unsigned char key)
{
	for (auto b : blancas) {
		if (b->get_pos().x == 8 && b->getTipo() == 0) {
			switch (key)
			{
			case 'Q':case 'q':
				blancas.agregar(new Queen(b->get_pos(), b->getColor(), t, v));
				blancas.eliminar(b);
				promocionRealizada = true;
				promocionActivada = false;
				break;

			case 'B':case 'b':
				blancas.agregar(new Bishop({ b->get_pos() }, b->getColor(), t, v));
				blancas.eliminar(b);
				promocionRealizada = true;
				promocionActivada = false;
				break;

			case 'R':case 'r':
				blancas.agregar(new Rook({ b->get_pos() }, b->getColor(), t, v));
				blancas.eliminar(b);
				promocionRealizada = true;
				promocionActivada = false;
				break;

			case 'K':case 'k':
				blancas.agregar(new Knight({ b->get_pos() }, b->getColor(), t, v));
				blancas.eliminar(b);
				promocionRealizada = true;
				promocionActivada = false;
				break;

			case 'A':case 'a':
				blancas.agregar(new Archbishop({ b->get_pos() }, b->getColor(), t, v));
				blancas.eliminar(b);
				promocionRealizada = true;
				promocionActivada = false;
				break;

			case 'C':case 'c':
				blancas.agregar(new Chancellor({ b->get_pos() }, b->getColor(), t, v));
				blancas.eliminar(b);
				promocionRealizada = true;
				promocionActivada = false;
				break;
			}
		}
		if (promocionRealizada == true)break;
	}

	for (auto n : negras) {
		if (n->get_pos().x == 1 && n->getTipo() == 0) {
			switch (key)
			{
			case 'Q':case 'q':
				negras.agregar(new Queen(n->get_pos(), n->getColor(), t, v));
				negras.eliminar(n);
				promocionRealizada = true;
				promocionActivada = false;
				cout << "salgo";
				break;

			case 'B':case 'b':
				negras.agregar(new Bishop({ n->get_pos() }, n->getColor(), t, v));
				negras.eliminar(n);
				promocionRealizada = true;
				promocionActivada = false;
				break;

			case 'R':case 'r':
				negras.agregar(new Rook({ n->get_pos() }, n->getColor(), t, v));
				negras.eliminar(n);
				promocionRealizada = true;
				promocionActivada = false;
				break;

			case 'K':case 'k':
				negras.agregar(new Knight({ n->get_pos() }, n->getColor(), t, v));
				negras.eliminar(n);
				promocionRealizada = true;
				promocionActivada = false;
				break;

			case 'A':case 'a':
				negras.agregar(new Archbishop({ n->get_pos() }, n->getColor(), t, v));
				negras.eliminar(n);
				promocionRealizada = true;
				promocionActivada = false;
				break;

			case 'C':case 'c':
				negras.agregar(new Chancellor({ n->get_pos() }, n->getColor(), t, v));
				negras.eliminar(n);
				promocionRealizada = true;
				promocionActivada = false;
				break;
			}
		}
		if (promocionRealizada == true)break;
	}
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

bool Game::comprobJaque(bool c, bool& DAmenaza, Punto2D& Maton)
{
	bool bit = 0, once = false;
	vector <piece*> amenazas;
	if (c)
	{
		for (auto b : blancas) {
			if (b->getTipo() == 4) {
				for (auto n : negras) {
					n->getPosibles(board);
					for (int i = 0; i < n->getVectorPosibles().size(); i++)
						if (b->get_pos() == n->getVectorPosibles()[i]) { 
							bit = 1;
							if(!once) amenazas.push_back(n), once = true;
						}
					n->cleanVector();
					ClearSelec();

				}
				if (amenazas.size() == 1) { //Si te amenaza uno puedes guardar su posici�n para su gesti�n en el jaque mate
					Maton.z = amenazas[0]->get_pos().z;
					Maton.x = amenazas[0]->get_pos().x;
				}
				if (amenazas.size() == 0) Maton = { 0.0,0.0 };
				
				if (bit)
				{
					bool coincidente{};
					for (auto b : blancas)
						if (b->get_pos() == Maton) coincidente = true;
					if (coincidente) return false;
					else {
						return 1;
					}
				}
				else return 0;
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
						if (n->get_pos() == b->getVectorPosibles()[i]) {
							bit = 1;
							if (!once) amenazas.push_back(b), once = true;
						}
					b->cleanVector();
					ClearSelec();
				}
				if (amenazas.size() == 1) { //Si te amenaza uno puedes guardar su posici�n para su gesti�n en el jaque mate

					Maton.z = amenazas[0]->get_pos().z;
					Maton.x = amenazas[0]->get_pos().x;
				}


				if (amenazas.size() == 0) Maton = { 0.0,0.0 };
				if (bit)
				{
					bool coincidente{};
					for (auto n : negras)
						if (n->get_pos() == Maton) coincidente = true;
					if (coincidente) return false;
					else {
						return 1;
					}
					
				}


				else return 0;
			}
		}
	}
}

void Game::SonidoComer()
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

//IMPLEMENTACI�N DE COMER LAS PIEZAS. SI LA POSICI�N DE LA PIEZA QUE SE HA MOVIDO ES LA MISMA QUE LA CONTRARIA, SE ELIMINA LA CONTRARIA

bool Game::comer(ListaPiezas& p1, piece* p2)	//Comida y la que come
{
	double tiempo{};

	for (auto n : p1)
	{
		if (n->get_pos() == p2->get_pos())
		{
			tiempo = cronometro(1);
			if (p2->getColor()) jugador1 = jugador1 + asignaPuntos(n->getTipo(), tiempo);
			else jugador2 = jugador2 + asignaPuntos(n->getTipo(), tiempo);

			p1.eliminar(n);

			return 1;
			break;
		}
	}
	return 0;
}

	

bool Game::comprobJaqueMate(bool c)
{
	bool bit = 0, DobleAmenaza = 0, limit{};
	Punto2D Maton;

	if (comprobJaque(1, DobleAmenaza, Maton) && c) {
		ETSIDI::play("resources/sounds/jaque/violin.wav");
		limit = Limitador(c);
		if (!limit) return 0;
		else
		{
			if (MataMaton(Maton, c)) return false;
			else
			{
				if (RompeRuta(Maton, c)) return false;
				else return true;
			}
		}
	}

	if (comprobJaque(0, DobleAmenaza, Maton) && !c) {
		ETSIDI::play("resources/sounds/jaque/violin.wav");
		limit = Limitador(c);
		if (!limit) return 0;
		else
		{
			if (MataMaton(Maton, c)) return false;
			else
			{
				if (RompeRuta(Maton, c)) return false;
				else return true;
				
			}
		}
	}
}

bool Game::MataMaton(Punto2D Maton, bool color) {

	bool bit = 0;
	if (color)
	{
		for (auto b : blancas) {
			b->getPosibles(board);
			for (int i = 0; i < b->getVectorPosibles().size(); i++)
				if (Maton == b->getVectorPosibles()[i]) bit = 1, cout << "Comematon" << endl;
				b->cleanVector();
				ClearSelec();
				if (bit) return 1;
				}
				 return 0;
	}
	if (!color)
	{
		for (auto n : negras) {
			n->getPosibles(board);
			for (int i = 0; i < n->getVectorPosibles().size(); i++)
				if (Maton == n->getVectorPosibles()[i]) bit = 1;
			n->cleanVector();
			ClearSelec();
			if (bit) return 1;
		}
		return 0;
	}
}


int Game::asignaPuntos(int pieza_comida, double tiempo)
{
	//Se implementa el tiempo para que las acciones de comer antes de 10 minutos punt�en m�s que pasado este tiempo
	switch (pieza_comida)
	{
	case 0:	return (tiempo >= 600) ? 5 : 10;		//pe�n
	case 1:	return (tiempo >= 600) ? 15 : 30;		//torre
	case 2:	return (tiempo >= 600) ? 15 : 30;		//alfil
	case 3:	return (tiempo >= 600) ? 15 : 30;		//caballo
	case 4:	break;									//rey no se come
	case 5:	return (tiempo >= 600) ? 35 : 70;		//reina
	case 6:	return (tiempo >= 600) ? 25 : 50;		//arzobispo
	case 7:	return (tiempo >= 600) ? 25 : 50;		//canciller
	}
}

 bool Game::Limitador(bool c)
{
	Punto2D maton{ 0,0 };//Variables inutiles
	bool dobleamenaza, retorno = true;
	if (c) {
		for (auto b : blancas) {
			if (b->get_pos() == Click) {
				b->cleanVector();
				b->getPosibles(board);
				if (b->getVectorPosibles().size() >= 1) { //Condiciones de funcionamiento
					Punto2D origen = b->get_pos(); //Guarda la posici�n del rey
					board.getTile(origen).setocupada(2); //Vacio la casilla del rey
					for (int r = 0; r < b->getVectorPosibles().size(); r++) {
						b->setPos(b->getVectorPosibles()[r]);  //Cambia la posicion del rey a una de sus posibles
						if (board.getTile(b->get_pos()).getocupada() == 0) {//Funcionamiento distinto si es una casilla vacia o enemiga
							board.getTile(b->get_pos()).setocupada(1);
							if (comprobJaque(1, dobleamenaza, maton)) { //Si el rey estuviera en posicion de peligro, elimina esa posibilidad
								b->cleanCasillaVector(b->getVectorPosibles()[r]);
								r--;
							}
							else retorno = false;
							board.getTile(b->get_pos()).setocupada(0);
						}
						else { //Caso en el que la casilla a la que se mueve est� vacia
							board.getTile(b->get_pos()).setocupada(1);
							if (comprobJaque(1, dobleamenaza, maton)) {
								b->cleanCasillaVector(b->getVectorPosibles()[r]);
								r--;
							}
							else retorno = false;
							board.getTile(b->get_pos()).setocupada(2);
						}
					}
					b->setPos(origen); //Reubico al rey a donde se encontraba antes
					board.getTile(origen).setocupada(1);
					ClearSelec();//Borra visualmente las posibles de las negras
					for (int i = 0; i < b->getVectorPosibles().size(); ++i) {
						if (board.getTile(b->getVectorPosibles()[i]).getocupada() == 2) board.getTile(b->getVectorPosibles()[i]).setposible(true); //Activo visualmente las posibles
						else board.getTile(b->getVectorPosibles()[i]).setcomestible(true);
					}
						
				}
			}
		}

	}
	if (!c) {
		for (auto n : negras) {
			if (n->get_pos() == Click) {
				n->cleanVector();
				n->getPosibles(board);
				if (n->getVectorPosibles().size() >= 1) {
					Punto2D origen = n->get_pos();
					board.getTile(origen).setocupada(2);
					for (int r = 0; r < n->getVectorPosibles().size(); r++) {
						n->setPos(n->getVectorPosibles()[r]);
						if (board.getTile(n->get_pos()).getocupada() == 1) {
							board.getTile(n->get_pos()).setocupada(0);
							if (comprobJaque(0, dobleamenaza, maton)) {
								n->cleanCasillaVector(n->getVectorPosibles()[r]);
								r--;
							}
							else retorno = false;
							board.getTile(n->get_pos()).setocupada(1);
						}
						else {
							board.getTile(n->get_pos()).setocupada(0);
							if (comprobJaque(0, dobleamenaza, maton)) {
								n->cleanCasillaVector(n->getVectorPosibles()[r]);
								r--;
							}
							else retorno = false;
							board.getTile(n->get_pos()).setocupada(2);
						}
					}
					n->setPos(origen);
					board.getTile(origen).setocupada(0);
					ClearSelec();//Borra visualmente las posibles de las negras
					for (int i = 0; i < n->getVectorPosibles().size(); ++i) {
						if (board.getTile(n->getVectorPosibles()[i]).getocupada() == 2) board.getTile(n->getVectorPosibles()[i]).setposible(true); //Activo visualmente las posibles
						else board.getTile(n->getVectorPosibles()[i]).setcomestible(true);
					}
						
				}
			}
		}

	}
	return retorno;
}

vector <Punto2D> Game::RutaMaton(Punto2D maton, bool color)
{
	vector<Punto2D> conexion;
	if (color)
	{
		for (auto b : blancas)
		{
			if (b->getTipo() == 4)
			{
				if (b->get_pos().z == maton.z) //Reconoce que el maton y el rey estan alineaados horizontalmente
				{
					if (b->get_pos().x > maton.x)
					{
						for (auto i = maton.x + 1; i < b->get_pos().x; ++i)
							conexion.push_back({ maton.z, i });
					}
					if (b->get_pos().x < maton.x)
					{
						for (auto i = b->get_pos().x + 1; i < maton.x; ++i)
							conexion.push_back({ maton.z ,i});
					}
				}
				else if (b->get_pos().x == maton.x) //Reconoce que el maton y el rey estan alineaados verticalmente
				{
					if (b->get_pos().z > maton.z)
					{
						for (auto i = maton.z + 1; i < b->get_pos().z; ++i)
							conexion.push_back({ i, maton.x });
					}
					if (b->get_pos().z < maton.z)
					{
						for (auto i = b->get_pos().z + 1; i < maton.z; ++i)
							conexion.push_back({ i, maton.x });
					}
				}
				else {
					if (maton.z < b->get_pos().z && maton.x > b->get_pos().x)
					{
						for (auto i = maton.z + 1; i < b->get_pos().z; i++)
							conexion.push_back({ i, maton.x - (i - maton.z) });
					}

					if (maton.z > b->get_pos().z && maton.x > b->get_pos().x)
					{
						for (auto i = b->get_pos().z + 1; i < maton.z; i++)
							conexion.push_back({ i, b->get_pos().x + (i - b->get_pos().z) });
					}

					if (maton.z > b->get_pos().z && maton.x < b->get_pos().x)
					{
						for (auto i = b->get_pos().z + 1; i < maton.z; i++)
							conexion.push_back({ i, b->get_pos().x - (i - b->get_pos().z) });
					}
					if (maton.z < b->get_pos().z && maton.x < b->get_pos().x)
					{
						for (auto i = maton.z + 1; i < b->get_pos().z; i++)
							conexion.push_back({ i, maton.x + (i - maton.z) });
					}
				}
			}

		}
	}
	for (auto i : conexion)
		cout << i.z << " " << i.x << endl;
	return conexion;
}

bool Game::RompeRuta(Punto2D maton, bool color)
{
	vector<Punto2D> ruta = RutaMaton(maton, color);

	if (color)
	{
		for (auto b : blancas)
		{
			if (b->getTipo() != 4) {
			b->getPosibles(board);
			for (int i = 0; i < b->getVectorPosibles().size(); i++)
			{
				for (int j = 0; j < ruta.size(); ++j)
				{
					if (ruta[j] == b->getVectorPosibles()[i])
						return 1;
				}
			}

			b->cleanVector();
			ClearSelec();
			}
		}
		return 0;
	}
	if (!color)
	{
		for (auto n : negras)
		{
			n->getPosibles(board);
			for (int i = 0; i < n->getVectorPosibles().size(); i++)
			{
				for (int j = 0; j < ruta.size(); ++j)
				{
					if (ruta[j] == n->getVectorPosibles()[i])
						return 1;
				}
			}

			n->cleanVector();
			ClearSelec();
		}
		return 0;
	}
}

void Game::eliminarPiezas()
{
	blancas.destruir_contenido();
	negras.destruir_contenido();
}

void Game::ClearCasillas()
{
	for (double i = 1; i <= fil; i++) {
		for (double j = 1; j <= col; j++)
		{
			//Se limpian todas las casillas que eran posibles o comestibles
			board.getTile({ j,i }).setposible(false);
			board.getTile({ j,i }).setcomestible(false);

			//Se ocupan las casillas por las piezas correspondientes de nuevo
			if (i == 1 || i == 2)
				board.getTile({ j,i }).setocupada(1);
			else if (i == 8 || i == 7)
				board.getTile({ j,i }).setocupada(0);
			else
				board.getTile({ j,i }).setocupada(2);
		}
	}
}