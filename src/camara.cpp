#include "camara.h"
#include <iostream>

Camara::Camara()
{
    posx = -20.0;
    posy = 40.0;
    posz = 15.0;
    mirax = 12.0;
    miray = 0.0;
    miraz = 15.0;
    suma = 0.0;
    angulo = 0.0;
}

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

void Camara::zoom(Menu& principal, unsigned char key)
{
    if (!principal.getMenu())
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


        if (key == '+')
        {
            // Mueve el punto de mira en la direcci�n opuesta al vector de direcci�n de la c�mara
            posx = posx + unitariodirx * zoom;
            posy = posy + unitariodiry * zoom;
            posz = posz + unitariodirz * zoom;
        }



        else if (key == '-')
        {
            // Mueve el punto de mira en la direcci�n del vector de direcci�n de la c�mara
            posx = posx - unitariodirx * zoom;
            posy = posy - unitariodiry * zoom;
            posz = posz - unitariodirz * zoom;
        }
    }
}

void Camara::vertical(Menu& principal, unsigned char key)
{
    if (!principal.getMenu())
    {
        if (key == 'w')
        {
            float d = sqrt((posx - mirax) * (posx - mirax) + (posy - miray) * (posy - miray));
            double theta = atan2((posy - miray), (posx - mirax));
            theta = theta + 0.05;
            posx = mirax + d * cos(theta);
            posy = miray + d * sin(theta);

        }
        if (key == 's')
        {
            float d = sqrt((posx - mirax) * (posx - mirax) + (posy - miray) * (posy - miray));
            double theta = atan2((posy - miray), (posx - mirax));
            theta = theta - 0.05;
            posx = mirax + d * cos(theta);
            posy = miray + d * sin(theta);

        }
    }
}

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
            theta = theta + 0.001;
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
                if (cambionegro == true)
                {
                    cambionegro = false;
                }
                else if (cambionegro == false)
                {
                    cambionegro = true;
                }
                rotar = FALSE;
                angulo = 0;
                suma = 0;
            }
        }

    }
}