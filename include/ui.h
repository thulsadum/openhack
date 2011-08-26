#ifndef UI_H
#define UI_H

#include <curses.h>

#include "config.h"

/**
 * @author Sebastian Claus
 * @date 2011-08-25
 * Header file specifying user interface (UI) functions
 */

WINDOW *ui_win_map, *ui_win_side, *ui_win_status, *ui_win_messages;

/**
 * initialize the user interface (ui)
 */
void ui_init();

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

// a simple wrapper macro for printing messages to default window
// (ui_win_messages)
#define ui_printf(FORMAT, ...) ui_wprintf(ui_win_messages, FORMAT, __VA_ARGS__)

#endif
