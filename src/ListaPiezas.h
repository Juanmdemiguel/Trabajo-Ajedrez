#pragma once
#include<vector>
#include "Piece.h"

using std::vector;

class ListaPiezas
{
	vector <piece*> lista;

public:
	void agregar(piece* p) { lista.push_back(p); }
/* Hay que apañarse con los argumentos
	void dibuja() { 	for (auto b : blancas) b->dibuja1Pieza(); }
	*/

	auto begin() { return lista.begin(); }
	auto end() { return lista.end(); }

	void eliminar(int index);
	void eliminar(piece* p);

	piece* operator[](int index);

	int size() { return static_cast<int>(lista.size()); }

	void destruir_contenido() {
		for (auto p : lista) delete p;
		lista.clear();
	}
};

