#pragma once
#include <windows.h>
#include <windowsx.h>
#include "graphics.h"
#define COLOR(r,g,b) (0x04000000 | RGB(r,g,b))

enum colorPrincipal
{
	COLOR_FONDO	= LIGHTGRAY,
	wZONE_COLOR			= COLOR(128,128,128),
	COLOR_LINEA			= COLOR(128,0,0),
	DOT_COLOR			= BLACK,
	LIMIT_COLOR			= GREEN
};
enum buttonColors
{
	BUTTON_COLOR				= COLOR(225, 225, 225),
	BUTTON_BORDER				= COLOR(173, 173, 173),
	BUTTON_COLOR_HIGHTLIGHT		= COLOR(228, 251, 255),
	BUTTON_BORDER_HIGHTLIGHT	= COLOR(0, 120, 215),
	BUTTON_COLOR_CHOSE			= COLOR(0,175,255),
	BUTTON_BORDER_CHOSE			= COLOR(0,0,128),
	BUTTON_HINT					= COLOR(255, 255, 225)
};
enum moreColor
{
	C_LIME = COLOR(210, 245, 60),
	C_GREEN = COLOR(60, 180, 75),
	C_YELLOW = COLOR(255, 225, 25),
	C_OLIVE = COLOR(128, 128, 0),
	C_BLUE = COLOR(0, 130, 200),
	C_ORANGE = COLOR(245, 130, 48),
	C_PURPLE = COLOR(145, 30, 180),
	C_CYAN = COLOR(70, 240, 240),
	C_MAGENTA = COLOR(240, 50, 230),
	C_RED = COLOR(230, 25, 75),
	C_PINK = COLOR(250, 190, 190),
	C_TEAL = COLOR(0, 128, 128),
	C_LAVENDER = COLOR(230, 190, 255),
	C_BROWN = COLOR(170, 110, 40),
	C_BEIGE = COLOR(255, 250, 200),
	C_MAROON = COLOR(128, 0, 0),
	C_MINT = COLOR(170, 255, 195),
	C_NAVY = COLOR(0, 0, 128),
	C_CORAL = COLOR(255, 215, 180),

};
enum vertexColors
{
	VERTEX_COLOR 			= COLOR(0,215,0),
	VERTEX_BORDER 			= BLACK,
	VERTEX_CHOOSING_COLOR 	= COLOR(0,0,255),
	VERTEX_CHOSE_COLOR 		= COLOR(128,0,128),
	VERTEX_DELETE_COLOR 	= COLOR(231,18,20),
	VERTEX_VISTED_COLOR 	= COLOR(0, 128, 128),
	VERTEX_QUEUE_COLOR		= COLOR(128, 128, 0),
	VERTEX_ACTIVE_COLOR		= RED
};
static int const VERTEX_MORE_COLOR[] = {BLACK,
										C_LIME, C_GREEN, C_OLIVE,
										C_BLUE, C_ORANGE, C_PURPLE,
										C_CYAN, C_MAGENTA, C_RED,
										C_PINK, C_TEAL, C_LAVENDER,
										C_BROWN, C_BEIGE, C_MAROON,
										C_MINT, C_NAVY, C_CORAL,
										C_YELLOW,
										BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, LIGHTGRAY, DARKGRAY,
              							LIGHTBLUE, LIGHTGREEN, LIGHTCYAN, LIGHTRED, LIGHTMAGENTA, YELLOW
										};
enum edgeColors
{
	EDGE_COLOR 				= WHITE,
	EDGE_VISTED_COLOR 		= COLOR(204, 0, 0),
	EDGE_HIGHTLIGHT_COLOR 	= COLOR(215,0,0)
};
enum textColors
{
	TEXT_COLOR = BLACK,
	TEXT_HIGHTLIGHT_COLOR = BLUE
};
