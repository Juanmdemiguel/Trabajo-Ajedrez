#include "Piece.h"

void piece::dibuja1Pieza(Board& tablero)
{
	glPushMatrix();
	glTranslatef(posicion.z, 0.0, posicion.x);
	glScalef(0.05f, 0.05f, 0.05f);

	glRotatef(-90, 90.0f, 0.0f, 1.0f);

	//Como cada modelo es distinto, la función scale y rotate dependerá de cada uno. La posición siempre será la misma
	if (color == TRUE)
		glColor3ub(15, 15, 15);
	else
		glColor3ub(5, 5, 5);

	modelo.Draw();
	glPopMatrix();
}


//Esto se hace en lista piezas
/*
void piece::dibujaPiezas(Board& tablero)
{
	//Dibujo de los peones
	for (double i = 2; i <= fil - 1; i += (fil - 3))
	{
		//En función de la fila dibuja un color u otro.
		(i == 2) ? color = TRUE : color = FALSE;
		for (double j = 1; j <= col; j++)
		{
			this->dibuja1Pieza(tablero.getTile({ j,i }).getCenter(), Pawn,TipoPieza::pawn, tablero);
			tablero.getTile({ j,i }).setocupada(true);
		}
	}

	//Dibujo del resto de piezas
	for (double i = 1; i <= fil; i += (fil-1))
	{
		(i == 1) ? color = TRUE : color = FALSE;
		for (double j = 1; j <= col; j++)
		{
			//Dibujo de las torres
			if (j == 1 || j == col)
				this->dibuja1Pieza(tablero.getTile({ j,i }).getCenter(), Rook, TipoPieza::rook, tablero);
		
			//Dibujo de los caballos
			if (j == 2 || j == col - 1)
			{
				this->dibuja1Pieza(tablero.getTile({ j,i }).getCenter(), Knight, TipoPieza::knight, tablero);
			}
			//Dibujo del arzobispo
			if (j == 3) //Aqui habria que tocar cositas
			{
				this->dibuja1Pieza(tablero.getTile({ j,i }).getCenter(), Knight, TipoPieza::knight, tablero);
				this->dibuja1Pieza(tablero.getTile({ j,i }).getCenter(), Bishop, TipoPieza::knight, tablero);
			}

			//Dibujo de los alfiles
			if (j == 4 || j == col - 3)
				this->dibuja1Pieza(tablero.getTile({ j,i }).getCenter(), Bishop, TipoPieza::bishop, tablero);

			//Dibujo del canciller
			if (j == 8) { //Aqui habría que tocar cositas
				this->dibuja1Pieza(tablero.getTile({ j,i }).getCenter(), Rook, TipoPieza::pawn, tablero);
				this->dibuja1Pieza(tablero.getTile({ j,i }).getCenter(), Bishop, TipoPieza::pawn, tablero);
			}
				

			//Dibujo de la reina
			if (j == 5)
				this->dibuja1Pieza(tablero.getTile({ j,i }).getCenter(), Queen, TipoPieza::queen, tablero);

			//Dibujo del rey
			if (j == 6)
				this->dibuja1Pieza(tablero.getTile({ j,i }).getCenter(), King, TipoPieza::king, tablero);

			tablero.getTile({ j,i }).setocupada(true);
		}
	}
}
*/