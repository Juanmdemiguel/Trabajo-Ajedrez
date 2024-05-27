#include "Coordinator.h"

void Coordinator::Dibuja()
{
	camara.dibuja(principal);
	principal.getMenu() ? principal.iniciaMenu(principal.getMenu(), principal.getSonido()) : juego.dibujaJuego();
	//El operador ternario llama a iniciaMenu si el booleano menu es true, si no, dibuja el juego

	drawEsferadePruebas(esfera.x, esfera.z);
}

void Coordinator::Click(int _button, int state, int _x, int _y)
{	

	if (_button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		// Acciones cuando se hace clic con el botón izquierdo del ratón

		if (principal.getMenu())
		{
			if (principal.getBoton()) principal.setBoton(false); //Al hacer click, si estaba a true, se vuelve a poner a false

			principal.clickBotonesMenu(_x, _y);
			//principal.clickBotonesMenu2(_x, _y, principal.comentario1);
			principal.getMenu() ? principal.musica(principal.getSonido()) : juego.musica(principal.getSonido(), music);
		}
		

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