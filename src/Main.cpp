#include "Game.h"
#include "Model.h"
#include "Board.h"
#include "Menu.h"
#include <iostream>


Model Pawn("model/Pawn.obj");

void OnDraw(void);		 //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	

void mouseClick(int button, int state, int _x, int _y);
void mouseMove(int _x, int _y);
void mouseDrag(int _x, int _y);

double x, y;
Board board;
Menu principal;
Game juego;

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

	(principal.getSonido() == true) ? ETSIDI::playMusica("sounds/marcha.mp3", true) : ETSIDI::stopMusica();

	//glutMotionFunc(mouseMove); // Movimiento del ratón
	//glutPassiveMotionFunc(mouseMove); // Movimiento pasivo del ratón (sin botón presionado)

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();	  //Bucle infinito

	return 0;
}
void OnDraw(void)
{
	//Borrado de la pantalla	
   	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	board.dibuja();

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0.0, 7.5, 20,  // posicion del ojo
		0.0, 7.5, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	principal.getMenu() ? principal.iniciaMenu(principal.getMenu(), principal.getSonido()) : juego.dibujaJuego(Pawn);
	//El operador ternario llama a iniciaMenu si el booleano menu es true, si no, dibuja el juego

	//Botón música y empezar. Falta modificar el funcionamiento del sonido para que funcione correctamente e imlplementar cuadros

	principal.clickBotonesMenu(x, y);

	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	//no borrar esta linea ni poner nada despues. Poner siempre
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	glutPostRedisplay();  //Poner siempre al final y no se pone nada más debajo. Dibuja otro frame
}

void OnTimer(int value)
{
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}

void mouseClick(int _button, int state, int _x, int _y) {
	if (_button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		// Acciones cuando se hace clic con el botón izquierdo del ratón
		x = _x;
		y = _y;
		principal.setBoton(false);
	}
}

void mouseMove(int x, int y) {
	// Acciones cuando el ratón se mueve
}

void mouseDrag(int x, int y) {
	// Acciones cuando el ratón se arrastra
}

