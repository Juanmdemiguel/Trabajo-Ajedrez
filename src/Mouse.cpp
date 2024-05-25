#include "Mouse.h"



void Mouse::movimiento(int x, int y1, Game& juego, Punto2D& esfera)
{
	/*
	float y = 600 - y1;
	Punto2D s;
	if (x > map(y, 125, 431, 117, 190) && x < map(y, 125, 431, 682, 610))
	{
		vector<vector<double>> matriz = {
		{map(y, 125, 431, 117, 190) * map(y, 125, 431, 117, 190), map(y, 125, 431, 117, 190), 1, 0},
		{400 * 400, 400, 1, 15},
		{map(y, 125, 431, 682, 610) * map(y, 125, 431, 682, 610), map(y, 125, 431, 682, 610), 1, 30}
		};
		esfera.x = map2(matriz, x);
	}
	if (y > 120 && y < 430)
	{
		vector<vector<double>> matriz1 = {
		{123 * 123, 123, 1, 0},
		{300 * 300, 300, 1, 12},
		{430 * 430, 430, 1, 24}
		};
		esfera.z = map2(matriz1, y);
	}
	*/
	

		// Convertir coordenadas de pantalla a coordenadas del mundo 3D
		GLint viewport[4]; //Tama�o de ventana actual
		GLdouble modelview[16]; //Matriz de vista del sistema, transforma coordenadas de pantalla en coordenadas de ojo
		GLdouble projection[16]; //Matriz de proyeccion del sistema, convierte coordenadas de ojo en coordenadas objeto
		GLfloat winX, winY, winZ; //Coordenadas del click de la pantalla 
		GLdouble posX, posY, posZ; //Coordenadas del punto del objeto que se encuentra en la pantalla

		glGetDoublev(GL_MODELVIEW_MATRIX, modelview); //Devuelve los 16 valores que contiene la matriz modelview de glut
		glGetDoublev(GL_PROJECTION_MATRIX, projection); //Devuelve los 16 valores de la matriz proyeccion en la parte superior de la pila
		glGetIntegerv(GL_VIEWPORT, viewport); //Devuelve 4 valores, las coordenadas de ventana x e y de la ventanilla, seguidas de su ancho y alto.

		winX = (float)x;
		winY = (float)viewport[3] - (float)y1;

		//Almacena el valor de profundidad en el eje z del pixel pulsado en la pantalla
		glReadPixels(x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);

		//Asocia coordenadas de pantalla con coordenadas de objetos con las matrices del sistema. 
		gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posZ, &posY, &posX);

		setCoordenadas(posZ, posX);

		// Seleccionar el punto en el plano x-z
		std::cout << "Punto seleccionado en el plano x-z: (" << posZ << ", 0, " << posX << ")" << std::endl;
		if (posX > -2 && posX < 32 && posZ > -2 && posZ < 26)
		{
			if (posX > 0 && posX < 30)
				esfera.x = posX;
			if (posZ > 0 && posZ < 24)
				esfera.z = posZ;
		}
		if (posX > 0 && posX < 30 && posZ > 0 && posZ < 24)
			juego.getboard().detectpieza(esfera);
}
void Mouse::seleccion(Game& juego, int boton, int state)
{
	for (float i = 1; i < col + 1; i++) {
		for (float j = 1; j < fil + 1; j++)
		{
			juego.getboard().getTile({ i,j }).setpiezapuntada(boton, state);
			if (juego.getboard().getTile({ i,j }).getseleccionada() == true)
				cout << i << " " << j << endl;
		}
	}
}