#include "Piece.h"
#include "freeglut.h"

void piece::elige(piezas p, Punto2D posicion)
{
	int i{};
	switch(p)
	{
	case piezas::pawn:
		posicion.x += square;
		break;
	case piezas::king:
		posicion.x += square;
		posicion.z += square;
		posicion.x -= square;
		posicion.z -= square;
		break;
	case piezas::queen:
		
		break;
	case piezas::bishop:
		posicion.x += square*i;
		posicion.z += square*i;
		posicion.x -= square*i;
		posicion.z -= square*i;
		break;
	case piezas::rook:
		
		break;
	case piezas::knight:
		
		break;
	case piezas::cancellor:
		
		break;
	case piezas::archbishop:
		
		break;
	}
}
void piece::mueve(Punto2D posicion, Model modelo)
{
	glTranslated(posicion.x,posicion.z, 0);
	modelo.Draw();
	glTranslated(-posicion.x, -posicion.z, 0);
}
