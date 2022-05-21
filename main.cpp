#include <iostream>
#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
#include "componentes.h"
#include<string.h>
#include<conio.h>

using namespace std;


int main()
{
       initwindow(getmaxwidth( ), getmaxheight( ),"Simulador Automata");

	   componentes  P;

	   P.mostrar_ventana();
       P.iniciar_programa();

	   getch();
       closegraph();
       return 0;
}
