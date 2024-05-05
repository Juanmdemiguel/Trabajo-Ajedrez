#pragma once
#include <vector>
using namespace std;

class Punto2D
{
public:
	double z, x;

};

//Funciones matematicas de utilidad relativa
float map(float x, float in_min, float in_max, float out_min, float out_max); //Escala linealmente una variable en un rango de valores
float map2(vector<vector<double>> matriz, float x);//Escala cuadraticamente una variable en un rango de valores
void drawEsferadePruebas(float sphereX, float sphereY);//Dibuja una esfera roja en unas coordenadas (se debe borrar cuando queramos)
double modulo(Punto2D, Punto2D);