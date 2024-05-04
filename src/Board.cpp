#include "Board.h"

//Constructor de Board;
Board::Board()
{
	for (int i = 0; i < fil; i++) {
		for (int j = 0; j < col; j++) {
			//Se busca que, por comodidad, el sistema de casillas inicie en (1,1) en vez de (0,0)
			//Además el criterio [filas][columnas] es contrario al [eje x][eje z], así que se invierten
			board[i][j].setPos(j+1, i+1);
			(j + i) % 2 == 0 ? board[i][j].color = true : board[i][j].color = false; //Recorre la matriz del tablero. Establece su color según la suma de sus coordenadas
		}
	}
}

//Métodos de Board

void Board::dibuja()
{
	//Dibujo de la base del tablero
	glDisable(GL_LIGHTING);
	glColor3ub(128, 64, 0);

	glBegin(GL_POLYGON);
	glVertex3d(-2, 0, -2); //Inferior izquierda
	glVertex3d(-2, 0, square * col +2); //Superior izquierda 
	glVertex3d(square * fil + 2, 0, square * col + 2 ); //Superior derecha 
	glVertex3d(square * fil + 2, 0, -2); //Inferior derecha
	glEnd();

	glEnable(GL_LIGHTING);

	//Dibujo superpuesto de las casillas
    for (int i = 0; i < fil; i++) {
		for (int j = 0; j < col; j++) 
			board[i][j].Dibuja(i,j);
    }
}

Tile Board::getTile(Punto2D pos)
{
	// Como la posicion de las casillas inicia en el (1,1), se traduce en una menos en la matriz
	// El criterio [filas][columnas] es contrario al [eje z][eje x].
	// Como el input del código va a ser la posición en el tablero, su equivalente matricial es invertido
	return board[(int)pos.x - 1][(int)pos.z - 1];
}
