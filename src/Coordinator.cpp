#include "Coordinator.h"

void Coordinator::Dibuja()
{
	camara.dibuja(principal);
	principal.getMenu() ? principal.iniciaMenu() : juego.dibujaJuego();
	//El operador ternario llama a iniciaMenu si el booleano menu es true, si no, dibuja el juego

	drawEsferadePruebas(esfera.x, esfera.z);
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
		if(!principal.getMenu()) juego.musica(principal.getSonido(), music);
		

		if (_button == GLUT_LEFT_BUTTON) //Solo si se pulsa el botón izquierdo del ratón
		{
			//Seleccion de la casilla
			raton.seleccion(juego, _button, state);
		}
	}

	
	

}

void Coordinator::Inicializa() 
{
	ETSIDI::playMusica("resources/sounds/menu.mp3", true);

	//Switch de modo de juego
	char cancion[] = "resources/sounds/marchav2.mp3";
	//Fin de switch
	strcpy_s(music, cancion);
}

void Coordinator::Mouse(int x, int y1)
{
	raton.movimiento(x, y1, juego, esfera, principal.getMenu());
}

void Coordinator::Teclado(unsigned char key, int x_t, int y_t)
{
	camara.zoom(principal, key);
	camara.actuador(principal, key);
	camara.vertical(principal, key);
	camara.cambio_modo_libre(principal, key);
}

void Coordinator::Temp(int value)
{
	camara.rota(principal);
}