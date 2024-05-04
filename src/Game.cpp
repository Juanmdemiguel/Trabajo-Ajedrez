#include"Game.h"

void Game::dibujaJuego(piece piezas) {	//Funcion dibujaJuego provisional, se a�ade a clase Juego/Game cuando se desarrolle

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
	switch (tema) //A�adir pistas de m�sica seg�n tem�tica elegida en el men�
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