#include "Coordinator.h"

void Coordinator::Dibuja()
{
	camara.dibuja(principal);
	switch (estado) 
	{
	case Estado::MENU:
		if (!principal.getMenu()) {
			juego.inicializa(principal.tematica, principal.vision);
			estado = JUEGO;
		}
		else
		principal.iniciaMenu();
		break;
	case Estado::JUEGO:
		juego.dibujaJuego(principal.tematica, principal.vision);
		juego.selecciona();
		PasaTurno();

		if (camara.Cambiando()) juego.ClearSelec();

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
			
			if ((raton.getCoordenadaZ() > (5 - 1.5)) && (raton.getCoordenadaZ() < 5) && (raton.getCoordenadaX() > (10 - 4)) && (raton.getCoordenadaX() < 10) && principal.ventana == 0)
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
		}

	}
}


void Coordinator::Teclado(unsigned char key, int x_t, int y_t)
{
	camara.zoom(principal, key);
	camara.vertical(principal, key);
	camara.cambio_modo_libre(principal, key);

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