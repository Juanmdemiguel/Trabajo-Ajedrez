#pragma once

#include "Comentario.h"

void Comentario::dibujaComentario(bool sonido)
{
	if (sonido) {
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
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/CuadroSin.png").id);

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

void Comentario::dibujaTexto(int menu, int numCuad)
{
	ETSIDI::setTextColor(1, 1, 1);
	ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
	switch (menu)
	{
	case 0:
		if (numCuad == 1) ETSIDI::printxy("SONIDO", p1.x,0, p1.z); //Le doy como referencia la esquina de abajo a la izqda
		if (numCuad == 2) ETSIDI::printxy("TEMÁTICA", p1.x,0, p1.z);
		if (numCuad == 3) ETSIDI::printxy("VISIÓN", p1.x, 0, p1.z);
		if (numCuad == 4) ETSIDI::printxy("EMPEZAR", p1.x, 0, p1.z);
		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	}
	
}