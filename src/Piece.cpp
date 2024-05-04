#include "Piece.h"
#include "freeglut.h"
#include <iostream>

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
	glTranslatef(posicion.x, 0.0, posicion.z);
	modelo.Draw();
	glTranslatef(-posicion.x, 0.0,-posicion.z);
}

void piece::dibujaPiezas(Board tablero)
{
	//Dibujo de los peones
	for (double i = 1.0; i<= fil - 2; i += (fil - 3))
	{
		for (double j = 0.0; j < col; j++)
		{
			this->dibuja1Pieza({tablero.getTile({5,8}).getCenter()}, Pawn);
		}
	}

	/*
	//Dibujo del resto de piezas
	for (double i = 0; i <= fil-1; i += (fil-2))
	{
		for (double j = 0; j < col; j++)
		{
			//Dibujo de las torres
			if (j==0 || j==col-1)
			this->dibuja1Pieza({ square * i,square * j }, Pawn);

			//Dibujo de los caballos
			if (j == 1 || j == col - 2)
				this->dibuja1Pieza({ square * i,square * j }, Pawn);

			//Dibujo de los alfiles
			if (j == 2 || j == col - 3)
				this->dibuja1Pieza({ square * i,square * j }, Pawn);

			//Dibujo del rey
			if (j == 3)
				this->dibuja1Pieza({ square * i,square * j }, Pawn);

			//Dibujo de la reina
			if (j == 4)
				this->dibuja1Pieza({ square * i,square * j }, Pawn);
		}
	}
	*/
}