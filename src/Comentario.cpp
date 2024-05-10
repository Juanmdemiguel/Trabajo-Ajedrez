#pragma once

#include "Comentario.h"

void Comentario::dibujaComentario(bool BotonSonido, bool sonido)	//BotonSonido indica si comentario tiene naturaleza de botoón de sonido
																	//sonido es el booleano de la música
{
	if (sonido||!BotonSonido) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/Cuadro.png").id);

		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);

		glTexCoord2d(0, 1);    glVertex3f(p1.x, 0.01, p1.z);
		glTexCoord2d(1, 1);    glVertex3f(p1.x, 0.01, p2.z); //bien
		glTexCoord2d(1, 0);    glVertex3f(p2.x, 0.01, p2.z);
		glTexCoord2d(0, 0);    glVertex3f(p2.x, 0.01, p1.z);

		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
	else
	{
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/CuadroSin.png").id);	//Tachado

		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);

		glTexCoord2d(0, 1);    glVertex3f(p1.x, 0.01, p1.z);
		glTexCoord2d(1, 1);    glVertex3f(p1.x, 0.01, p2.z); //bien
		glTexCoord2d(1, 0);    glVertex3f(p2.x, 0.01, p2.z);
		glTexCoord2d(0, 0);    glVertex3f(p2.x, 0.01, p1.z);

		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
	}
	dibujaTexto(0, 1);
}

void Comentario::dibujaTexto(int menu, int numCuad)	//menu es un entero que indica la pantalla del menú en la que se está
													//numCuad indica qué comentario es   1  2
													//									 3	4
{
	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 16);

	switch (menu)
	{
	case 0:	//Menú inicial

		switch (numCuad)
		{
		case 1: ETSIDI::printxy("SONIDO", p1.x, 0, p1.z); break; //Le doy como referencia la esquina de abajo a la izqda
		case 2: ETSIDI::printxy("TEMÁTICA", p1.x, 0, p1.z); break;
		case 3: ETSIDI::printxy("VISIÓN", p1.x, 0, p1.z); break;
		case 4: ETSIDI::printxy("EMPEZAR", p1.x, 0, p1.z); break;
		}
		
	case 1: //Menú TEMÁTICA

		switch (numCuad)
		{
		case 1: ETSIDI::printxy("STAR WARS", p1.x, 0, p1.z); break; //Le doy como referencia la esquina de abajo a la izqda
		case 2: ETSIDI::printxy(" ", p1.x, 0, p1.z); break;
		case 3: ETSIDI::printxy(" ", p1.x, 0, p1.z); break;
		case 4: ETSIDI::printxy("VOLVER", p1.x, 0, p1.z); break;
		}
	case 2: //Menú VISIÓN

		switch (numCuad)
		{
		case 1: ETSIDI::printxy("2D", p1.x, 0, p1.z); break; //Le doy como referencia la esquina de abajo a la izqda
		case 2: ETSIDI::printxy("3D", p1.x, 0, p1.z); break;
		}
		break;
	}
	
}