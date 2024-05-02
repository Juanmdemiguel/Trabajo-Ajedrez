#include "camara.h"

Camara::Camara()
{
    posx = -20.0;
    posy = 40.0;
    posz = 15.0;
    mirax = 12.0;
    miray = 0.0;
    miraz = 15.0;
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

//No se usa todavía
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
        double zoom = 0.5; // Ajusta el factor de zoom según sea necesario

        double dirx = mirax - posx;
        double diry = miray - posy;
        double dirz = miraz - posz;

        // Normaliza el vector de dirección
        double modulodir = sqrt(dirx * dirx + diry * diry + dirz * dirz);
        double unitariodirx = dirx / modulodir;
        double unitariodiry = diry / modulodir;
        double unitariodirz = dirz / modulodir;


        if (key == '+')
        {
            // Mueve el punto de mira en la dirección opuesta al vector de dirección de la cámara
            posx = posx + unitariodirx * zoom;
            posy = posy + unitariodiry * zoom;
            posz = posz + unitariodirz * zoom;
        }



        else if (key == '-')
        {
            // Mueve el punto de mira en la dirección del vector de dirección de la cámara
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

//Restricción de giro sin implemetar
void Camara::rota(Menu& principal)
{
    if (!principal.getMenu())
    {
        if (rotar)
        {
            float theta{};
            float d;

            d = sqrt((posx - mirax) * (posx - mirax) + (posz - miraz) * (posz - miraz));
            theta = atan2((posz - miraz), (posx - mirax));
            theta = theta + 0.05;
            posx = mirax + d * cos(theta);
            posz = miraz + d * sin(theta);

            theta = 0;
            rotar = FALSE;
        }
    }
}