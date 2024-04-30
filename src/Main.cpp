#include "Menu.h"
#include "Model.h"
#include "ETSIDI.h"
#include <iostream>


Model Pawn("model/Pawn.obj");


void OnDraw(void);		 //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void menu(bool& menu, bool& sonido);

void mouseClick(int button, int state, int x, int y);
void mouseMove(int x, int y);
void mouseDrag(int x, int y);

bool menu_= true, sonido = true;
double x, y;
bool boton{};

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

	(sonido == true) ? ETSIDI::playMusica("sounds/marcha.mp3", true) : ETSIDI::stopMusica();

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

	
		//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();

		gluLookAt(0.0, 7.5, 20,  // posicion del ojo
			0.0, 7.5, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	if (menu_ == false)
	{
		gluLookAt(0.0, 7.5, 20,  // posicion del ojo
			0.0, 0.0, 0.0,      // hacia que punto mira  (0,0,0) 
			0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    
		glPushMatrix();
		glTranslatef((5.0 - 5) * 1.0f + 0.5f, (5.0 - 5) * 1.0f + 0.5f, 1.0);
		glScalef(0.05f, 0.05f, 0.05f);
		glRotatef(-90, 90.0f, 0.0f, 1.0f);
		glColor3f(0.1f, 0.1f, 0.1f);


		Pawn.Draw();
		glPopMatrix();
		glColor3f(0, 0, 0);
	}
	else 
		menu(menu_,sonido);


	//Botón música
	

	if ((x > 33) && (x < 151) && (y > 488) && (y < 557) && (boton == false))
	{
		sonido = !sonido;
		boton = true;
	}

	if ((x > 579) && (x < 788) && (y > 483) && (y < 553))
		menu_ = false;

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

	std::cout << sonido;
	
}

void menu(bool &menu, bool &sonido)
{
	glEnable(GL_TEXTURE_2D);

	if (sonido == true)
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("images/menu.png").id);
	else
	{
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("images/menusin.png").id);
	}

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1);    glVertex3f(-10, 0, -0.1);
	glTexCoord2d(1, 1);    glVertex3f(10, 0, -0.1);
	glTexCoord2d(1, 0);    glVertex3f(10, 15, -0.1);
	glTexCoord2d(0, 0);    glVertex3f(-10, 15, -0.1);
	
}

void mouseClick(int _button, int state, int _x, int _y) {
	if (_button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		// Acciones cuando se hace clic con el botón izquierdo del ratón
		x = _x;
		y = _y;
		boton = false;
	}

}

void mouseMove(int x, int y) {
	// Acciones cuando el ratón se mueve
}


void mouseDrag(int x, int y) {
	// Acciones cuando el ratón se arrastra
}
