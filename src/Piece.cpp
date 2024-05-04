#include "Piece.h"
#include "freeglut.h"

void piece::elige(TipoPieza p, Punto2D posicion)
{
	int i{}, movimientos{};
	switch(p)
	{
	case TipoPieza::pawn:
		posicion.x += square;
		
		break;
	case TipoPieza::king:
		posicion.x += square;
		posicion.z += square;
		posicion.x -= square;
		posicion.z -= square;
		break;
	case TipoPieza::queen:
		
		break;
	case TipoPieza::bishop:
		posicion.x += square*i;
		posicion.z += square*i;
		posicion.x -= square*i;
		posicion.z -= square*i;
		break;
	case TipoPieza::rook:
		
		break;
	case TipoPieza::knight:
		
		break;
	case TipoPieza::cancellor:
		
		break;
	case TipoPieza::archbishop:
		
		break;
	}
}
void piece::dibuja1Pieza(Punto2D posicion, Model modelo)
{
	glPushMatrix();
	glTranslatef(posicion.x, 0.0, posicion.z);
	glScalef(0.05f, 0.05f, 0.05f);
	glRotatef(-90, 90.0f, 0.0f, 1.0f);
	glColor3f(0.1f, 0.1f, 0.1f);
	modelo.Draw();
	glPopMatrix();
	glColor3f(0, 0, 0);
}

void piece::dibujaPiezas(Board tablero)
{
	//Dibujo de los peones
	for (double i = 2; i <= fil - 1; i += (fil - 3))
	{
		for (double j = 1; j <= col; j++)
		{
			this->dibuja1Pieza(tablero.getTile({ j,i }).getCenter(), Pawn);
		}
	}

	//Dibujo del resto de piezas
	for (double i = 1; i <= fil; i += (fil-1))
	{
		for (double j = 1; j <= col; j++)
		{
			//Dibujo de las torres
			if (j == 1 || j == col)
				this->dibuja1Pieza(tablero.getTile({ j,i }).getCenter(), Pawn);
		
			//Dibujo de los caballos
			if (j == 2 || j == col - 1)
				this->dibuja1Pieza(tablero.getTile({ j,i }).getCenter(), Pawn);

			//Dibujo del arzobispo
			if (j == 3)
				this->dibuja1Pieza(tablero.getTile({ j,i }).getCenter(), Pawn);

			//Dibujo de los alfiles
			if (j == 4 || j == col - 3)
				this->dibuja1Pieza(tablero.getTile({ j,i }).getCenter(), Pawn);

			//Dibujo del canciller
			if (j == 8)
				this->dibuja1Pieza(tablero.getTile({ j,i }).getCenter(), Pawn);

			//Dibujo de la reina
			if (j == 5)
				this->dibuja1Pieza(tablero.getTile({ j,i }).getCenter(), Pawn);

			//Dibujo del rey
			if (j == 6)
				this->dibuja1Pieza(tablero.getTile({ j,i }).getCenter(), Pawn);
		}
	}
}