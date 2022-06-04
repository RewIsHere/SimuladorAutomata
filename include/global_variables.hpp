#pragma once
#include "list_vertices.hpp"
#include "button.hpp"

ListVertices listv;
int xCursor = xCURSOR;
int yCursor = yCURSOR;
int delayRunTime = 500;
bool isSaved = 1;
int trace[MAX_VERTEX];
float adjaGraph[MAX_VERTEX][MAX_VERTEX];
HWND hwnd;

Button menuButton[] =	{ {15, 30, 115, 70, BUTTON_COLOR,  	""},
						  {120, 30, 220, 70, BUTTON_COLOR,	""},
						  {225, 30, 325, 70, BUTTON_COLOR,	""},
						  {15, 75, 115, 115, BUTTON_COLOR,	""},
						  {120, 75, 220, 115, BUTTON_COLOR,	""},
						  {225, 75, 325, 115, BUTTON_COLOR,	""},
						  {15, 120, 115, 160, BUTTON_COLOR,	""},
						  {120, 120, 220, 160, BUTTON_COLOR,""},
						  {225, 120, 325, 160, BUTTON_COLOR,""},
						  {15, 165, 115, 205, BUTTON_COLOR,	""},
						  {120, 165, 220, 205, BUTTON_COLOR,""},
						  {15, 245, 115, 285, BUTTON_COLOR,	""},
						  {120, 245, 220, 285, BUTTON_COLOR,""},
						  {225, 245, 325, 285, BUTTON_COLOR,""},
						  {357, 22, 417, 92, BUTTON_COLOR,	"Nodo"},
						  {357, 92, 417, 162, BUTTON_COLOR,	"Conector"},
						  {357, 162, 417, 232, BUTTON_COLOR,"Editar"},
						  {357, 232, 417, 302, BUTTON_COLOR,"Eliminar"},
						  {357, 302, 417, 372, BUTTON_COLOR,"Mover"}};

