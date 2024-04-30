#include "Board.h"

void Board::inicializa()
{
    for (int i = 0; i < fil; i++) {
        for (int j = 0; j < col; j++)
            (j + i) % 2 == 0 ? board[i][j] = true : board[i][j] = false;
    }
}

void Board::dibuja()
{
	
	glDisable(GL_LIGHTING);
	glColor3ub(128, 64, 0);

	glBegin(GL_POLYGON);
	glVertex3d(-2, 0, -2); //Inferior izquierda
	glVertex3d(-2, 0, square * col + 2); //Superior izquierda 
	glVertex3d(square*fil + 2, 0, square * col + 2 ); //Superior derecha 
	glVertex3d(square * fil + 2, 0, -2); //Inferior derecha
	glEnd();

	glEnable(GL_LIGHTING);

    for (int i = 0; i < fil; i++) {
		for (int j = 0; j < col; j++) {

			glDisable(GL_LIGHTING);
			board[i][j] ? glColor3ub(255, 255, 255) : glColor3ub(0, 0, 0);

			glBegin(GL_POLYGON);
			glVertex3d(i*square, 0.01, j*square); //Inferior izquierda
			glVertex3d(i*square, 0.01, square * (j + 1)); //Superior izquierda 
			glVertex3d(square * (i + 1), 0.01, square * (j + 1)); //Superior derecha 
			glVertex3d(square*(i+1), 0.01, j * square); //Inferior derecha
			glEnd();

			glEnable(GL_LIGHTING);
		}	
    }
}