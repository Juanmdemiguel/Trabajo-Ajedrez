#include "Menu.h"

void Menu::iniciaMenu(bool menu, bool sonido)
{
	//setVentana(2);  //Probar menú de VISIÓN

	if (Ventana == 0 || Ventana == 1) //Menú inicial o menú TEMÁTICA
	{
		//Cuadros de arriba
		comentario1.setPosicionCuadro({6,2.5},{10,4});			//Izqda
		comentario1.setSound();
		comentario1.dibujaComentario(comentario1.getSound(), sonido);
	
		comentario2.setPosicionCuadro({ 11,2.5 }, { 15, 4 });	//Drcha
		comentario2.dibujaComentario(comentario2.getSound(),sonido);

		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("resources/fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("SONIDO", 10, 0, 10);

		//Cuadros de abajo
		comentario3.setPosicionCuadro({ 6,0.5 }, { 10,2 });		//Izqda
		comentario3.dibujaComentario(comentario3.getSound(),sonido);

		comentario4.setPosicionCuadro({ 11,0.5 }, { 15,2 });	//Drcha
		comentario4.dibujaComentario(comentario4.getSound(),sonido);

		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("resources/fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("SONIDO", 10, 0, 10);

		glEnable(GL_TEXTURE_2D);

		//setTematica(1); //Prueba funcionamiento switch case del tema de fondo
		Tema(Tematica);

		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		
		glTexCoord2d(0, 1);    glVertex3f(0, 0, 0);
		glTexCoord2d(1, 1);    glVertex3f(0, 0, 16); //bien
		glTexCoord2d(1, 0);    glVertex3f(12, 0, 16);
		glTexCoord2d(0, 0);    glVertex3f(12, 0, 0);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		glEnable(GL_TEXTURE_2D);
	}
	else
	{
		//Cuadro de arriba
		comentario1.setPosicionCuadro({ 8,6.5 }, { 12,8 });			//2D o 3D
		comentario1.dibujaComentario(comentario1.getSound(), sonido);

		comentario2.setPosicionCuadro({ 8,4 }, { 12, 5.5 });	//VOLVER
		comentario2.dibujaComentario(comentario2.getSound(), sonido);

		/*
		ETSIDI::setTextColor(1, 1, 0);
		ETSIDI::setFont("resources/fuentes/Bitwise.ttf", 16);
		ETSIDI::printxy("SONIDO", 10, 0, 10);
		*/

		glEnable(GL_TEXTURE_2D);

		
		Tema(Tematica);
		
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);

		glTexCoord2d(0, 1);    glVertex3f(0, 0, 0);
		glTexCoord2d(1, 1);    glVertex3f(0, 0, 16); //bien
		glTexCoord2d(1, 0);    glVertex3f(12, 0, 16);
		glTexCoord2d(0, 0);    glVertex3f(12, 0, 0);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		glEnable(GL_TEXTURE_2D);
	}
	
}

void Menu::clickBotonesMenu(double x, double y) // Función primitiva, futuras iteraciones mirar creación de cuadros de texto
// sobre la imagen para tener las coordenadas según cuadro creado
{
	if ((x > 33) && (x < 151) && (y > 488) && (y < 557) && (getBoton() == false))
	{
		setSonido(!getSonido());
		setBoton(true);
	}

	if ((x > 579) && (x < 788) && (y > 483) && (y < 553))
		setMenu(false);
}

void Menu::musica(bool sonido)
{
	(sonido) ? ETSIDI::playMusica("resources/sounds/menu.mp3", true) : ETSIDI::stopMusica();
}

void Menu::Tema(int tema)
{
	switch (tema)
	{
	case 0: glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/MenuPpal.png").id); break;
	case 1: glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/Arturito.png").id); break;
	case 2: //glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/MenuPpal2.png").id); 
		break;
	}
}