#ifndef UI_H
#define UI_H

#include <curses.h>

#include "config.h"

#include "map.h"
#include "mob.h"

/**
 * @file ui.h
 * @author Sebastian Claus
 * @date 2011-08-25
 * @brief specifying user interface (UI) functions
 */

WINDOW *ui_win_map, *ui_win_side, *ui_win_status, *ui_win_messages;

extern int ui_isrunning;

typedef struct win_size_st win_size_t; ///< windows size type

/**
 * initialize the user interface (ui)
 */
void ui_init();

/**
 * the game loop
 */
void ui_loop();

/**
 * player interaction
 */
void ui_player_interaction();

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

/**
 * quit the game
 */
void ui_quit();

/**
 * renders a mob on the map.
 * @param mob reference to the mob, which will be rendered.
 */
void ui_print_mob(mob_t* mob);

/**
 * scrolls the message window
 * @param lines amount of lines to scroll
 */
void ui_scroll(int lines);

/**
 * enques a message to the message buffer
 * @param msg message to enqueue
 */
void ui_printf(const char* fmt, ...);

/**
 * prints messages from the message queue to the message window
 */
void ui_show_messages();

// a simple wrapper macro for printing messages to default window
// (ui_win_messages)
#define ui_print(MSG) ui_printf(MSG)

#endif
