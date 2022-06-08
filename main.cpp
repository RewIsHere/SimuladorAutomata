#include <fstream>
#include <iostream>
#include "include/colors.hpp"
#include "include/button.hpp"
#include "include/vertex.hpp"
#include "include/list_vertices.hpp"
#include "include/helpers.hpp"
#include "include/constants.hpp"
#include "include/global_variables.hpp"

void drawWindow();
void dibujarZonaTrabajo();
void dibujarZonaLimites();
void dibujarZonaDelMenu();
void dibujarZonaDeTexto();
void drawMatrixZone();
void showSpeed();
void showAllButtons();
void refrescarPantalla();
void refrescarGrafica(int);
void initScreen();
void initializer();

void agregarVertice();
void addEdges();
void renameVertex();
void deleteVertex();
void moveVertex();
void cleanGraph();

void removeVertex(int);
void removeRow(int);
void removeCol(int);
void removeLast();

void drawEdge(int, int, int);
void drawAllEdges();
int chooseVertex(int, int skipReset = -1);
bool chooseStartVertex(int &, const char*, const char*);
bool chooseTwoVertices(int &, int &);
char getKey();
void adjustSpeed(char);
bool isEmptyGraph();


bool getInputChar(char *, int, bool (*)(char));
bool getInputWeight(float &);


void setTextPrintStyle(int);
void printText(float);
void printText(const char*);
void deleteText(const char*);
template <typename Type>
void printTextWl(Type);
template <typename Type>
void printTextWlb(Type);

int findButton(int, int);
void switchMenuItem(int);
void menu();
void backToMenu();

//----------------------------------------------
//PRUEBA V1 Y V2 DE IMPEMENTACION DE ARBOLES PARA SIMULACION
//creacion de nodo
/*
//creacion de nodo
struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
};
//Prototipos
 Nodo *crearNodo(int);
void insertarNodo(Nodo *&,int);
void menu();
void mostrarArbol(Nodo *,int);

Nodo *arbol =NULL;


int main(){

	menu();

}

//Funcion de menu
void menu(){
	int dato, opcion, contador=0;

	do{
		printf("\n Menu:\n");
		printf("\n 1.- Insertar un nuevo nodo");
		printf("\n 2.-Mostrar arbol completo");
		printf("\n 3.-Salir");

		scanf("%d",&opcion);

		switch(opcion){
			case 1:
				printf("Digite un numero:");
					scanf("%d",&dato);
					insertarNodo(arbol,dato); //Insertamos un nuevo nodo
					printf("\n");
					system("pause");
					break;
			case 2:
			printf("\nMostrar el arbol completo: \n\n");
			mostrarArbol(arbol,contador);
			printf("\n \n");
			system("pause");
			break;

		}
		system("cls");
	}while(opcion != 3);
}

//Funcion para crear un nuevo nodo

 Nodo *crearNodo(int n){
	Nodo *nuevo_nodo = new Nodo();

	nuevo_nodo->dato =n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;

		return nuevo_nodo;
}

//Funcion para insertar elementos en el arbol
void insertarNodo(Nodo *&arbol,int n){
	if(arbol==NULL){ //Si el arbol esta vacio
		struct Nodo *nuevo_nodo = crearNodo(n);
		arbol=nuevo_nodo;
	}
	else{//Si el arbol tiene uno o mas de un nodo
	int valorRaiz = arbol ->dato; //Obtener valor de la raiz
	//n<valorRaiz
	if(n == 0){ //Si el elemento es igual a 0, falso, insertamos a la izquierda
		insertarNodo(arbol->izq,n);
	}
	else{ //sI EL ELEMENTO es diferente de 0, verdadero, insertamos a la derecha
	insertarNodo(arbol->der,n);
	}

	}
}

//Funcion para mostrar arbolcompleto

void mostrarArbol(Nodo *arbol,int contador){
	if(arbol==NULL){
		return;

	}
	else{
		mostrarArbol(arbol ->der,contador+1);
		for(int i=0;i<contador;i++){
			printf("   ");
		}
		printf("%d-----\n",arbol->dato);
		mostrarArbol(arbol->izq,contador+1);
	}
}

struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
};
*/
//-------------------------------------------------


