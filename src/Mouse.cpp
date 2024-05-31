#include "Mouse.h"
#define square 3


void Mouse::movimiento(int x, int y1, Game& juego, Punto2D& esfera, bool menu)
{
	if (menu)
	{
		// Convertir coordenadas de pantalla a coordenadas del mundo 

		GLint viewport[4]; // Tamaño de ventana actual
		GLdouble modelview[16]; // Matriz de vista del sistema, transforma coordenadas de pantalla en coordenadas de ojo
		GLdouble projection[16]; // Matriz de proyección del sistema, convierte coordenadas de ojo en coordenadas objeto
		GLfloat winX, winY, winZ; // Coordenadas del clic de la pantalla 
		GLdouble posX, posY, posZ; // Coordenadas del punto del objeto que se encuentra en la pantalla

		glGetDoublev(GL_MODELVIEW_MATRIX, modelview); // Devuelve los 16 valores que contiene la matriz modelview de GLUT
		glGetDoublev(GL_PROJECTION_MATRIX, projection); // Devuelve los 16 valores de la matriz proyección en la parte superior de la pila
		glGetIntegerv(GL_VIEWPORT, viewport); // Devuelve 4 valores: las coordenadas de ventana x e y de la ventanilla, seguidas de su ancho y alto

		winX = (float)x;
		winY = (float)viewport[3] - (float)y1;

		// Almacena el valor de profundidad en el eje z del píxel pulsado en la pantalla
		glReadPixels(x, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);

		// Asocia coordenadas de pantalla con coordenadas de objetos con las matrices del sistema 
		gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);

		setCoordenadas(posX, posY);

		// Seleccionar el punto en el plano x-y
		//std::cout << "Punto seleccionado en el plano x-y: (" << posX << ", " << posY << ", 0)" << std::endl;
		if (posX > -2 && posX < 32 && posY > -2 && posY < 26)
		{
			if (posX > 0 && posX < 30)
				esfera.x = posX;
			if (posY > 0 && posY < 24)
				esfera.z = posY;
		}
		if (posX > 0 && posX < 30 && posY > 0 && posY < 24)
			juego.getboard().detectpieza(esfera);

	}
	else
	{
		// Convertir coordenadas de pantalla a coordenadas del mundo 3D
		GLint viewport[4]; //Tamaño de ventana actual
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
		//std::cout << "Punto seleccionado en el plano x-z: (" << posZ << ", 0, " << posX << ")" << std::endl;
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
}

void Mouse::seleccion(Game& juego, int boton, int state)const
{
	//Se divide la coordenada entre el tamaño de la casilla
	//Se suma uno para establecer el origenen (1,1)
	if (boton == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
		cout << (int)z / square + 1 << " " << (int)x / square + 1 << endl;
}