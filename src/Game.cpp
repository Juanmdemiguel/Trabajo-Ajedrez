#include"Game.h"

void Game::dibujaJuego(piece piezas) {	//Funcion dibujaJuego provisional, se añade a clase Juego/Game cuando se desarrolle

	board.dibuja();
	glPushMatrix();
	//glTranslatef(board.getTile({ 7,6 }).getCenter().x, 0.0, board.getTile({ 7,6 }).getCenter().z); 
	glScalef(0.05f, 0.05f, 0.05f);
	glRotatef(-90, 90.0f, 0.0f, 1.0f);
	glColor3f(0.1f, 0.1f, 0.1f);
	piezas.dibujaPiezas(board);
	glPopMatrix();
	glColor3f(0, 0, 0);

}

void Game::musica(bool sonido, int tema)
{
	switch (tema) //Añadir pistas de música según temática elegida en el menú
	{
	case 0:
		(sonido == true) ? ETSIDI::playMusica("sounds/marchav2.mp3", true) : ETSIDI::stopMusica();
		break;
	case 1:
		break;
	case 2:
		break;
		//...
	}
		


}