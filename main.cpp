#include <graphics.h>

int main()
{
    /*initwindow(getmaxwidth(),getmaxheight());
    getch();*/

    //Esto es un comentario

    /*Para empezar, hemos declarado dos variables de tipo int gd y gm para el controlador de
    gr�ficos y el modo de gr�ficos respectivamente, tambi�n puede elegir cualquier otro nombre de
    variable. DETECT es una macro definida en el archivo de encabezado "graphics.h", luego hemos
    pasado tres argumentos a la funci�n initgraph: primero es la direcci�n de gd, segundo es la direcci�n
    de gm y tercero es la ruta donde est�n presentes sus archivos BGI (tiene para ajustar esto seg�n
    el lugar donde est� instalado el compilador Turbo C). La funci�n Initgraph decide autom�ticamente
    un controlador de gr�ficos y un modo apropiados, de modo que se establece la resoluci�n m�xima
    de pantalla, getch nos ayuda a esperar hasta que se presiona una tecla, la funci�n closegraph
    cierra el modo de gr�ficos.*/

    int gd = DETECT, gm; //VARIABLES PARA EL CONTROLADOR DE GRAFICOS
    initgraph(&gd, &gm, "");//PARA CARGAR EL DRIVER DE LA GRAFICA
    initwindow(getmaxwidth(),getmaxheight(),"LOBO DOMESTICADO");

    setcolor(RED);//ESTABLECEMOS COLOR DEL RECTANGULO
    rectangle(2,2,120,120);//DEFINIMOS E IMPRIMIMOS EL RECTANGULO

    setcolor(WHITE);//COLOR DEL TEXTO
    settextstyle(DEFAULT_FONT,HORIZ_DIR,3);//DEFINIMOS EL ESTILO DEL TEXTO
    outtextxy(200,150,"Presione el circulo rojo para salir");

    setcolor(WHITE);
    line(100,200,1150,200);//(X1,Y1,X2,Y2) DIBUJA DE X1 A X2 Y Y1 A Y2

    getch();
    closegraph();//CERRAMOS LA PANTALLA GRAFICA
}
