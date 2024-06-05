#pragma once
#include "Punto2D.h"
#include "Board.h"
#include "freeglut.h"
#include "Model.h"
#include <iostream>

class piece
{
protected:
	vector <Punto2D> posibles{};	//Almacena posiciones posibles �BORRAR POSICIONES TRAS SET DE POSICION!
	Punto2D posicion;

	//Se define el color de las piezas. 0 para negro y 1 para blanco.
	bool color;
	int tematica{}; //Tem�tica del juego, por defecto StarWars (SW a 0 y ETSIDI a 1)
	int vision = 1; //Por defecto visi�n 3D (para 2D es 0)
	enum TIPO { PAWN, ROOK, BISHOP, KNIGHT, KING, QUEEN, ARCHBISHOP, CHANCELLOR } tipo;
	
	inline static Model King{ "resources/model/King.obj" };
	inline static Model Queen{ "resources/model/Queen.obj" };
	inline static Model Bishop{ "resources/model/Bishop.obj" };
	inline static Model Rook{ "resources/model/Rook.obj" };
	inline static Model Knight{ "resources/model/Knight.obj" };
	inline static Model Pawn{ "resources/model/Pawn.obj" };

public:

	//Constructor para dar posici�n gen�rica y color a la pieza correspondiente
	piece(Punto2D pos, bool c, int t, int v) { posicion = pos, color = c; tematica = t; vision = v; }

	//M�todos
	void dibuja1Pieza(Board& tablero);

	void cambiaTematica(int t) { tematica = t; }
	void cambiaVision(int v) { vision = v; }

	void dibujaSprite(Board& tablero);
	void dibujaModelo(Board& tablero) const;

	virtual void getPosibles(Punto2D pos, Board& tablero) = 0;
	virtual void getDiagonal(Punto2D pos, int reach,  Board& tablero);
	virtual void getHorizontal(Punto2D pos, int reach, Board& tablero);
	virtual void getEle(Punto2D pos, Board& tablero);

	Punto2D get_pos() { return posicion; };
	bool getColor() { return color; };
<<<<<<< Updated upstream
	TIPO getTipo() { return tipo; };

=======
>>>>>>> Stashed changes
	vector <Punto2D> getVectorPosibles() { return posibles; }

	bool mueve(const Punto2D& pos_raton, vector <Punto2D> posibles, Board& tablero);

	void cleanVector();

	virtual int promocionar(Punto2D pos)
	{
		if (tipo != PAWN)
			return 0;
	}

};