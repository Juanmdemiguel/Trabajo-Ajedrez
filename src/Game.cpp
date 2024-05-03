#include"Game.h"

void Game::dibujaJuego(piece piezas) {	//Funcion dibujaJuego provisional, se añade a clase Juego/Game cuando se desarrolle

	glPushMatrix();
	//glTranslatef(board.getTile({ 7,6 }).getCenter().x, 0.0, board.getTile({ 7,6 }).getCenter().z); 
	glScalef(0.05f, 0.05f, 0.05f);
	glRotatef(-90, 90.0f, 0.0f, 1.0f);
	glColor3f(0.1f, 0.1f, 0.1f);

	piezas.dibujaPiezas();

	glPopMatrix();
	glColor3f(0, 0, 0);

	board.dibuja();
}