#include "freeglut.h"
#include "assimp/aabb.h"		//Comprobacion correcta instalacion assimp



//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void);		 //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	


int main(int argc, char* argv[]) //Primero numero de caracteres, luego array
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("Ajedrez");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw); //Cuando tiene que dibujar llama OnDraw
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown); //Cuando se pulsa un botón llama OnKeyboardDown
	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();	//Juego


	return 0;
}
void OnDraw(void)
{
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Se borra buffer de color y de profuncidad

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); //Se carga la matrizidentidad para situarse en un punto referencia. Los objetos se pondrán en ese punto de referencia

	gluLookAt(0.0, 10.0, 20.0,  //pone posición a la cámara
		0.0, 0.0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el código de dibujo
	//Plano de colores de lado 10
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(255, 0, 0);
	glVertex3f(-5.0f, 0, -5.0f);
	glColor3ub(150, 100, 0);
	glVertex3f(-5.0f, 0, 5.0f);
	glColor3ub(200, 0, 150);
	glVertex3f(5.0f, 0, 5.0f);
	glColor3ub(255, 200, 100);
	glVertex3f(5.0f, 0, -5.0f);
	glEnd();
	glEnable(GL_LIGHTING);

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t) //Evento de teclado
{
	

	glutPostRedisplay();
}


void OnTimer(int value) //Evento de tiempo
{
	//poner aqui el código de animacion
	

	//no borrar estas lineas
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();

}
