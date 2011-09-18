#ifndef COLORS_H
#define COLORS_H

/**
 * colors.h
 * @author Sebastian Claus
 * @date Sun 18 Sep 2011 11:50:56 PM CEST
 * @brief defines some constants for color usage
 */

#include "config.h"
#ifdef CFG_COLORS

#include <curses.h>

#define COLOR_GRAY 8

/**
 * initializes the colour pairs
 */
void colors_init();

#define IFCOL(...) __VA_ARGS__

typedef enum colors_e color_t; ///< typedef for colors

/**
 * color enumeration
 */
enum colors_e {
	COL_BLACK = 1,
	COL_RED,
	COL_GREEN,
	COL_YELLOW,
	COL_BLUE,
	COL_MAGENTA,
	COL_CYAN,
	COL_WHITE,
	COL_GRAY
};

#define COL_BLACK COL_BLACK
#define COL_RED COL_RED
#define COL_GREEN COL_GREEN
#define COL_YELLOW COL_YELLOW
#define COL_BLUE COL_BLUE
#define COL_MAGENTA COL_MAGENTA
#define COL_CYAN COL_CYAN
#define COL_WHITE COL_WHITE
#define COL_GRAY COL_GRAY

#define COL_PLAYER COL_WHITE

#else
#define IFCOL(...)

#endif
#endif // COLORS_H
