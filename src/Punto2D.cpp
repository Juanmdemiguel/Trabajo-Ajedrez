#include "Punto2D.h"
#include "freeglut.h"
#include <math.h>


vector<double> resolverSistema(vector<vector<double>> matriz) {
	int n = matriz.size();

	for (int i = 0; i < n; ++i) {
		// Encuentra la fila con el elemento máximo en la columna actual
		int fila_max = i;
		for (int k = i + 1; k < n; ++k) {
			if (abs(matriz[k][i]) > abs(matriz[fila_max][i])) {
				fila_max = k;
			}
		}

		// Intercambia filas
		swap(matriz[i], matriz[fila_max]);

		// Hacer los elementos debajo del pivote igual a cero
		for (int k = i + 1; k < n; ++k) {
			double factor = -matriz[k][i] / matriz[i][i];
			for (int j = i; j < n + 1; ++j) {
				if (i == j) {
					matriz[k][j] = 0;
				}
				else {
					matriz[k][j] += factor * matriz[i][j];
				}
			}
		}
	}

	// Sustitución hacia atrás
	vector<double> solucion(n);
	for (int i = n - 1; i >= 0; --i) {
		solucion[i] = matriz[i][n] / matriz[i][i];
		for (int k = i - 1; k >= 0; --k) {
			matriz[k][n] -= matriz[k][i] * solucion[i];
		}
	}

	return solucion;
}

float map(float x, float in_min, float in_max, float out_min, float out_max) {
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
float map2(float x, float a, float b, float c) {
	return (a * pow(x, 2) + b * x + c);
}

// Función para dibujar la esfera de pruebas
void drawEsferadePruebas(float sphereX, float sphereY) {

	glColor3f(255.0f, 0.0f, 0.0f);
	glPushMatrix();
	glTranslatef(sphereY, 0.0f, sphereX);
	glutSolidSphere(0.25f, 20, 200);
	glPopMatrix();

}
double modulo(Punto2D a, Punto2D b)
{
	return sqrt(pow((a.x - b.x), 2) + pow((a.z - b.z), 2));
}