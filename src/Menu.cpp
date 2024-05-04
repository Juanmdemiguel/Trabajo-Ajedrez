#include "Menu.h"

void Menu::iniciaMenu(bool menu, bool sonido)
{
	glEnable(GL_TEXTURE_2D);

	sonido ? glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/menu.png").id): glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/menusin.png").id);
	
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);    glVertex3f(-10, 0, -0.1);
	glTexCoord2d(1, 1);    glVertex3f(10, 0, -0.1);
	glTexCoord2d(1, 0);    glVertex3f(10, 15, -0.1);
	glTexCoord2d(0, 0);    glVertex3f(-10, 15, -0.1);
	glEnd();

	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
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
	(sonido == true) ? ETSIDI::playMusica("resources/sounds/menu.mp3", true) : ETSIDI::stopMusica();
}