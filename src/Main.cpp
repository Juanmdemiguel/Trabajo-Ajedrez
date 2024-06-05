#include "Game.h"
#include "Model.h"
#include "Board.h"
#include "camara.h"
#include "Piece.h"
#include "Mouse.h"
#include "Coordinator.h"
#include "iostream"



void OnDraw(void);		 //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	

void mouseClick(int button, int state, int _x, int _y);
void mouseMove(int _x, int _y);
void mouseDrag(int _x, int _y);


Coordinator coord;


int main(int argc,char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana

	double width = 800.0f, height = 600.0f;
	glutInit(&argc, argv);
	glutInitWindowSize(width,height);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");
	

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 40.0, width/height, 0.1, 150);
	


	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25,OnTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	// Registrar funciones de callback para eventos del ratón
	glutMouseFunc(mouseClick); // Clic del ratón
	glutMotionFunc(mouseMove); // Movimiento del ratón
	glutPassiveMotionFunc(mouseMove); // Movimiento pasivo del ratón (sin botón presionado)

	//coord.Inicializa();

	ETSIDI::playMusica("resources/sounds/menu2.mp3", true);

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();	  //Bucle infinito

	return 0;
}
void OnDraw(void)
{
	//Borrado de la pantalla	
   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	coord.Dibuja();

	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	//no borrar esta linea ni poner nada despues. Poner siempre
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	coord.Teclado(key, x_t, y_t);

	glutPostRedisplay();  //Poner siempre al final y no se pone nada más debajo. Dibuja otro frame
}

void OnTimer(int value)
{
	coord.Temp(value);
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}

void mouseClick(int _button, int state, int _x, int _y) 
{
	coord.Click(_button, state, _x, _y);
}

void mouseMove(int x, int y1) 
{
	// Acciones cuando el ratón se mueve
	coord.Mouse(x, y1);
}

void mouseDrag(int x, int y) {
	// Acciones cuando el ratón se arrastra
}

