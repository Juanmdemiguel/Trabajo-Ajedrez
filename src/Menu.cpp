#include "Menu.h"

void Menu::iniciaMenu()
{
	if (comienzo) {
		//musica();
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

	}
	else
	{
		dibujaFondo();

		comentario5.setEsquina({ 10, 8 }); //Ar
		comentario5.dibuja(true, sonido, ventana, 1);
		comentario6.setEsquina({ 7,8 }); //Medio
		comentario6.dibuja(true, sonido, ventana, 2);
		comentario7.setEsquina({ 4,8 }); //Ab
		comentario7.dibuja(true, sonido, ventana, 3);

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
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void Menu::clickBotonesMenu() // Función primitiva, futuras iteraciones mirar creación de cuadros de texto
// sobre la imagen para tener las coordenadas según cuadro creado
{
	if (ventana == 0 || ventana == 1)
	{
		if ((r.x > (5 - 1.5)) && (r.x < 5) && (r.z > (10 - 4)) && (r.z < 10) )							//ArI
		{
			if (ventana == 1) tematica = SW;
			if (ventana == 0 && (getBoton() == false)) setSonido(!getSonido()), setBoton(true);
		}
	
		if ((r.x > (5 - 1.5)) && (r.x < 5) && (r.z > (5 - 4)) && (r.z < 5))								//ArD(Temática)
		{
			if (ventana == 1) tematica = T2;
			if (ventana == 0) ventana = TEMATICA;
		}
		if ((r.x > (3 - 1.5)) && (r.x < 3) && (r.z > (10 - 4)) && (r.z < 10))							//AbI(Visión)
		{
			if (ventana == 1) tematica = T3;
			if (ventana == 0) ventana = VISION;
		}
		if ((r.x > (3 - 1.5)) && (r.x < 3) && (r.z > (5 - 4)) && (r.z < 5))								//AbD
		{
			if (ventana == 0) setMenu(false);
			if (ventana == 1) ventana = INICIO;
		}

	}

	if (ventana == 2)
	{
		if ((r.x > (10 - 1.5)) && (r.x < 10) && (r.z > (8 - 4)) && (r.z < 8))vision = _2D;			//Ar
		if ((r.x > (7 - 1.5)) && (r.x < 7) && (r.z > (8 - 4)) && (r.z < 8))vision = _3D;			//Med
		if ((r.x > (4 - 1.5)) && (r.x < 4) && (r.z > (8 - 4)) && (r.z < 8)) ventana = INICIO;		//Ab
		
	}
	
}


void Menu::musica()
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