int main()
{
    initializer();
	menu();
	closegraph();
	return EXIT_SUCCESS;
}
void dibujarZonaTrabajo()
{
	setfillstyle(SOLID_FILL, wZONE_COLOR);
	bar(wbLEFT, wTOP, wRIGHT, wBOTTOM);
	setcolor(COLOR_LINEA);
	setlinestyle(SOLID_LINE, 1, 2);
	rectangle(wLEFT, wTOP, wRIGHT, wBOTTOM);
}
void dibujarZonaLimites()
{
	setcolor(LIMIT_COLOR);
	setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
	rectangle(wbLEFT + 2, wTOP + 2, wRIGHT - 2, wBOTTOM - 2);
}
void dibujarZonaDelMenu()
{
	setbkcolor(COLOR_FONDO);
	setusercharsize(1, 2, 1, 2);
	settextstyle(COMPLEX_FONT, HORIZ_DIR, USER_CHAR_SIZE);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	setcolor(BLACK);
	outtextxy(5, mTOP - 20, "EJECUTAR");
	outtextxy(5, fTOP - 20, "");
	outtextxy(5, aTOP - 20, "Matriz");
	setlinestyle(SOLID_LINE, 1, 2);
	setcolor(COLOR_LINEA);
	rectangle(mLEFT, mTOP, mRIGHT, mBOTTOM);
	rectangle(fLEFT, fTOP, fRIGHT, fBOTTOM);
}
void dibujarZonaDeTexto()
{
	setfillstyle(SOLID_FILL, COLOR_FONDO);
	bar(tLEFT, tTOP, tRIGHT, tBOTTOM);
	setcolor(COLOR_LINEA);
	setlinestyle(SOLID_LINE, 1, 2);
	rectangle(tLEFT, tTOP, tRIGHT, tBOTTOM);
	xCursor = xCURSOR;
	yCursor = yCURSOR;
}

void showSpeed()
{
	char status[15];
	char speed[3];
	convertToChar((MAX_SPEED - delayRunTime) / 100, speed);
	strcpy(status, "Speed: ");
	strcat(status, speed);
	setcolor(BLACK);
	setfillstyle(SOLID_FILL, COLOR_FONDO);
	bar(sLEFT, sTOP, sRIGHT, sBOTTOM);
	setbkcolor(COLOR_FONDO);
	setusercharsize(1, 2, 1, 2);
	settextstyle(COMPLEX_FONT, HORIZ_DIR, USER_CHAR_SIZE);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	outtextxy(sLEFT, sTOP, status);
}
void drawWindow()
{
	setcolor(DOT_COLOR);
	setbkcolor(COLOR_FONDO);
	setfillstyle(CLOSE_DOT_FILL, wZONE_COLOR);
	bar(0, 0, WINDOW_WIDTH, WINDOW_HIGHT);
}
void showAllButtons()
{
	for (int i = 0; i < NUM_OF_MENU; ++i)
	{
		menuButton[i].showNormalButton();
		showButtonIcon(menuButton, i);
	}
}
void initScreen()
{
	drawWindow();
	dibujarZonaTrabajo();
	dibujarZonaDeTexto();
	dibujarZonaDelMenu();
	showAllButtons();
	showSpeed();
}
void initializer()
{
	initwindow(WINDOW_WIDTH + 5, WINDOW_HIGHT + 10, "Simulador de Automatas");
	hwnd = GetActiveWindow();
	::SetWindowLong(hwnd, GWL_STYLE, GetWindowLong(hwnd, GWL_STYLE)&~WS_MAXIMIZEBOX);
    initScreen();
    setMatrixTo(adjaGraph, NO_EDGE_VALUE);
}

inline void removeRow(int row)
{
	for (int i = row; i < listv.num - 1; ++i)
		for (int j = 0; j < listv.num; ++j)
			adjaGraph[i][j] = adjaGraph[i + 1][j];
}
inline void removeCol(int col)
{
	for (int i = 0; i < listv.num; ++i)
		for (int j = col; j < listv.num - 1; ++j)
			adjaGraph[i][j] = adjaGraph[i][j + 1];
}
inline void removeLast()
{
	const int &LAST = listv.num - 1;
	for (int i = 0; i < listv.num; ++i)
	{
		adjaGraph[LAST][i] = NO_EDGE_VALUE;
		adjaGraph[i][LAST] = NO_EDGE_VALUE;
	}
}
void removeVertex(int v)
{
	removeCol(v);
	removeRow(v);
	removeLast();
}

