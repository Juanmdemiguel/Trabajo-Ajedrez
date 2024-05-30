#pragma once
#include<vector>
#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "King.h"
#include "Queen.h"
#include "Archbishop.h"
#include "Chancellor.h"
#include "Bishop.h"

using std::vector;

class ListaPiezas
{
	vector <piece*> lista;
public:
//Métodos
	void agregar(piece* p) { lista.push_back(p); }
	void dibuja(Board& tablero) { for (auto b : lista) b->dibuja1Pieza(tablero); }
	void cambiaTematica(int  d) { for (auto b : lista) b->cambiaTematica(d); }
	auto begin() { return lista.begin(); }
	auto end() { return lista.end(); }
	int size() { return static_cast<int>(lista.size()); }
	void eliminar(int index);
	void eliminar(piece* p);
	piece* operator[](int index);
	void destruir_contenido() { for (auto p : lista) delete p; lista.clear(); }
//Amigos
};

