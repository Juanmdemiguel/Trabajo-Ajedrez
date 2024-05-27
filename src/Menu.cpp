#include "Menu.h"

void Menu::iniciaMenu(bool menu, bool sonido)
{
	if (comienzo) {
		musica(sonido);
		comienzo = false;
	}

	//Para probar más ventanas, con el inicializador

	if (ventana == 0 || ventana == 1) //Menú inicial o menú TEMÁTICA
	{
		dibujaFondo();

		comentario1.setEsquina({ 5, 10 }); //ArI
		comentario1.dibuja(true, sonido, ventana, 1);
		comentario2.setEsquina({ 5,5 }); //ArD
		comentario2.dibuja(true, sonido, ventana, 2);
		comentario3.setEsquina({ 3, 10 }); //AbI
		comentario3.dibuja(true, sonido, ventana, 3);
		comentario4.setEsquina({ 3,5 }); //AbD
		comentario4.dibuja(true, sonido, ventana, 4);

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		glEnable(GL_TEXTURE_2D);

	}
	else
	{
		dibujaFondo();

		comentario1.setEsquina({ 8, 8 }); //Ar
		comentario1.dibuja(true, sonido, ventana, 1);
		comentario2.setEsquina({ 5,8 }); //Ab
		comentario2.dibuja(true, sonido, ventana, 2);

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

		glEnable(GL_TEXTURE_2D);
	}

}


void Menu::dibujaFondo()
{
	glEnable(GL_TEXTURE_2D);

	Tema();

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);

	glTexCoord2d(1, 1);    glVertex3f(0, 0, -0.1);
	glTexCoord2d(0, 1);    glVertex3f(0, 16, -0.1);
	glTexCoord2d(0, 0);    glVertex3f(12, 16, -0.1);
	glTexCoord2d(1, 0);    glVertex3f(12, 0, -0.1);

	glEnd();
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

void Menu::Tema()
{
	switch (tematica)
	{
	case 0: glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/MenuPpal.png").id); break;
	case 1: glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/Arturito.png").id); break;
	case 2: //glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/MenuPpal2.png").id); 
		break;
	}
}