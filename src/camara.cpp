#include "camara.h"
#include <iostream>
#define mirax 12.0
#define miray 0.0
#define miraz 15.0

//Establece posiciones iniciales de la camara tanto en el menu como al iniciar la partida
void Camara::dibuja(Menu& principal)
{
    
    if (principal.getMenu())
    {
        gluLookAt(6, 8, 16,  // posicion del ojo
            6, 8, 0,      // hacia que punto mira  (0,0,0)
           1.0, 0.0, 0.0);      // definimos visión hacia arriba (eje X)
    }
    else if (!vistaPuntuaciones)
    {
        gluLookAt(posx, posy, posz,  // posicion del ojo
            mirax, miray, miraz,      // hacia que punto mira  (0,0,0) 
            0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)*/  
    }
    else 
    {
        gluLookAt(7.5, 8, 8,  // posicion del ojo   10
            7.5, 8, 0,      // hacia que punto mira  (0,0,0) 
            0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)*/  
    }
    
}


//Permite la rotación al cambiar de turno (provisionalmente se acciona al pulsar el espacio)
void Camara::actuador(Menu& principal, bool& _rotate)
{
    if (!principal.getMenu()) {
        rotar = _rotate;
        _rotate = false;
    }
}

//Permite acercar la camara al tablero al pulsar '+' y alejarla al pulsar '-'
void Camara::zoom(Menu& principal, unsigned char key)
{
    if (!principal.getMenu()  && estatico)
    {
        double zoom = 0.5; // Ajusta el factor de zoom según sea necesario

        double dirx = mirax - posx;
        double diry = miray - posy;
        double dirz = miraz - posz;

        // Normaliza el vector de dirección
        double modulodir = sqrt(dirx * dirx + diry * diry + dirz * dirz);
        double unitariodirx = dirx / modulodir;
        double unitariodiry = diry / modulodir;
        double unitariodirz = dirz / modulodir;

        if (key == '+' && zoomin < 30)
        {
            // Mueve el punto de mira en la dirección opuesta al vector de dirección de la cámara
            posx = posx + unitariodirx * zoom;
            posy = posy + unitariodiry * zoom;
            posz = posz + unitariodirz * zoom;
            zoomin = zoomin + 1;
            zoomout = zoomout - 1;
        }

        else if (key == '-' && zoomout < 20)
        {
            // Mueve el punto de mira en la dirección del vector de dirección de la cámara
            posx = posx - unitariodirx * zoom;
            posy = posy - unitariodiry * zoom;
            posz = posz - unitariodirz * zoom;
            zoomin = zoomin - 1;
            zoomout = zoomout + 1;
        }

        else if (key == 'p' || key == 'P')  vistaPuntuaciones = true;

        else if (key == 'j' || key == 'J') vistaPuntuaciones = false;
    }
}

//Permite ver el tablero desde arriba al pulsar 'w' y de forma frontal al pulsar 's' independientemente del color que tenga el turno
void Camara::vertical(Menu& principal, unsigned char key)
{
    if (!principal.getMenu()  && estatico)
    {
        float d = sqrt((posx - mirax) * (posx - mirax) + (posy - miray) * (posy - miray));
        double theta = atan2((posy - miray), (posx - mirax));
        if (cambionegro)
        {
            if ((key == 'w' || key == 'W') && arriba < 10)
            {
                
                theta = theta + 0.05;
                posx = mirax + d * cos(theta);
                posy = miray + d * sin(theta);
                arriba = arriba + 1;
                abajo = abajo - 1;
            }
            if ((key == 's' || key == 'S') && abajo < 18)
            {
                
                theta = theta - 0.05;
                posx = mirax + d * cos(theta);
                posy = miray + d * sin(theta);
                arriba = arriba - 1;
                abajo = abajo + 1;

            }
        }
        if (!cambionegro)
        {
            if ((key == 's' || key == 'S') && abajo < 18)
            {
               
                theta = theta + 0.05;
                posx = mirax + d * cos(theta);
                posy = miray + d * sin(theta);
                arriba = arriba - 1;
                abajo = abajo + 1;

            }
            if ((key == 'w' || key == 'W') && arriba < 10)
            {
                
                theta = theta - 0.05;
                posx = mirax + d * cos(theta);
                posy = miray + d * sin(theta);
                arriba = arriba + 1;
                abajo = abajo - 1;

            }
        }
    }
}

//Función de rotado para el cambio de turno
void Camara::rota(Menu& principal)
{
    if (!principal.getMenu())
    {
        double d{};
        double theta{};

        //Ángulo en radianes. Permite un giro hasta 180º

        if (rotar && fabs(theta) <= 0)
        {
            estatico = FALSE;
            //Se guarda la posición anterior
            double antesX = posx, antesZ = posz;

            //Se calcula la nueva posición de la cámara
            d = sqrt((posx - mirax) * (posx - mirax) + (posz - miraz) * (posz - miraz));
            theta = atan2((posz - miraz), (posx - mirax));
            theta = theta + 0.05;

            if (theta >= 0 && theta != (atan2((15.0 - 15.0), (-20.0 - 12.0)) + 0.0291) && cambionegro == FALSE)
                theta = 0;
            if (theta <= 0 && cambionegro == TRUE)
                theta = 3.1416;;
            posx = mirax + d * cos(theta);
            posz = miraz + d * sin(theta);
           
            //Cuando se llega a los 180º, cambia de turno y al volver a pulsar el espacio gira otra vez.
            if (theta == 0)
            {
                estatico = TRUE;
                rotar = FALSE;
                cambionegro = TRUE;
            }

            if (theta == 3.1416)
            {
                estatico = TRUE;
                rotar = FALSE;
                cambionegro = FALSE;
            }
        }
    }
}