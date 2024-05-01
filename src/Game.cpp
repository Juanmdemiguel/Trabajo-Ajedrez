#include"Game.h"


void Game::dibujaJuego(Model Pawn) {	//Funcion dibujaJuego provisional, se añade a clase Juego/Game cuando se desarrolle

	gluLookAt(-20.0, 40.0, 15.0,  // posicion del ojo
		12.0, 0.0, 15.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	glPushMatrix();
	glTranslatef((5.0 - 5) * 1.0f + 0.5f, (5.0 - 5) * 1.0f + 0.5f, 1.0);
	glScalef(0.05f, 0.05f, 0.05f);
	glRotatef(-90, 90.0f, 0.0f, 1.0f);
	glColor3f(0.1f, 0.1f, 0.1f);

	Pawn.Draw();
	glPopMatrix();
	glColor3f(0, 0, 0);
}