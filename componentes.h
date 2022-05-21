#include"herramientas.h"


class componentes
       {
            Herramientas T;
            Interfaz GP;

	  public:
		componentes( );
		~componentes( ) { }
        void mostrar_ventana();
        void iniciar_programa();
};

componentes::componentes( )
{}

void componentes::mostrar_ventana()
{
    cleardevice( );

// ================== CABECERA DE VENTANA ==================
    setfillstyle(1,COLOR(43, 43, 43));
    bar(0,0,getmaxx( ),90);

    setcolor(COLOR(185, 196, 188));
    setbkcolor(COLOR(43, 43, 43));
    settextstyle(BOLD_FONT,0,2);
	outtextxy(50,22,"Simulador de Automatas");
// ===================== FIN DE CABECERA =====================

    setfillstyle(1,COLOR(93, 93, 93));
    bar(700,18,getmaxx( )-18 ,70);

// ===================== MENU LATERAL =====================
    setfillstyle(1,COLOR(54,54,54));
    bar(0,90,225,getmaxy( ));
// ===================== FIN DE MENU LATERAL =====================


// AREA DE TRABAJO
    setfillstyle(1, COLOR(16,16,16));
    bar(225,90,getmaxx( )-13,getmaxy( )-13);
// FIN DE AREA DE TRABAJO


// MENU LATERAL BOTONES
    setcolor(COLOR(185, 196, 188));
    setbkcolor(COLOR(54,54,54));
    settextstyle(BOLD_FONT,0,1);
    outtextxy(17,107,"Seleccionar:");

	   GP.boton_sinseleccionar(30,140,80," ");
	   readimagefile("Conector.JPG",32,142,77,177);

       GP.boton_sinseleccionar(30,280,80," ");
       readimagefile("Caja.JPG",32,282,77,317);

       GP.boton_sinseleccionar(30,210,80," ");
       readimagefile("Nodo.JPG",32,212,77,247);

       setcolor(WHITE);
       settextstyle(SIMPLEX_FONT,0,2);
// FIN DE BOTONES

}

void componentes::iniciar_programa()
{
       int mx,my;
       while(true)
       {

			while (!ismouseclick(WM_LBUTTONDOWN))
			 delay(5);

         getmouseclick(WM_LBUTTONDOWN, mx, my);
         clearmouseclick(WM_LBUTTONDOWN);
         clearmouseclick(WM_LBUTTONUP);
         if( (mx>=30 && mx <=180)&&(my>=140&&my<=320) )
            {
                          T.establecer_herramienta(mx,my);
            }
        else if( (mx>=230 && mx <=getmaxx()-18)&&(my>=97&&my<=getmaxy()-13) )
            {
                           GP.colocarEnPantalla(T.obtener_herramienta_actual(),mx,my);
            }
          else
        {
                  clearmouseclick(WM_LBUTTONDOWN);
                  clearmouseclick(WM_LBUTTONUP);
          }
       }
}
