#include "Tile.h"

//Métodos de Tile
void Tile::Dibuja(int i, int j) 
{
	glDisable(GL_LIGHTING);
	this->color ? glColor3ub(255, 255, 255) : glColor3ub(0, 0, 0);

	glBegin(GL_POLYGON);
	glVertex3d(i * tam , 0.01, j * tam); //Inferior izquierda
	glVertex3d(i * tam, 0.01, tam * (j + 1)); //Superior izquierda 
	glVertex3d(tam * (i + 1), 0.01, tam * (j + 1)); //Superior derecha 
	glVertex3d(tam * (i + 1), 0.01, j * tam); //Inferior derecha
	glEnd();

	glEnable(GL_LIGHTING);
}

void Tile::setPos(int row, int col)
{
	this->posicion = { row,col };
}