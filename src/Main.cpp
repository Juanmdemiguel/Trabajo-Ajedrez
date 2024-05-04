#include "Game.h"
#include "Model.h"
#include "Board.h"
#include <iostream>
#include "camara.h"
#include "Piece.h"

// Posici�n de la esfera
Punto2D esfera = { 0,0 };
vector<double> solucion;
vector<vector<double>> matriz = {
	{125 * 125, 125, 1, 0},
	{400 * 400, 400, 1, 15},
	{641 * 641, 641, 1, 30}
};

Model Pawn("model/Pawn.obj");

void OnDraw(void);		 //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	

void mouseClick(int button, int state, int _x, int _y);
void mouseMove(int _x, int _y);
void mouseDrag(int _x, int _y);

double x, y;
Menu principal;
Game juego;
Camara camara;
piece piezas;

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
	
	ETSIDI::playMusica("sounds/menu.mp3", true);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25,OnTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);

	// Registrar funciones de callback para eventos del rat�n
	glutMouseFunc(mouseClick); // Clic del rat�n


	glutMotionFunc(mouseMove); // Movimiento del rat�n
	glutPassiveMotionFunc(mouseMove); // Movimiento pasivo del rat�n (sin bot�n presionado)

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

	camara.dibuja(principal);
	drawEsferadePruebas(esfera.x, esfera.z);

	principal.getMenu() ? principal.iniciaMenu(principal.getMenu(), principal.getSonido()) : juego.dibujaJuego(piezas);
	//El operador ternario llama a iniciaMenu si el booleano menu es true, si no, dibuja el juego

	//Bot�n m�sica y empezar. Falta modificar el funcionamiento del sonido para que funcione correctamente e imlplementar cuadros

	principal.clickBotonesMenu(x, y);

	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);

	//no borrar esta linea ni poner nada despues. Poner siempre
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	camara.zoom(principal, key);
	camara.actuador(principal, key);
	camara.vertical(principal, key);
	glutPostRedisplay();  //Poner siempre al final y no se pone nada m�s debajo. Dibuja otro frame
}

void OnTimer(int value)
{
	camara.rota(principal);
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}

void mouseClick(int _button, int state, int _x, int _y) {
	if (_button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		// Acciones cuando se hace clic con el bot�n izquierdo del rat�n
		x = _x;
		y = _y;
		principal.setBoton(false);
	}
	
	if (_button == GLUT_LEFT_BUTTON) //Solo si se pulsa el bot�n izquierdo del rat�n
	{
		if ((x > 33) && (x < 151) && (y > 488) && (y < 557)) //Y se tienen las coordenadas del bot�n de sonido
			if (principal.getMenu())
				principal.musica(principal.getSonido());

		if ((x > 579) && (x < 788) && (y > 483) && (y < 553))
			if(principal.getMenu())
				juego.musica(principal.getSonido(),0); //De momento se le pasa un 0 para que funcione	
													   // marchav2, cuando haya desarrollo de botones se implementa el int

	}
	
}

void mouseMove(int x, int y1) 
{
	// Acciones cuando el rat�n se mueve

	float y = 600 - y1;
	Punto2D s;
	if (x > map(y, 125, 431, 117, 190) && x < map(y, 125, 431, 682, 610))
	{
		matriz = {
		{map(y, 125, 431, 117, 190) * map(y, 125, 431, 117, 190), map(y, 125, 431, 117, 190), 1, 0},
		{400 * 400, 400, 1, 15},
		{map(y, 125, 431, 682, 610) * map(y, 125, 431, 682, 610), map(y, 125, 431, 682, 610), 1, 30}
		};

		solucion = resolverSistema(matriz);
		esfera.x = map2(x, solucion[0], solucion[1], solucion[2]);
	}
	if (y > 120 && y < 430)
		esfera.z = map2(y, 0.0000798, 0.034, -5.393);

	juego.getboard().detectpieza(esfera);



}

void mouseDrag(int x, int y) {
	// Acciones cuando el rat�n se arrastra
}

