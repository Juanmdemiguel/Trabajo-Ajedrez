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

void piece::ocupado(Tile casilla)
{
	casilla.ocupamiento();
}

void piece::dibuja1Pieza(Punto2D posicion, Model modelo, TipoPieza pieza, Board tablero)
{
	glPushMatrix();
	glTranslatef(posicion.z, 0.0, posicion.x);
	//Como cada modelo es distinto, la función scale y rotate dependerá de cada uno. La posición siempre será la misma
	switch (pieza)
	{
	
		//Para el caso del peón
	case TipoPieza::pawn:
		glScalef(0.05f, 0.05f, 0.05f);
		glRotatef(-90, 90.0f, 0.0f, 1.0f);
		if (color == TRUE)
		{
			glColor3ub(15, 15, 15);
		}
		else
		{
			glColor3ub(5, 5, 5);
		}
		break;
	
		//Para el caso del caza
	case TipoPieza::knight:
		glScalef(1.0f, 1.0f, 1.0f);
		if (color == TRUE)
		{
			glRotatef(-90, 90.0f, 180.0f, 120.0f);
			glColor3ub(15, 15, 15);
		}
		else
		{
			//Cuando es negro, tiene que mirar hacia el lado contrario
			glRotatef(-90, 90.0f, -180.0f, -120.0f);
			glColor3ub(5, 5, 5);
		}
		break;
	}
	modelo.Draw();
	glPopMatrix();
	//glColor3f(0, 0, 0);

	//Se informa a la casilla que donde se ha dibujado el modelo, está ocupado
	this->ocupado(tablero.getTile(posicion));
}

void piece::dibujaPiezas(Board tablero)
{
	//Dibujo de los peones
	for (double i = 2; i <= fil - 1; i += (fil - 3))
	{
		//En función de la fila dibuja un color u otro.
		(i == 2) ? color = TRUE : color = FALSE;
		for (double j = 1; j <= col; j++)
		{
			this->dibuja1Pieza(tablero.getTile({ j,i }).getCenter(), Pawn,TipoPieza::pawn, tablero);
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
				this->dibuja1Pieza(tablero.getTile({ j,i }).getCenter(), Pawn, TipoPieza::pawn, tablero);
		
			//Dibujo de los caballos
			if (j == 2 || j == col - 1)
			{
				this->dibuja1Pieza(tablero.getTile({ j,i }).getCenter(), Tie, TipoPieza::knight, tablero);
			}
			//Dibujo del arzobispo
			if (j == 3)
				this->dibuja1Pieza(tablero.getTile({ j,i }).getCenter(), Pawn, TipoPieza::pawn, tablero);

			//Dibujo de los alfiles
			if (j == 4 || j == col - 3)
				this->dibuja1Pieza(tablero.getTile({ j,i }).getCenter(), Pawn, TipoPieza::pawn, tablero);

			//Dibujo del canciller
			if (j == 8)
				this->dibuja1Pieza(tablero.getTile({ j,i }).getCenter(), Pawn, TipoPieza::pawn, tablero);

			//Dibujo de la reina
			if (j == 5)
				this->dibuja1Pieza(tablero.getTile({ j,i }).getCenter(), Pawn, TipoPieza::pawn, tablero);

			//Dibujo del rey
			if (j == 6)
				this->dibuja1Pieza(tablero.getTile({ j,i }).getCenter(), Pawn, TipoPieza::pawn, tablero);
		}
	}
}