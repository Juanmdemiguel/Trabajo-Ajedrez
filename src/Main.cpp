#include "freeglut.h"
#include "Model.h"
#include "ETSIDI.h"


Model Pawn("model/Pawn.obj");


void OnDraw(void);		 //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	



int main(int argc,char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 40.0, 800/600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25,OnTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	
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
	
	gluLookAt(0.0, 10, 20,  // posicion del ojo
		0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	glPushMatrix();
	glTranslatef((5.0 - 5) * 1.0f + 0.5f, (5.0 - 5) * 1.0f + 0.5f, 1.0);
	glScalef(0.05f, 0.05f, 0.05f);
	glRotatef(-90, 90.0f, 0.0f, 1.0f);
	glColor3f(0.1f, 0.1f, 0.1f);

	Pawn.Draw();
	glPopMatrix();
	glColor3f(0, 0, 0);

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