void drawEdge(int begin, int end, int color)
{
	const int &x1 = listv.v[begin]->x;
	const int &y1 = listv.v[begin]->y;
	const int &x2 = listv.v[end]->x;
	const int &y2 = listv.v[end]->y;
	if (adjaGraph[end][begin] == NO_EDGE_VALUE || begin < end)
		drawArrow(x1, y1, x2, y2, color, adjaGraph[begin][end]);
	else
		drawCurvedLine(x1, y1, x2, y2, color, adjaGraph[begin][end]);
}
void drawAllEdges()
{
	for (int i = 0; i < listv.num; ++i)
		for (int j = 0; j < listv.num; ++j)
			if (adjaGraph[i][j] != NO_EDGE_VALUE)
				drawEdge(i, j, EDGE_COLOR);
}
int chooseVertex(int highLightColor, int skipReset)
{
	dibujarZonaLimites();
	int x, y;
	int newPos(-1), oldPos(-1);
	while (1)
	{
		if (getKey() == KEY_ESC) break;
		newPos = listv.find(mousex(), mousey());
		if (newPos != oldPos)
		{
			if (newPos != -1 && newPos != skipReset)
				listv.v[newPos]->show(highLightColor);
			if (oldPos != -1 && oldPos != skipReset)
				listv.v[oldPos]->show(VERTEX_COLOR);
			oldPos = newPos;
		}
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if (!isInWorkingZone(x, y)) break;
			if (newPos != -1)
			{
				listv.v[newPos]->show(highLightColor);
				return newPos;
			}
		}
		delay(DELAY_VALUE);
	}
	return -1;
}
bool chooseStartVertex(int &start, const char *text1, const char *text2)
{
	setTextPrintStyle(TEXT_COLOR);
	printText(text1);
	start = chooseVertex(VERTEX_CHOOSING_COLOR);
	if (start == -1) return 0;
	setTextPrintStyle(TEXT_COLOR);
	printText(listv.v[start]->name);
	printTextWlb(text2);
	return 1;

}
bool chooseTwoVertices(int &start, int &stop)
{
	setTextPrintStyle(TEXT_COLOR);
	start = chooseVertex(VERTEX_CHOOSING_COLOR);
	if (start == -1) return 0;
	setTextPrintStyle(TEXT_COLOR);
	printTextWl(listv.v[start]->name);
	listv.v[start]->show(VERTEX_CHOSE_COLOR);
	setTextPrintStyle(TEXT_COLOR);
	stop = chooseVertex(VERTEX_CHOOSING_COLOR, start);
	if (stop == -1) return 0;
	setTextPrintStyle(TEXT_COLOR);
	printTextWl(listv.v[stop]->name);
	listv.v[stop]->show(VERTEX_CHOSE_COLOR);
	if (start == stop)
	{
		listv.v[stop]->show(VERTEX_COLOR);
		return 0;
	}
	return 1;
}
bool isEmptyGraph()
{
	if (listv.num == 0)
	{
		MessageBox(hwnd, "Ha ocurrido un problema", "ERROR", MB_APPLMODAL | MB_ICONERROR);
		return 1;
	}
	return 0;
}
void adjustSpeed(char key)
{
	if (key == KEY_LEFT)
		delayRunTime = (delayRunTime < MAX_SPEED) ? delayRunTime + 100 : MAX_SPEED;
	else if (key == KEY_RIGHT)
		delayRunTime = (delayRunTime > 100) ? delayRunTime - 100 : 0;
	showSpeed();
}
char getKey()
{
	if (kbhit())
	{
		char c = getch();
		switch (c)
		{
			case KEY_ESC:
				return KEY_ESC;
			case ARROW_KEY:
				c = getch();
				adjustSpeed(c);
				return c;
			case KEY_Q:
				return KEY_Q;
			case KEY_LQ:
				return KEY_Q;
			default:
				return KEY_NULL;
		}
	}
	return KEY_NULL;
}

