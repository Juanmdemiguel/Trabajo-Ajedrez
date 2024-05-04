#pragma once
#include <vector>
using namespace std;

class Punto2D
{
public:
	double z, x;

};

//Funciones matematicas de utilidad relativa
vector<double> resolverSistema(vector<vector<double>> matriz); //resuelve un sistema de 3 ecuaciones
float map(float x, float in_min, float in_max, float out_min, float out_max); //Escala linealmente una variable en un rango de valores
float map2(float x, float a, float b, float c);//Ecuación de 2º grado
void drawEsferadePruebas(float sphereX, float sphereY);//Dibuja una esfera roja en unas coordenadas (se debe borrar cuando queramos)
double modulo(Punto2D, Punto2D);