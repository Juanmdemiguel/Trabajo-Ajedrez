
#include "Menu.h"

void Menu::iniciaMenu()
{
	//Para probar más ventanas, con el inicializador

	if (ventana == 0 || ventana == 1) //Menú inicial o menú TEMÁTICA
	{
		dibujaFondo();

		comentario1.setEsquina({ 5, 10 }); //ArI
		comentario1.dibuja(sonido, ventana, 1);
		comentario2.setEsquina({ 5,5 }); //ArD
		comentario2.dibuja(sonido, ventana, 2);
		comentario3.setEsquina({ 3, 10 }); //AbI
		comentario3.dibuja(sonido, ventana, 3);
		comentario4.setEsquina({ 3,5 }); //AbD
		comentario4.dibuja(sonido, ventana, 4);

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);

	}
	else
	{
		dibujaFondo();

		comentario5.setEsquina({ 9, 8 }); //Ar
		comentario5.dibuja(sonido, ventana, 1);
		comentario6.setEsquina({ 6,8 }); //Medio
		comentario6.dibuja(sonido, ventana, 2);
		comentario7.setEsquina({ 3,8 }); //Ab
		comentario7.dibuja(sonido, ventana, 3);

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
			(ventana == 1) ? tematica = T2: ventana = TEMATICA;
		}
		if ((r.x > (3 - 1.5)) && (r.x < 3) && (r.z > (10 - 4)) && (r.z < 10))							//AbI(Visión)
		{
			(ventana == 1) ? tematica = T3: ventana = VISION;
		}
		if ((r.x > (3 - 1.5)) && (r.x < 3) && (r.z > (5 - 4)) && (r.z < 5))								//AbD
		{
			if (ventana == 0) {
				setMenu(false);
			}
			
			if (ventana == 1) ventana = INICIO, r.x = 0, r.z = 0;					//Para evitar que, al guardarse la posición, se inicie
																					//el juego porque evalúa ventana == 0 y se cumple
		}
	}

	if (ventana == 2)
	{
		if ((r.x > (9 - 1.5)) && (r.x < 9) && (r.z > (8 - 4)) && (r.z < 8))vision = _2D;			//Ar
		if ((r.x > (6 - 1.5)) && (r.x < 6) && (r.z > (8 - 4)) && (r.z < 8))vision = _3D;			//Med
		if ((r.x > (3 - 1.5)) && (r.x < 3) && (r.z > (8 - 4)) && (r.z < 8)) ventana = INICIO;		//Ab
	}
	
}

void Menu::Tema()
{
	switch (tematica)
	{
	case 0: glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/MenuPpal.png").id); break;
	case 1: glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/Arturito.png").id); break;
	case 2: glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/BlackTileSW.png").id); break;
	}
}