void setTextPrintStyle(int color)
{
//	setusercharsize(9, 10, 9, 10);
	settextstyle(COMPLEX_FONT, HORIZ_DIR, 1);
	setbkcolor(COLOR_FONDO);
	setcolor(color);
	settextjustify(LEFT_TEXT, TOP_TEXT);
}
bool getInputWeight(float &res)
{
	char str[10];
	getInputChar(str, 10, inputFloat);
	if (!isFloat(str)) return 0;
	res = roundf(toFloat(str) * 100) / 100;
	if (res > MAX_WEIGHT || res < MIN_WEIGHT)
	{
		char msg[70]; char w[10];
		convertToChar(MIN_WEIGHT, w);
		strcat(msg, w);
		convertToChar(MAX_WEIGHT, w);
		strcat(msg, w);
		return 0;
	}
	return 1;
}
bool getInputChar(char *str, int max, bool (*checkKey)(char key))
{
	setTextPrintStyle(BLUE);
	int i = 0; str[0] = '\0';
	char key[2] = {'\0', '\0'};
	while (i < max)
	{
		if (kbhit())
		{
			key[0] = getch();
			if (key[0] == KEY_ESC || key[0] == KEY_ENTER) break;
			if (key[0] == KEY_BACKSPACE && i > 0) {--i; key[0] = str[i]; deleteText(key); str[i] = '\0';}
			else if (checkKey(key[0])) {strcat(str, key); ++i; printText(key);}
		}
		if (ismouseclick(WM_LBUTTONDOWN)) clearmouseclick(WM_LBUTTONDOWN);
		delay(DELAY_VALUE);
	}
	return (i > 0);
}
void deleteText(const char* str)
{
	if (xCursor <= xCURSOR) return;
	const int currentColor = getcolor();
	setTextPrintStyle(COLOR_FONDO);
	const int tw = textwidth(str);
	xCursor -= tw;
	printText(str);
	xCursor -= tw;
	setTextPrintStyle(currentColor);
}
void printText(const char *str)
{
	int const tw = textwidth(str);
	if (xCursor + tw >= tRIGHT)
	{
		xCursor = xCURSOR;
		yCursor += TEXTHIGHT;
	}
	if (yCursor > tBOTTOM - TEXTHIGHT)
	{
		dibujarZonaDeTexto();
		xCursor = xCURSOR;
		yCursor = yCURSOR;
		setTextPrintStyle(TEXT_COLOR);
	}
	outtextxy(xCursor, yCursor, str);
	xCursor += tw;
}
void printText(float value)
{
	char str[MAX_INPUT];
	convertToChar(value, str);
	printText(str);
}
template <typename Type>
void printTextWl(Type s)
{
	printText(s);
	xCursor = xCURSOR;
	yCursor += TEXTHIGHT;
}
template <typename Type>
void printTextWlb(Type s)
{
	xCursor = xCURSOR;
	yCursor += TEXTHIGHT;
	printText(s);
}
void agregarVertice()
{
	dibujarZonaLimites();
	if (listv.num == MAX_VERTEX)
	{
		char msg[45], num[3];
		strcpy(msg, "Se ha alcanzado el maximo de nodos MAX_VERTEX = ");
		convertToChar(MAX_VERTEX, num);
		strcat(msg, num);
		MessageBox(hwnd, msg, "ERROR", MB_APPLMODAL | MB_ICONERROR);
	}
	int x, y;
	setTextPrintStyle(TEXT_COLOR);
	printText("Haga click para añadir un nodo en el area de trabajo");
	while (listv.num < MAX_VERTEX)
	{
		if (getKey() == KEY_ESC) break;
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			getmouseclick(WM_LBUTTONDOWN, x, y);
			if (listv.find(x, y) != -1)
			{
				MessageBox(hwnd, "Ha ocurrido un error.", "ERROR",
							MB_APPLMODAL | MB_ICONERROR);
				continue;
			}
			if (isInLimitZone(x, y))
			{
				listv.addVertex(x, y);
				isSaved = 0;
			}
			else break;
		}
		delay(DELAY_VALUE);
	}
}
void addEdges()
{
	if (isEmptyGraph()) return;
	int begin, end, oldEnd = -1;
	float weight;
	setTextPrintStyle(TEXT_COLOR);
	printText("Haga click en un nodo y arrastre el mouse hacia otro");
	while (1)
	{
		begin = chooseVertex(VERTEX_CHOOSING_COLOR);
		if (begin == -1) break;
		int x = listv.v[begin]->x;
		int y = listv.v[begin]->y;
		if (ismouseclick(WM_LBUTTONUP)) clearmouseclick(WM_LBUTTONUP);
		while (!ismouseclick(WM_LBUTTONUP))
		{
			setactivepage(1 - getactivepage());
			initScreen();
			dibujarZonaLimites();
			drawAllEdges();
			listv.showAll();
			listv.v[begin]->show(VERTEX_CHOSE_COLOR);
			menuButton[ADD_EDGE_MENU].showChoseButton();
			showButtonIcon(menuButton, ADD_EDGE_MENU);
			end = listv.find(mousex(), mousey());
			drawArrow(x, y, mousex(), mousey(), EDGE_HIGHTLIGHT_COLOR, 0);
			setvisualpage(getactivepage());
			if (oldEnd != -1 && oldEnd != end && oldEnd != begin)
				listv.v[oldEnd]->show(VERTEX_COLOR);
			if (end != begin && end != -1 && end != oldEnd)
				listv.v[end]->show(VERTEX_CHOOSING_COLOR);
			oldEnd = end;
			if (!isInWorkingZone(mousex(), mousey())) break;
			delay(DELAY_VALUE);
		}
		if (end == -1 || end == begin)
		{
			refrescarGrafica(ADD_EDGE_MENU);
			listv.v[begin]->show(VERTEX_COLOR);
			continue;
		}
		listv.v[end]->show(VERTEX_CHOSE_COLOR);
		setvisualpage(getactivepage());
		adjaGraph[begin][end] = DEFAULT_WEIGHT;
		refrescarGrafica(ADD_EDGE_MENU);
		drawEdge(begin, end, EDGE_HIGHTLIGHT_COLOR);
		setTextPrintStyle(TEXT_COLOR);
		printText("Nodos conectados correctamente. Presione ENTER para finalizar ");
		if (getInputWeight(weight)) adjaGraph[begin][end] = weight;
		else adjaGraph[begin][end] = NO_EDGE_VALUE;
		isSaved = 0;
		refrescarGrafica(ADD_EDGE_MENU);
		listv.v[begin]->show(VERTEX_COLOR);
		listv.v[end]->show(VERTEX_COLOR);
	}
}
void renameVertex()
{
	if (isEmptyGraph()) return;
	int choose;
	while (1)
	{
		if (chooseStartVertex(choose, "Haga click sobre un nodo para renombrarlo: ", "Escribe el nuevo nombre para "))
		{
			printText(listv.v[choose]->name);
			printText(": ");
			listv.v[choose]->show(VERTEX_CHOSE_COLOR);
			char name[MAX_NAME_LENGTH];
			if (getInputChar(name, MAX_NAME_LENGTH - 1, inputAscii) && !listv.isExist(name))
			{
				listv.updateCurrentName(name);
				listv.v[choose]->clearName();
				strcpy(listv.v[choose]->name, name);
				isSaved = 0;
			}
			else MessageBox(hwnd, "Ha ocurrido un error", "ERROR", MB_APPLMODAL | MB_ICONERROR);
			listv.v[choose]->show(VERTEX_COLOR);
			printTextWl("");
		} else break;
	}
}
void deleteVertex()
{
	if (isEmptyGraph()) return;
	while (listv.num > 0)
	{
		setTextPrintStyle(TEXT_COLOR);
		printText("Seleccione un nodo para eliminarlo: ");
		int choose = chooseVertex(VERTEX_DELETE_COLOR);
		if (choose == -1) break;
		setTextPrintStyle(VERTEX_DELETE_COLOR);
		printText(listv.v[choose]->name);
		removeVertex(choose);
		listv.deleteVertex(choose);
		refrescarGrafica(DELETEVE_MENU);
		isSaved = 0;
		if (listv.num == 0)
			listv.clear();
	}
}
void moveVertex()
{
	if (isEmptyGraph()) return;
	int x, y;
	setTextPrintStyle(TEXT_COLOR);
	printTextWl("Elija un nodo para moverlo y arrastre el mouse");
	while (1)
	{
		int choose = chooseVertex(VERTEX_CHOOSING_COLOR);
		if  (choose == -1) break;
		if (ismouseclick(WM_LBUTTONUP)) clearmouseclick(WM_LBUTTONUP);
		isSaved = 0;
		listv.v[choose]->show(VERTEX_CHOSE_COLOR);
		while (!ismouseclick(WM_LBUTTONUP))
		{
			if (ismouseclick(WM_MOUSEMOVE))
			{
				getmouseclick(WM_MOUSEMOVE, x, y);
				if (!isInLimitZone(x, y)) continue;
				if (GetKeyState(VK_CONTROL) < 0)
				{
					int dx = x - listv.v[choose]->x;
					int dy = y - listv.v[choose]->y;
					for (int i = 0; i < listv.num; ++i)
					{
						listv.v[i]->x += dx;
						listv.v[i]->y += dy;
						if (!isInLimitZone(listv.v[i]->x, listv.v[i]->y))
						{
							for (int j = i; j >= 0; --j)
							{
								listv.v[j]->x -= dx;
								listv.v[j]->y -= dy;
							}
							break;
						}
					}
				} else listv.v[choose]->setCoordinate(x, y);
				setactivepage(1 - getactivepage());
				initScreen();
				dibujarZonaLimites();
				drawAllEdges();
				listv.showAll();
				menuButton[MOVEVE_MENU].showChoseButton();
				showButtonIcon(menuButton, MOVEVE_MENU);
				setvisualpage(getactivepage());
			}
			delay(DELAY_VALUE);
		}
		listv.v[choose]->show(VERTEX_COLOR);
		setvisualpage(getactivepage());
	}
}
void cleanGraph()
{
	if (isEmptyGraph()) return;
	if (MessageBox(hwnd, "ERROR", "ERROR",
		MB_APPLMODAL| MB_ICONQUESTION | MB_YESNO) == IDYES)
	{
		listv.clear();
		setMatrixTo(adjaGraph, NO_EDGE_VALUE);
		refrescarGrafica(CLEAN_GRAPH_MENU);
		isSaved = 1;
	}
}
void help()
{

}
int findButton(int x, int y)
{
	for (int i = 0; i < NUM_OF_MENU; ++i)
		if (menuButton[i].isButtonClick(x, y))
			return i;
	return -1;
}
void backToMenu()
{
	setTextPrintStyle(TEXT_COLOR);
	printTextWlb("");
	if (ismouseclick(WM_LBUTTONDOWN)) clearmouseclick(WM_LBUTTONDOWN);
	fflush(stdin);
	while (1)
	{
		if (kbhit()) break;
		if (ismouseclick(WM_LBUTTONDOWN)) break;
		delay(DELAY_VALUE);
	}
	if (ismouseclick(WM_LBUTTONDOWN)) clearmouseclick(WM_LBUTTONDOWN);
	fflush(stdin);
}
void switchMenuItem(int chose)
{
	switch (chose)
	{

		case ADD_VERTEX_MENU:	 	return agregarVertice();
		case ADD_EDGE_MENU: 		return addEdges();
		case RENAME_VERTEX_MENU: 	return renameVertex();
		case DELETEVE_MENU: 		return deleteVertex();
		case MOVEVE_MENU: 			return moveVertex();
		default: return;
	}
}
void refrescarPantalla()
{
	setactivepage(1 - getactivepage());
	initScreen();
	drawAllEdges();
	listv.showAll(VERTEX_COLOR);
	setvisualpage(getactivepage());
}
void refrescarGrafica(int mPos)
{
	setactivepage(1 - getactivepage());
	dibujarZonaTrabajo();
	dibujarZonaDeTexto();
	showAllButtons();
	drawAllEdges();
	listv.showAll();
	menuButton[mPos].showChoseButton();
	showButtonIcon(menuButton, mPos);
	setvisualpage(getactivepage());
}
inline void showChoseButton(int pos)
{
	if (pos >= ADD_VERTEX_MENU) refrescarPantalla();
	menuButton[pos].showChoseButton();
	showButtonIcon(menuButton, pos);
}
inline void showHightLightButton(int pos)
{
	menuButton[pos].showHightLightButton();
	if (pos >= ADD_VERTEX_MENU) menuButton[pos].showButtonHint();
	showButtonIcon(menuButton, pos);
}
inline void showNormalButton(int pos)
{
	if (pos >= ADD_VERTEX_MENU) refrescarPantalla();
	menuButton[pos].showNormalButton();
	showButtonIcon(menuButton, pos);
}
inline void update(int &oldPos, int &newPos, int x, int y)
{
	newPos = findButton(x, y);
	if (newPos != oldPos)
	{
		if (oldPos != -1) showNormalButton(oldPos);
		if (newPos != -1) showHightLightButton(newPos);
		oldPos = newPos;
	}
}
void menu()
{
	int x, y;
	int newPos(-1), oldPos(-1);
	while (1)
	{
		if (ismouseclick(WM_MOUSEMOVE))
		{
			getmouseclick(WM_MOUSEMOVE, x, y);
			update(oldPos, newPos, x, y);
		}
		if (ismouseclick(WM_LBUTTONDOWN))
		{
			clearmouseclick(WM_LBUTTONDOWN);
			if (newPos != -1)
			{
				showChoseButton(newPos);
				switchMenuItem(newPos);
			}
			oldPos = -1;
			refrescarPantalla();
			update(oldPos, newPos, mousex(), mousey());
		}
		delay(DELAY_VALUE);
	}
}
