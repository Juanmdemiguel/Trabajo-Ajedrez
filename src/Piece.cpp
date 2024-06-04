#include "Piece.h"

void piece::dibuja1Pieza(Board& tablero)
{
	switch (tematica)
	{
	case 0:
		dibujaModelo(tablero);
		break;
	case 1:
		dibujaSprite(tablero);
		break;
	}
}

void piece::dibujaSprite(Board& tablero)
{
	glEnable(GL_TEXTURE_2D);

	switch (tipo) {
	case TIPO::PAWN:
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/Arturito.png").id);
		break;
	case TIPO::ROOK:
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/Arturito.png").id);
		break;
	case TIPO::BISHOP:
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/Arturito.png").id);
		break;
	case TIPO::KNIGHT:
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/Arturito.png").id);
		break;
	case TIPO::KING:
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/Arturito.png").id);
		break;
	case TIPO::QUEEN:
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/Arturito.png").id);
		break;
	case TIPO::CHANCELLOR:
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/Arturito.png").id);
		break;
	case TIPO::ARCHBISHOP:
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("resources/images/Arturito.png").id);
		break;
	}

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);

	glTexCoord2d(0, 1); glVertex3d(tablero.getTile({ posicion.z, posicion.x }).getCenter().z - 1.5, 0.02, tablero.getTile({ posicion.z, posicion.x }).getCenter().x - 1.5);
	glTexCoord2d(1, 1); glVertex3d(tablero.getTile({ posicion.z, posicion.x }).getCenter().z - 1.5, 0.02, tablero.getTile({ posicion.z, posicion.x }).getCenter().x + 1.5);
	glTexCoord2d(1, 0); glVertex3d(tablero.getTile({ posicion.z, posicion.x }).getCenter().z + 1.5, 0.02, tablero.getTile({ posicion.z, posicion.x }).getCenter().x + 1.5);
	glTexCoord2d(0, 0); glVertex3d(tablero.getTile({ posicion.z, posicion.x }).getCenter().z + 1.5, 0.02, tablero.getTile({ posicion.z, posicion.x }).getCenter().x - 1.5);
	glEnd();

	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
}

void piece::dibujaModelo(Board& tablero) const
{
	glPushMatrix();
	glTranslatef(tablero.getTile({ posicion.z, posicion.x }).getCenter().z, 0.0, tablero.getTile({ posicion.z, posicion.x }).getCenter().x);
	glScalef(0.05f, 0.05f, 0.05f);

	//Como cada modelo es distinto, la función scale y rotate dependerá de cada uno. La posición siempre será la misma

	if (color) {
		glColor3ub(15, 15, 15);
		glRotatef(-90, 1.0f, 0.0f, 0.0f);
		glRotatef(90, 0.0f, 0.0f, 1.0f);
	}
	else {
		glColor3ub(5, 5, 5);
		glRotatef(-90, 1.0f, 0.0f, 0.0f);
		glRotatef(-90, 0.0f, 0.0f, 1.0f);
	}

	switch (tipo) {
	case TIPO::PAWN:
		Pawn.Draw();
		break;
	case TIPO::ROOK:
		Rook.Draw();
		break;
	case TIPO::BISHOP:
		Bishop.Draw();
		break;
	case TIPO::KNIGHT:
		Knight.Draw();
		break;
	case TIPO::KING:
		King.Draw();
		break;
	case TIPO::QUEEN:
		Queen.Draw();
		break;
	case TIPO::CHANCELLOR:
		Knight.Draw();
		Rook.Draw();
		break;
	case TIPO::ARCHBISHOP:
		Knight.Draw();
		Bishop.Draw();
		break;
	}
	glPopMatrix();
}

