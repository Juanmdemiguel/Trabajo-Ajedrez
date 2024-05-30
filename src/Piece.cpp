#include "Piece.h"

void piece::dibuja1Pieza(Board& tablero)
{
	switch (tematica)
	{
	case 0:
		dibujaModelo(tablero);
		break;
	case 1:
		dibujaSprite(tablero);
		break;
	}
}

void piece::dibujaSprite(Board& tablero)
{
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
}

void piece::dibujaModelo(Board& tablero)
{
	glPushMatrix();
	glTranslatef(tablero.getTile({ posicion.z, posicion.x }).getCenter().z, 0.0, tablero.getTile({ posicion.z, posicion.x }).getCenter().x);
	glScalef(0.05f, 0.05f, 0.05f);

	//Como cada modelo es distinto, la función scale y rotate dependerá de cada uno. La posición siempre será la misma

	if (color) {
		glColor3ub(15, 15, 15);
		glRotatef(-90, 1.0f, 0.0f, 0.0f);
		glRotatef(90, 0.0f, 0.0f, 1.0f);
	}
	else {
		glColor3ub(5, 5, 5);
		glRotatef(-90, 1.0f, 0.0f, 0.0f);
		glRotatef(-90, 0.0f, 0.0f, 1.0f);
	}

	switch (tipo) {
	case TIPO::PAWN:
		Pawn.Draw();
		break;
	case TIPO::ROOK:
		Rook.Draw();
		break;
	case TIPO::BISHOP:
		Bishop.Draw();
		break;
	case TIPO::KNIGHT:
		Knight.Draw();
		break;
	case TIPO::KING:
		King.Draw();
		break;
	case TIPO::QUEEN:
		Queen.Draw();
		break;
	case TIPO::CHANCELLOR:
		Knight.Draw();
		Rook.Draw();
		break;
	case TIPO::ARCHBISHOP:
		Knight.Draw();
		Bishop.Draw();
		break;
	}
	glPopMatrix();
}