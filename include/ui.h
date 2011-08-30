#ifndef UI_H
#define UI_H

#include <curses.h>

#include "config.h"

#include "map.h"

/**
 * @file ui.h
 * @author Sebastian Claus
 * @date 2011-08-25
 * @brief specifying user interface (UI) functions
 */

WINDOW *ui_win_map, *ui_win_side, *ui_win_status, *ui_win_messages;

int ui_isrunning;

typedef struct win_size_st win_size_t; ///< windows size type

/**
 * structure describing the window dimensions
 */
struct win_size_st {
	NCURSES_SIZE_T width; ///< width of the window region
	NCURSES_SIZE_T height; ///< height of the window region
	NCURSES_SIZE_T x; ///< x coordinate of the upper-left corner
	NCURSES_SIZE_T y; ///< y coordinate of the upper-left corner
};

win_size_t *ui_win_dim(WINDOW* win);

/**
 * initialize the user interface (ui)
 */
void ui_init();

/**
 * the game loop
 */
void ui_loop();

/**
 * suspends the ui
 */
void ui_suspend();

/**
 * waits for an key press
 * @return int pressed key
 */
//int ui_waitkey();

/**
 * a printf wrapper for printing strings to windows.
 * @param fmt const char * containing the format string
 * @param ... arguments for the format string
 * @return int number of characters written
 */
int ui_wprintf(WINDOW* win, const char * fmt, ...);

/**
 * prints a map onto the screen (in window ui_win_map)
 * @param map the map structure to be printed out
 */
void ui_print_map(const map_t* map);

// a simple wrapper macro for printing messages to default window
// (ui_win_messages)
#define ui_printf(FORMAT, ...) ui_wprintf(ui_win_messages, FORMAT, __VA_ARGS__)

#endif