void piece::getDiagonal(Punto2D pos, int reach, Board& tablero)
{
	bool d1=false, d2=false, d3=false, d4=false;
	double columna = (int)pos.x;     //Traduce el punto 2D a posiciones matriciales
	double fila = (int)pos.z;

	//Para comer a otras piezas
	for (int i = 1; i <= reach; i++) { //asigna a las matrices en la diagonal el estatus de posible
		if ((fila + i) <= 8 && (columna + i) <= 8 && !d1) { //fil col

			//Si el color de la pieza es igual al color de la pieza que está comprobando mediante la casilla entonces no la hace posible, sino sí que es posible
			if (int(color) == tablero.getTile({ fila + i,columna + i }).getocupada()) { d1 = true; }
			if (d1 == false) tablero.getTile({ fila + i,columna + i }).setposible(true), posibles.push_back({ fila + i,columna + i });

			//Si la casilla es posible y además hay una pieza del otro color, entonces la pone como comestible
			if (tablero.getTile({ fila + i,columna + i }).getposible() && tablero.getTile({ fila + i,columna + i }).getocupada() != int(color) && tablero.getTile({ fila + i,columna + i }).getocupada() != 2)
				tablero.getTile({ fila + i,columna + i }).setcomestible(true);
		}
		if ((fila - i) >= 1 && (columna - i) >= 1 && !d2){
			if (int(color) == tablero.getTile({ fila - i,columna - i }).getocupada()) { d2 = true; }
			if (d2 == false) tablero.getTile({ fila - i,columna - i }).setposible(true), posibles.push_back({ fila - i,columna - i });
			if (tablero.getTile({ fila - i,columna - i }).getposible() && tablero.getTile({ fila - i,columna - i }).getocupada() != int(color) && tablero.getTile({ fila - i,columna - i }).getocupada() != 2)
				tablero.getTile({ fila - i,columna - i }).setcomestible(true);
		}
		if ((fila - i) >= 1 && (columna + i) <= 8 && !d3) { //col
			if (int(color) == tablero.getTile({ fila - i,columna + i }).getocupada()) { d3 = true; }
			if (d3 == false) tablero.getTile({ fila - i,columna + i }).setposible(true), posibles.push_back({ fila - i,columna + i });
			if (tablero.getTile({ fila - i,columna + i }).getposible() && tablero.getTile({ fila - i,columna + i }).getocupada() != int(color) && tablero.getTile({ fila - i,columna + i }).getocupada() != 2)
				tablero.getTile({ fila - i,columna + i }).setcomestible(true);
		}
		if ((fila + i) <= 10 && (columna - i) >= 1 && !d4) {
			if (int(color) == tablero.getTile({ fila + i,columna - i }).getocupada()) { d4 = true; }
			if (d4 == false) tablero.getTile({ fila + i,columna - i }).setposible(true), posibles.push_back({ fila + i,columna - i });
			if (tablero.getTile({ fila + i,columna - i }).getposible() && tablero.getTile({ fila + i,columna - i }).getocupada() != int(color) && tablero.getTile({ fila + i,columna - i }).getocupada() != 2)
				tablero.getTile({ fila + i,columna - i }).setcomestible(true);
		}



		for (auto p : posibles)
			cout << p.x << ';' << p.z << endl;

	}
}
void piece::getHorizontal(Punto2D pos, int reach, Board& tablero)
{
	bool d1 = false, d2 = false, d3 = false, d4 = false;
	double columna = (int)pos.x;     //Traduce el punto 2D a posiciones matriciales
	double fila = (int)pos.z;

	for (int i = 1; i <= reach; i++) { //asigna posible a las casillas en horizontal y vertical

		//UBICAR EL DEFINE Y CAMBIARLO POR EL VALOR BUENO
		if ((fila + i) <= 10 && !d1) {
			if (int(color) == tablero.getTile({ fila + i,columna }).getocupada()) { d1 = true; }
			if (d1 == false) tablero.getTile({ fila + i,columna }).setposible(true), posibles.push_back({ fila + i,columna }); //fil
			if (tablero.getTile({ fila + i,columna }).getposible() && tablero.getTile({ fila + i,columna }).getocupada() != int(color) && tablero.getTile({ fila + i,columna }).getocupada() != 2)
				tablero.getTile({ fila + i,columna }).setcomestible(true);
		} 
		if ((fila - i) > 0 && !d2) {
			if (int(color) == tablero.getTile({ fila - i,columna }).getocupada()) { d2 = true; }
			if (d2 == false) tablero.getTile({ fila - i,columna }).setposible(true), posibles.push_back({ fila - i,columna });
			if (tablero.getTile({ fila - i,columna }).getposible() && tablero.getTile({ fila - i,columna }).getocupada() != int(color) && tablero.getTile({ fila - i,columna }).getocupada() != 2)
				tablero.getTile({ fila - i,columna }).setcomestible(true);
		}
			
		if ((columna + i) <= 8 && !d3) {
			if (int(color) == tablero.getTile({ fila,columna + i }).getocupada()) { d3 = true; }
			if (d3 == false) tablero.getTile({ fila,columna + i }).setposible(true), posibles.push_back({ fila,columna + i });//col
			if (tablero.getTile({ fila ,columna + i }).getposible() && tablero.getTile({ fila ,columna + i }).getocupada() != int(color) && tablero.getTile({ fila ,columna + i }).getocupada() != 2)
				tablero.getTile({ fila ,columna + i }).setcomestible(true);
		}
		
		if ((columna - i) > 0 && !d4) {
			if (int(color) == tablero.getTile({ fila,columna - i }).getocupada()) { d4 = true; }
			if (d4 == false) tablero.getTile({ fila,columna - i }).setposible(true), posibles.push_back({ fila,columna - i });
			if (tablero.getTile({ fila ,columna - i }).getposible() && tablero.getTile({ fila ,columna - i }).getocupada() != int(color) && tablero.getTile({ fila ,columna - i }).getocupada() != 2)
				tablero.getTile({ fila ,columna - i }).setcomestible(true);
		} 
			
	}

	/*for (auto i : posibles)
		cout << i.x << i.z;*/
}
void piece::getEle(Punto2D pos, Board& tablero)
{
	double columna = (int)pos.x;     //Traduce el punto 2D a posiciones matriciales
	double fila = (int)pos.z;

	if (fila + 2 < 11 && columna + 1 < 9 && int(color) != tablero.getTile({ fila + 2,columna + 1 }).getocupada())
	{
		tablero.getTile({ fila + 2, columna + 1 }).setposible(true);
		if (tablero.getTile({ fila + 2,columna + 1 }).getposible() && tablero.getTile({ fila + 2,columna + 1 }).getocupada() != int(color) && tablero.getTile({ fila + 2,columna + 1 }).getocupada() != 2)
			tablero.getTile({ fila + 2,columna + 1 }).setcomestible(true);
		posibles.push_back({ fila + 2,columna + 1 });
	}
		

	if (fila + 2 < 11 && columna - 1 > 0 && int(color) != tablero.getTile({ fila + 2,columna - 1 }).getocupada())
	{
		tablero.getTile({ fila + 2, columna - 1 }).setposible(true);
		if (tablero.getTile({ fila + 2,columna - 1 }).getposible() && tablero.getTile({ fila + 2,columna - 1 }).getocupada() != int(color) && tablero.getTile({ fila + 2,columna - 1 }).getocupada() != 2)
			tablero.getTile({ fila + 2,columna - 1 }).setcomestible(true);
		posibles.push_back({ fila + 2,columna - 1 });
	}
		

	if (fila - 2 > 0 && columna + 1 < 9 && int(color) != tablero.getTile({ fila - 2,columna + 1 }).getocupada())
	{
		tablero.getTile({ fila - 2, columna + 1 }).setposible(true);
		if (tablero.getTile({ fila - 2,columna + 1 }).getposible() && tablero.getTile({ fila - 2,columna + 1 }).getocupada() != int(color) && tablero.getTile({ fila - 2,columna + 1 }).getocupada() != 2)
			tablero.getTile({ fila - 2,columna + 1 }).setcomestible(true);
		posibles.push_back({ fila - 2,columna + 1 });
	}
		

	if (fila - 2 > 0 && columna - 1 > 0 && int(color) != tablero.getTile({ fila - 2,columna - 1 }).getocupada())
	{
		tablero.getTile({ fila - 2, columna - 1 }).setposible(true);
		if (tablero.getTile({ fila - 2,columna - 1 }).getposible() && tablero.getTile({ fila - 2,columna - 1 }).getocupada() != int(color) && tablero.getTile({ fila - 2,columna - 1 }).getocupada() != 2)
			tablero.getTile({ fila - 2,columna - 1 }).setcomestible(true);
		posibles.push_back({ fila - 2,columna - 1 });
	}
		

	if (fila + 1 < 11 && columna + 2 < 9 && int(color) != tablero.getTile({ fila + 1,columna + 2 }).getocupada())
	{
		tablero.getTile({ fila + 1, columna + 2 }).setposible(true);
		if (tablero.getTile({ fila + 1,columna + 2 }).getposible() && tablero.getTile({ fila + 1,columna + 2 }).getocupada() != int(color) && tablero.getTile({ fila + 1,columna + 2 }).getocupada() != 2)
			tablero.getTile({ fila + 1,columna + 2 }).setcomestible(true);
		posibles.push_back({ fila + 1,columna + 2 });
	}
		

	if (fila + 1 < 11 && columna - 2 > 0 && int(color) != tablero.getTile({ fila + 1,columna - 2 }).getocupada())
	{
		tablero.getTile({ fila + 1, columna - 2 }).setposible(true);
		if (tablero.getTile({ fila + 1,columna - 2 }).getposible() && tablero.getTile({ fila + 1,columna - 2 }).getocupada() != int(color) && tablero.getTile({ fila + 1,columna - 2 }).getocupada() != 2)
			tablero.getTile({ fila + 1,columna - 2 }).setcomestible(true);
		posibles.push_back({ fila + 1,columna - 2 });
	}
		

	if (fila - 1 > 0 && columna + 2 < 9 && int(color) != tablero.getTile({ fila - 1,columna + 2 }).getocupada())
	{
		tablero.getTile({ fila - 1, columna + 2 }).setposible(true);
		if (tablero.getTile({ fila - 1,columna + 2 }).getposible() && tablero.getTile({ fila - 1,columna + 2 }).getocupada() != int(color) && tablero.getTile({ fila - 1,columna + 2 }).getocupada() != 2)
			tablero.getTile({ fila - 1,columna + 2 }).setcomestible(true);
		posibles.push_back({ fila - 1,columna + 2 });
	}
		

	if (fila - 1 > 0 && columna - 2 > 0 && int(color) != tablero.getTile({ fila - 1,columna - 2 }).getocupada())
	{
		tablero.getTile({ fila - 1, columna - 2 }).setposible(true);
		if (tablero.getTile({ fila - 1,columna - 2 }).getposible() && tablero.getTile({ fila - 1,columna - 2 }).getocupada() != int(color) && tablero.getTile({ fila - 1,columna - 2 }).getocupada() != 2)
			tablero.getTile({ fila - 1,columna - 2 }).setcomestible(true);
		posibles.push_back({ fila - 1,columna - 2 });
	}
		

}

bool piece::mueve(const Punto2D& pos_raton, vector <Punto2D> posibles, Board &tablero)
{
	for (auto p : posibles)
	{
		if (pos_raton == p)	// Si posición del ratón es igual a la de una de las posibles
		{
			tablero.getTile(posicion).setocupada(2); //Donde estaba antes la pieza ahora está libre (2)
			posicion.x = p.x;	//Cambia posición de la pieza
			posicion.z = p.z;
			cleanVector();
			return true;
		}

		if (posicion != pos_raton) cleanVector();

		//cout << p.x << ',' << p.z << endl;
		//cout << pos_raton.x <<','<< pos_raton.z << endl;

	
	}
	return false;

}

void piece::cleanVector()
{
	int num = posibles.size();
	for (int contador = 0; contador < num; contador++) { posibles.pop_back(); }

}