#include "Archbishop.h"

void Archbishop::dibuja1Pieza(Board& tablero)
{
	switch (tematica)
	{
	case 0:
		glPushMatrix();
		glTranslatef(tablero.getTile({ posicion.z, posicion.x }).getCenter().z, 0.0, tablero.getTile({ posicion.z, posicion.x }).getCenter().x);
		glScalef(0.05f, 0.05f, 0.05f);

		glRotatef(-90, 90.0f, 0.0f, 1.0f);

		//Como cada modelo es distinto, la función scale y rotate dependerá de cada uno. La posición siempre será la misma
		if (color == TRUE)
			glColor3ub(15, 15, 15);
		else
			glColor3ub(5, 5, 5);

		modelo.Draw();
		bishop.Draw();
		glPopMatrix();
		break;
	case 1:
		glEnable(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/Arturito.png").id);

		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);

		glTexCoord2d(0, 1); glVertex3d(tablero.getTile({ posicion.z, posicion.x }).getCenter().z - 1.5, 0.02, tablero.getTile({ posicion.z, posicion.x }).getCenter().x - 1.5);
		glTexCoord2d(1, 1); glVertex3d(tablero.getTile({ posicion.z, posicion.x }).getCenter().z - 1.5, 0.02, tablero.getTile({ posicion.z, posicion.x }).getCenter().x + 1.5);
		glTexCoord2d(1, 0); glVertex3d(tablero.getTile({ posicion.z, posicion.x }).getCenter().z + 1.5, 0.02, tablero.getTile({ posicion.z, posicion.x }).getCenter().x + 1.5);
		glTexCoord2d(0, 0); glVertex3d(tablero.getTile({ posicion.z, posicion.x }).getCenter().z + 1.5, 0.02, tablero.getTile({ posicion.z, posicion.x }).getCenter().x - 1.5);
		glEnd();

		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		break;
	}
}