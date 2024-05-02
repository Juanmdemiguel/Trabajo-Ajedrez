#include"Game.h"


void Game::dibujaJuego(Model Pawn) {	//Funcion dibujaJuego provisional, se a�ade a clase Juego/Game cuando se desarrolle

	gluLookAt(-20, 40.0, 15.0,  // posicion del ojo
		12.0, 0.0, 15.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

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