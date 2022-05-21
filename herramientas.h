#include"interfaz.h"

class Herramientas{
      Interfaz GT;
      int herramienta_defecto;
      int color_defecto;
      int color_fondodefecto;

      public:
             Herramientas();
             ~Herramientas() {}
             void seleccionar_herramienta(int);
             int obtener_herramienta_actual();
             void establecer_herramienta(int,int);
             void herramienta_disponible();
       };

Herramientas::Herramientas()
{
              herramienta_defecto=CONECTOR;
}

void Herramientas::seleccionar_herramienta(int t)
{

     switch(t)
       {
                       case 0:
                            GT.tips("Conector seleccionado, mantenga el click y arrastre el mouse");
                            GT.boton_seleccionado(30,140,80," ");
                            readimagefile("Conector.JPG",32,142,77,177);
                            break;

                       case 1:
                            GT.tips("Cuadro seleccionado, mantenga el click y arrastre el mouse ");
                            GT.boton_seleccionado(30,280,80," ");
                            readimagefile("Caja.JPG",32,282,77,317);
                            break;

                       case 2:
                            GT.tips("Nodo seleccionado, haga un click para elegir el centro");
                            GT.boton_seleccionado(30,210,80," ");
                            readimagefile("Nodo.JPG",32,212,77,247);
                            break;
       }
}
void Herramientas::establecer_herramienta(int x,int y)
{
    if((x>=30 && x<=80)&&(y>=140 && y<=180))
        {
              herramienta_disponible();
              herramienta_defecto=CONECTOR;
              seleccionar_herramienta(herramienta_defecto);
        }

    else if((x>=30 && x<=80)&&(y>=280 && y<=320))
        {
              herramienta_disponible();
              herramienta_defecto=CAJA;
              seleccionar_herramienta(herramienta_defecto);
        }

    else if((x>=30 && x<=80)&&(y>=210 && y<=250))
        {
              herramienta_disponible();
              herramienta_defecto=NODO;
              seleccionar_herramienta(herramienta_defecto);
        }

}
void Herramientas::herramienta_disponible()
{
        switch(herramienta_defecto)
       {
                       case 0:
                            GT.boton_sinseleccionar(30,140,80," ");
                            readimagefile("Conector.JPG",32,142,77,177);
                            break;

                       case 1:
                            GT.boton_sinseleccionar(30,280,80," ");
                            readimagefile("Caja.JPG",32,282,77,317);
                            break;

                       case 2:
                           GT.boton_sinseleccionar(30,210,80," ");
                           readimagefile("Nodo.JPG",32,212,77,247);
                            break;
       }
}

int Herramientas::obtener_herramienta_actual()
{
    return herramienta_defecto;
}
