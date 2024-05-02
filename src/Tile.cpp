#include "Tile.h"

//Métodos de Tile
void Tile::Dibuja(int i, int j) 
{
	glEnable(GL_TEXTURE_2D);
	this->color ? glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("images/WhiteTileSW2.png").id) : glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("images/BlackTileSW2.png").id);
	glDisable(GL_LIGHTING);

	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);

	glTexCoord2d(0, 1); glVertex3d(i * tam, 0.01, j * tam);
	glTexCoord2d(1, 1); glVertex3d(i * tam, 0.01, tam * (j + 1));
	glTexCoord2d(1, 0); glVertex3d(tam * (i + 1), 0.01, tam * (j + 1));
	glTexCoord2d(0, 0); glVertex3d(tam * (i + 1), 0.01, j * tam);

	glEnd();

	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void Tile::setPos(int row, int col)
{
	this->posicion = { (double)row,(double)col };
}

Punto2D Tile::getCenter()
{
	//Como el sistema de coordenadas empieza en (0,0) y las posiciones en (1,1), se debe extrapolar del sistema de casillas al del glut 
	return {this->tam * (this->posicion.x - 0.5), this->tam *  (this->posicion.z - 0.5) }; 
}

bool Tile::esta_ocupado()
{
	return ocupada;
}