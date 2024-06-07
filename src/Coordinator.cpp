#include "Coordinator.h"


void Coordinator::Dibuja()
{
	camara.dibuja(principal);

	switch (estado) 
	{
	case Estado::MENU:
		if (!principal.getMenu()) {
			juego.inicializa(principal.getTematica(), principal.getVision());
			principal.getVision() ? camara.set_pos(12.0 + 32* cos(3.1416) , 40.0, 15.0 + 32 * sin(3.1416)) : camara.set_pos(11.9, 35.0, 14.9992); //Selecciona la posición de la camara según la visión
			estado = JUEGO;
		}
		else
		principal.iniciaMenu();
		break;

	case Estado::JUEGO:

		fichero = true;

		//Se dibuja el juego según la temática y visión
		juego.dibujaJuego(principal.getTematica(), principal.getVision());

		//Se gestiona el paso de turno
		PasaTurno();

		//Si gira la cámara, se limpian las casillas
		if (camara.Cambiando()) juego.ClearSelec();

		//Se gestiona las puntuaciones
		if (camara.getPuntuaciones()) Puntuaciones();

		//La partida finaliza al realizar jaque mate al jugador contrario, que activa el booleano finPartida.
		if (juego.finPartida()) estado = FIN, camara.setfin(true);
		break;

	case Estado::FIN:
				
		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/Puntuaciones.png").id);

		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);

		glTexCoord2d(1, 1);    glVertex3f(0, 0, -0.1);
		glTexCoord2d(0, 1);    glVertex3f(0, 16, -0.1);
		glTexCoord2d(0, 0);    glVertex3f(12, 16, -0.1);
		glTexCoord2d(1, 0);    glVertex3f(12, 0, -0.1);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		ETSIDI::setTextColor(0, 0, 1);
		ETSIDI::setFont("resources/fuentes/Bitwise.ttf", 20);
		ETSIDI::printxy("FIN DEL JUEGO", 6, 9);
		
		(juego.Ganador()) ? ETSIDI::printxy("GANA EL JUGADOR 1", 6, 8) : ETSIDI::printxy("GANA EL JUGADOR 2", 6, 8);

		ETSIDI::printxy("PRESIONE EL ESPACIO PARA VOLVER AL MENU", 4, 7);

		if (fichero) CreaFicheroPuntuaciones(), fichero = false; //Se guardan las puntuaciones de los jugadores en un fichero

		//Se gestiona la cámara para que pueda rotar al haber ganado el jugador 2
		camara.setRotar(true);
		
		break;

	}
}

void Coordinator::Click(int _button, int state, int _x, int _y)
{	

	if (_button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		// Acciones cuando se hace clic con el botón izquierdo del ratón

		principal.setCoord({ raton.getCoordenadaX(), raton.getCoordenadaZ() }); //Pasar coordenadas click al menú

		if (principal.getMenu())
		{
			if (principal.getBoton()) principal.setBoton(false); //Al hacer click, si estaba a true, se vuelve a poner a false

			principal.clickBotonesMenu();
			
			if ((raton.getCoordenadaZ() > (5 - 1.5)) && (raton.getCoordenadaZ() < 5) && (raton.getCoordenadaX() > (10 - 4)) && (raton.getCoordenadaX() < 10) && principal.getVentana() == 0)
				principal.musica();
		}
		
		static int i= 0;			//Se crea para que se inicialice solo una vez a 0, para comprobar lo siguiente
		if (!principal.getMenu() && i == 0)
		{
			CompruebaMusica();
			juego.musica(principal.getSonido(), music), i++;
		}
			
		if (_button == GLUT_LEFT_BUTTON && estado == JUEGO) //Solo si se pulsa el botón izquierdo del ratón
		{
			//Seleccion de la casilla
			raton.seleccion(juego, _button, state);
			MouseToGame();
			juego.ClearSelec();
			juego.selecciona(principal.getTematica(), principal.getVision(), camara.Cambiando());
		}

	}
}


void Coordinator::Teclado(unsigned char key, int x_t, int y_t)
{
	camara.zoom(principal, key);
	camara.vertical(principal, key);

	if (estado == FIN)
	{
		if (key == ' ') principal.setMenu(true), estado = MENU, camara.setfin(false);
	}

}

void Coordinator::CompruebaMusica()
{
	switch (principal.getTematica())
	{
	case 0:
	{
		char cancion1[] = "resources/sounds/marchav2.mp3";
		strcpy_s(music, cancion1);
		break;
	}
		
	case 1:
	{
		char cancion2[] = "resources/sounds/TunaIndustrialesUPM.mp3";
		strcpy_s(music, cancion2);
		break;
	}
	}
}

void Coordinator::MouseToGame()
{
	juego.SetClick(raton.getClick());
}

void Coordinator::PasaTurno()
{
	if (juego.getMov()) {
		juego.Listo();
		juego.ClearSelec();
		camara.actuador(principal, juego.getMov());
		juego.setMov(false);
	}
}

void Coordinator::Puntuaciones()
{
	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/Puntuaciones.png").id);

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);

	glTexCoord2d(1, 1);    glVertex3f(0, 0, -0.1);
	glTexCoord2d(0, 1);    glVertex3f(0, 16, -0.1);
	glTexCoord2d(0, 0);    glVertex3f(12, 16, -0.1);
	glTexCoord2d(1, 0);    glVertex3f(12, 0, -0.1);
	glEnd();

	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("resources/fuentes/Bitwise.ttf", 20);
	char cadena1[50];
	sprintf_s(cadena1, "%d", juego.PuntosJ1());
	ETSIDI::printxy("JUGADOR 1:", 5, 9);
	ETSIDI::printxy(cadena1, 8, 9);

	char cadena2[50];
	sprintf_s(cadena2, "%d", juego.PuntosJ2());
	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::printxy("JUGADOR 2:", 5, 7);
	ETSIDI::printxy(cadena2, 8, 7);
}

void Coordinator::CreaFicheroPuntuaciones()	// Crea el fichero donde se guardan las puntuaciones
{
	std::string nombre = "ResultadoPartidas.txt";

	bool escribeLineaInicial = false; //Booleano para conocer si el archivo ya existe

	if (!std::filesystem::exists(nombre) || std::filesystem::file_size(nombre) == 0) {
		escribeLineaInicial = true;
	}
	
	std::ofstream archivo(nombre, std::ios::app); // Abrir el archivo sin sobrescribir el contenido

	if (archivo.is_open()) 
	{
		if (escribeLineaInicial) archivo << " Jugador 1 || Jugador 2 " << endl;

		archivo << juego.PuntosJ1() << "||" << juego.PuntosJ2() << endl;
		archivo.close();

		//cout << "Puntuacion final guardada" << endl;
	}
	else {
		cerr << "No se pudo abrir el archivo para escribir" << endl;
	}
}