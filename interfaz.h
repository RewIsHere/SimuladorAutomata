#include<graphics.h>
#include <math.h>

 # define CONECTOR 0
 # define CAJA 1
 # define NODO 2

class Interfaz
       {
	  public:
		Interfaz( ) {}
		~Interfaz( ) { }
		void boton_sinseleccionar(int,int,int,char*);
		void boton_seleccionado(int,int,int,char *);
		void mostrar_porcion(int,int,int,int);
        void borrar_panel(int,int,int,int,int);
        void comprobar_menu(int , int);
        void colocarEnPantalla(int,int,int);
        void tips(char*);

};

void Interfaz::boton_sinseleccionar(int izquierda,int arriba,int derecha,char inferior[])
 {
     setlinestyle(SOLID_LINE,0,5);
     setcolor(COLOR(54,54,54));
     int abajo=arriba+40;

     rectangle(izquierda,arriba,derecha,abajo);
     setfillstyle(1,LIGHTBLUE);
     bar(izquierda+1,arriba+1,derecha-1,abajo-1);

     int x=((derecha-izquierda)/2)+izquierda;

     int len=(strlen(inferior)*15)/2;
     setbkcolor(LIGHTBLUE);
     settextstyle(TRIPLEX_FONT,0,3);
	 setcolor(RED);
     outtextxy(x-len,arriba+10,inferior);
     setbkcolor(BLACK);
}

void Interfaz::boton_seleccionado(int izquierda,int arriba,int derecha,char inferior[])
{
     setlinestyle(SOLID_LINE,0,5);
     setcolor(COLOR(17,193,56));
     int abajo=arriba+40;

     rectangle(izquierda,arriba,derecha,abajo);
     setfillstyle(1,COLOR(93,93,93));
     bar(izquierda+1,arriba+1,derecha-1,abajo-1);

     int x=((derecha-izquierda)/2)+izquierda;

     int len=(strlen(inferior)*15)/2;
     setbkcolor(COLOR(93,93,93));
     settextstyle(TRIPLEX_FONT,0,3);
	 setcolor(RED);
     outtextxy(x-len,arriba+10,inferior);
     setbkcolor(BLACK);
     delay(200);
}

void Interfaz::borrar_panel(int x1,int y1,int x2,int y2,int bc)
{
      setbkcolor(bc);
      setfillstyle(1,bc);
      bar(x1,y1,x2,y2);
}


void Interfaz::colocarEnPantalla(int t,int x1, int y1)
    {
		                setcolor(COLOR(54,54,54));
		                setbkcolor(COLOR(54,54,54));
                        setfillstyle(SOLID_FILL,COLOR(54,54,54));
                        if(t == CONECTOR)
                        {
                            tips("Conector seleccionado, mantenga el click y arrastre el mouse");
                             int x2,y2;
                             while (!ismouseclick(WM_LBUTTONUP))
                              delay(5);
                             getmouseclick(WM_LBUTTONUP, x2, y2);
                             if((x2>=230 && x2 <=getmaxx()-18)&&(y2>=97&&y2<=getmaxy()-13))
                               setcolor(COLOR(255,255,0));
                               line(x1,y1,x2,y2);
                        }
                        else if(t == NODO)
                        {
                            tips("Nodo seleccionado, haga un segundo click para completar ");

                            int r,cx,cy;
                    while(1)
                    {

                        if(ismouseclick(WM_LBUTTONDOWN)){

                            cx = mousex();
                            cy = mousey();
                            clearmouseclick(WM_LBUTTONDOWN);
                            }
                        if(cx<=getmaxx()-18 && cx >= 230 && cy<=getmaxy()-13 && cy>=97)
                            {
                                r= sqrt(pow((cx-x1) , 2) + pow((cy-y1) , 2) );
                                break;
                            }

                    }
                for(int i=230; i <=getmaxx()-18; i++)
                {
                    for(int j=97; j<=getmaxy()-13;j++)
                    {
                        if(abs(r - sqrt(pow((x1-i) , 2) + pow((y1-j) , 2)))<=5)
                        {
                            putpixel(i,j,COLOR(54,54,54));
                        }
                    }
                }
                tips("Nodo seleccionado, haga un click para elegir el centro");

                        }
                        else if(t == CAJA)
                        {
                              int x2,y2;
                             while (!ismouseclick(WM_LBUTTONUP))
                              delay(5);
							   setbkcolor(COLOR(54,54,54));                                            //
                             getmouseclick(WM_LBUTTONUP, x2, y2);
                             if((x2>=230 && x2 <=getmaxx()-18)&&(y2>=97&&y2<=getmaxy()-13))
                               {
									rectangle(x1,y1,x2,y2);
                                    floodfill((x1+x2)/2, (y1+y2)/2, COLOR(54,54,54));
							   }
                        }
    }
void Interfaz::tips(char *texto)
{
     setfillstyle(1,COLOR(93, 93, 93));
    bar(700,18,getmaxx( )-18 ,70);

    setcolor(WHITE);
    setbkcolor(COLOR(93, 93, 93));
    settextstyle(SANS_SERIF_FONT,0,3);
    outtextxy(720,20,texto);
}
