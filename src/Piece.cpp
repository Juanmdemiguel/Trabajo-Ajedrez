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

	switch (tipo) {
	case TIPO::PAWN:
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/Arturito.png").id);
		break;
	case TIPO::ROOK:
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/Arturito.png").id);
		break;
	case TIPO::BISHOP:
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/Arturito.png").id);
		break;
	case TIPO::KNIGHT:
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/Arturito.png").id);
		break;
	case TIPO::KING:
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/Arturito.png").id);
		break;
	case TIPO::QUEEN:
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/Arturito.png").id);
		break;
	case TIPO::CHANCELLOR:
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/Arturito.png").id);
		break;
	case TIPO::ARCHBISHOP:
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/Arturito.png").id);
		break;
	}

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

void piece::dibujaModelo(Board& tablero) const
{
	glPushMatrix();
	glTranslatef(tablero.getTile({ posicion.z, posicion.x }).getCenter().z, 0.0, tablero.getTile({ posicion.z, posicion.x }).getCenter().x);
	glScalef(0.05f, 0.05f, 0.05f);

	//Como cada modelo es distinto, la funci�n scale y rotate depender� de cada uno. La posici�n siempre ser� la misma

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

void piece::getDiagonal(Punto2D pos, int reach, Board& tablero)
{
	double columna = (int)pos.x;     //Traduce el punto 2D a posiciones matriciales
	double fila = (int)pos.z;

	//Para comer a otras piezas
	for (int i = 1; i <= reach; i++) { //asigna a las matrices en la diagonal el estatus de posible
		if ((fila + i) <= 10 && (columna + i) <= 8) //fil col
			tablero.getTile({ fila + i,columna + i }).setposible(true);
		if ((fila - i) >= 1 && (columna - i) >= 0)
			tablero.getTile({ fila - i,columna - i }).setposible(true);
		if ((fila - i) >= 1 && (columna + i) <= 8) //col
			tablero.getTile({ fila - i,columna + i }).setposible(true);
		if ((fila + i) <= fil && (columna - i) >= 0)
			tablero.getTile({ fila + i,columna - i }).setposible(true);
	}
}
void piece::getHorizontal(Punto2D pos, int reach, Board& tablero)
{
	double columna = (int)pos.x;     //Traduce el punto 2D a posiciones matriciales
	double fila = (int)pos.z;

	for (int i = 1; i <= reach; i++) { //asigna posible a las casillas en horizontal y vertical

		//UBICAR EL DEFINE Y CAMBIARLO POR EL VALOR BUENO
		if ((fila + i) <= 10)   tablero.getTile({ fila + i,columna }).setposible(true); //fil
		
		if ((fila - i) >= 0)    tablero.getTile({ fila - i,columna }).setposible(true);
			
		if ((columna + i) <= 8)	tablero.getTile({ fila,columna + i }).setposible(true);//col
		
		if ((columna - i) >= 0) tablero.getTile({ fila,columna - i }).setposible(true);
			
	}
}