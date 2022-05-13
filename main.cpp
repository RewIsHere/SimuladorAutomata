#include <graphics.h>

int main()
{
    /*initwindow(getmaxwidth(),getmaxheight());
    getch();*/

    //Esto es un comentario

    /*Para empezar, hemos declarado dos variables de tipo int gd y gm para el controlador de
    gráficos y el modo de gráficos respectivamente, también puede elegir cualquier otro nombre de
    variable. DETECT es una macro definida en el archivo de encabezado "graphics.h", luego hemos
    pasado tres argumentos a la función initgraph: primero es la dirección de gd, segundo es la dirección
    de gm y tercero es la ruta donde están presentes sus archivos BGI (tiene para ajustar esto según
    el lugar donde esté instalado el compilador Turbo C). La función Initgraph decide automáticamente
    un controlador de gráficos y un modo apropiados, de modo que se establece la resolución máxima
    de pantalla, getch nos ayuda a esperar hasta que se presiona una tecla, la función closegraph
    cierra el modo de gráficos.*/

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
