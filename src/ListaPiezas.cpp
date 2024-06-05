#include "ListaPiezas.h"

void ListaPiezas::eliminar(int index)
{
	int numero = lista.size();
	if ((index < 0) || (index >= numero))
		return;
	delete lista[index];
	numero--;
	for (int i = index; i < numero; i++)
		lista[i] = lista[i + 1];
	lista.pop_back();
}
void ListaPiezas::eliminar(piece* p)
{
	for (int i = 0; i < lista.size(); i++)
		if (lista[i] == p)
		{
			eliminar(i);
			return;
		}
}

piece* ListaPiezas::operator[](int index) {
	//Si esta fuera de rango te selecciona el más cercano
	if (index >= lista.size()) index = (int)(lista.size()) - 1;
	if (index < 0) index = 0;
	//Accede desde la clase vector, que tiene definido []
	return lista[index];
}

piece* ListaPiezas::getPieza(Punto2D posicion)
{
	for (auto i : lista)
	{
		if (i->get_pos() == posicion)
			return i;
	}
}