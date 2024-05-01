#include "Board.h"

//Constructor de Board;
Board::Board()
{
	for (int i = 0; i < fil; i++) {
		for (int j = 0; j < col; j++) {
			board[i][j].setPos(i, j);
			(j + i) % 2 == 0 ? board[i][j].color = true : board[i][j].color = false; //Recorre la matriz del tablero. Establece su color según la suma de sus coordenadas
		}
	}
}


void Board::dibuja()
{
	//Dibujo de la base del tablero
	glDisable(GL_LIGHTING);
	glColor3ub(128, 64, 0);

	glBegin(GL_POLYGON);
	glVertex3d(-2, 0, -2); //Inferior izquierda
	glVertex3d(-2, 0, square * col + 2); //Superior izquierda 
	glVertex3d(square*fil + 2, 0, square * col + 2 ); //Superior derecha 
	glVertex3d(square * fil + 2, 0, -2); //Inferior derecha
	glEnd();

	glEnable(GL_LIGHTING);

	//Dibujo superpuesto de las casillas
    for (int i = 0; i < fil; i++) {
		for (int j = 0; j < col; j++) 
			board[i][j].Dibuja(i,j);
    }
}