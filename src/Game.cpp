#include"Game.h"


void Game::dibujaJuego(Model Pawn) {	//Funcion dibujaJuego provisional, se a�ade a clase Juego/Game cuando se desarrolle

	glPushMatrix();
	glTranslatef(board.getTile({ 7,6 }).getCenter().x, 1.0, board.getTile({ 7,6 }).getCenter().z); 
	glScalef(0.05f, 0.05f, 0.05f);
	glRotatef(-90, 90.0f, 0.0f, 1.0f);
	glColor3f(0.1f, 0.1f, 0.1f);

	Pawn.Draw();

	glPopMatrix();
	glColor3f(0, 0, 0);

	board.dibuja();
}