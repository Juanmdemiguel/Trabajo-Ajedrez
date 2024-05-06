#include "camara.h"
#include <iostream>
#define mirax 12.0
#define miray 0.0
#define miraz 15.0

Camara::Camara()
{
    posx = -20.0;
    posy = 40.0;
    posz = 15.0;
    suma = 0.0;
    angulo = 0.0;
}

//Establece posiciones iniciales de la camara tanto en el menu como al iniciar la partida
void Camara::dibuja(Menu& principal)
{
    if (principal.getMenu())
    {
        gluLookAt(0.0, 7.5, 20.0,  // posicion del ojo
            0.0, 7.5, 0.0,      // hacia que punto mira  (0,0,0)
            0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)
    }
    else
    {
        gluLookAt(posx, posy, posz,  // posicion del ojo
            mirax, miray, miraz,      // hacia que punto mira  (0,0,0) 
            0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)*/  
    }
}

//No se usa todav�a
void Camara::set_pos(double _posx, double _posy, double _posz)
{
    posx = _posx;
    posy = _posy;
    posz = _posz;
}

//Permite cambiar al modo en el que se mueven las piezas, que no admite movimientos de camara adicionales y regresar
void Camara::cambio_modo_libre(Menu& principal, unsigned char key)
{
    if (!principal.getMenu() && angulo == 0)
    {
        //Al pulsar l se entra en el modo y se vuelve a la posici�n de la camara original segun juege un color u otro
        if (key == 'l' && modolibre == FALSE)
        {
            modolibre = TRUE;
            if (!cambionegro)
                posx = -20.0;
            if (cambionegro)
                posx = 44.0;
            posy = 40.0;
            posz = 15.0;
            zoomin = 0;
            zoomout = 0;
            arriba = 0;
            abajo = 0;
        }
        //Al volver a pulsar l se sale del modo manteniendo la posici�n original segun juegue un color u otro
        else if (key == 'l' && modolibre == TRUE)
        {
            modolibre = FALSE;
            if (!cambionegro)
                posx = -20.0;
            if (cambionegro)
                posx = 44.0;
            posy = 40.0;
            posz = 15.0;
            zoomin = 0;
            zoomout = 0;
            arriba = 0;
            abajo = 0;
        }
    }
}

//Permite la rotaci�n al cambiar de turno (provisionalmente se acciona al pulsar el espacio)
void Camara::actuador(Menu& principal, unsigned char key)
{
    if (!principal.getMenu())
    {
        bool _rotar;
        _rotar = FALSE;
        if (key == ' ')
            _rotar = TRUE;
        rotar = _rotar;
    }
}

//Permite acercar la camara al tablero al pulsar '+' y alejarla al pulsar '-'
void Camara::zoom(Menu& principal, unsigned char key)
{
    if (!principal.getMenu() && modolibre)
    {
        double zoom = 0.5; // Ajusta el factor de zoom seg�n sea necesario

        double dirx = mirax - posx;
        double diry = miray - posy;
        double dirz = miraz - posz;

        // Normaliza el vector de direcci�n
        double modulodir = sqrt(dirx * dirx + diry * diry + dirz * dirz);
        double unitariodirx = dirx / modulodir;
        double unitariodiry = diry / modulodir;
        double unitariodirz = dirz / modulodir;


        if (key == '+' && angulo ==0 && zoomin < 30)
        {
            // Mueve el punto de mira en la direcci�n opuesta al vector de direcci�n de la c�mara
            posx = posx + unitariodirx * zoom;
            posy = posy + unitariodiry * zoom;
            posz = posz + unitariodirz * zoom;
            zoomin = zoomin + 1;
            zoomout = zoomout - 1;
        }



        else if (key == '-' && angulo == 0 && zoomout < 20)
        {
            // Mueve el punto de mira en la direcci�n del vector de direcci�n de la c�mara
            posx = posx - unitariodirx * zoom;
            posy = posy - unitariodiry * zoom;
            posz = posz - unitariodirz * zoom;
            zoomin = zoomin - 1;
            zoomout = zoomout + 1;
        }
    }
}

//Permite ver el tablero desde arriba al pulsar 'w' y de forma frontal al pulsar 's' independientemente del color que tenga el turno
void Camara::vertical(Menu& principal, unsigned char key)
{
    if (!principal.getMenu() && modolibre)
    {
        float d = sqrt((posx - mirax) * (posx - mirax) + (posy - miray) * (posy - miray));
        double theta = atan2((posy - miray), (posx - mirax));
        if (cambionegro)
        {
            if ((key == 'w' || key == 'W') && arriba < 10 && angulo == 0)
            {
                
                theta = theta + 0.05;
                posx = mirax + d * cos(theta);
                posy = miray + d * sin(theta);
                arriba = arriba + 1;
                abajo = abajo - 1;
            }
            if ((key == 's' || key == 'S') && abajo < 18 && angulo == 0)
            {
                
                theta = theta - 0.05;
                posx = mirax + d * cos(theta);
                posy = miray + d * sin(theta);
                arriba = arriba - 1;
                abajo = abajo + 1;

            }
        }
        //Si se cambia de turno se invierten los comandos
        if (!cambionegro)
        {
            if ((key == 's' || key == 'S') && abajo < 18 && suma == 0)
            {
               
                theta = theta + 0.05;
                posx = mirax + d * cos(theta);
                posy = miray + d * sin(theta);
                arriba = arriba - 1;
                abajo = abajo + 1;

            }
            if ((key == 'w' || key == 'W') && arriba < 10 && suma == 0)
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

//Funci�n de rotado para el cambio de turno
void Camara::rota(Menu& principal)
{
    if (!principal.getMenu())
    {
        double d{};
        double theta{};
        double DistRecorrida{};
        //�ngulo en radianes. Permite un giro hasta 180�

        if (rotar && angulo < 3.141592653589793)
        {
            //Se guarda la posici�n anterior
            double antesX = posx, antesZ = posz;
            //Se calcula la nueva posici�n de la c�mara
            d = sqrt((posx - mirax) * (posx - mirax) + (posz - miraz) * (posz - miraz));
            theta = atan2((posz - miraz), (posx - mirax));
            //Giro muy lento pero el incremento no debe ser mayor porque si no el tablero se tuerce.
            // Debe buscarse una alternativa 
            theta = theta + 0.0291;
            posx = mirax + d * cos(theta);
            posz = miraz + d * sin(theta);
            //Se calcula la distancia recorrida entre cada incremento de la c�mara
            DistRecorrida = sqrt((posx - antesX) * (posx - antesX) + (posz - antesZ) * (posz - antesZ));
            //Se calcula la longitud recorrida a lo largo del per�metro de la circunferencia que forma la c�mara
            suma += DistRecorrida;
            //Mediante la distancia recorrida, se calcula el �ngulo formado con respecto el centro
            angulo = (suma / d);

            //Cuando se llega a los 180�, cambia de turno y al volver a pulsar el espacio gira otra vez.
            if (angulo >= 3.141592653789793)
            {
                cambionegro = !cambionegro;
                rotar = FALSE;
                angulo = 0;
                suma = 0;
            }
        }

    }
}