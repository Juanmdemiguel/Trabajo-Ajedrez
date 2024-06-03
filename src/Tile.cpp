#include "Tile.h"

void Tile::Dibuja(int i, int j)
{
	glEnable(GL_TEXTURE_2D);

	//Primero la dibuja como psible. Si no es, pregunta si la estás apuntado cn el ratón. Si no, la fibuja según color. 
	apuntada ? (glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/Arturito.png").id)) : (
		posible ? (glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/Selected.png").id)) : (
			color ? glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/WhiteTileSW.png").id) : glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/BlackTileSW.png").id)));

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

Punto2D Tile::getCenter()
{
	//Como el sistema de coordenadas empieza en (0,0) y las posiciones en (1,1), se debe extrapolar del sistema de casillas al del glut 
	//Como esta funciona está especificada para el gltranslatef(), y ese método coge la x como horizontal, se han invertido la salida
	//De esta manera, ya que se ha establecido el eje z como el horizontal, el programador puede introducir su eje horizontal en la función
	return { this->tam * (this->posicion.x - 0.5), this->tam * (this->posicion.z - 0.5) };
}