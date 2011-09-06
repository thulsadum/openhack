#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "include/ui.h"
#include "include/player.h"

int ui_isrunning;

void ui_init() {
    initscr();

	noecho();
	cbreak();

#ifdef CFG_COLORS
	// yeah, we use colors :D
    if(has_colors())start_color();
	else {
		addstr("Termninal does not support colors!");
		getch();
		clear();
	}
#endif

	int mapw = (int)((float)COLS/80*60);
	int maph = (int)((float)LINES/25*20);
	int sidew = COLS-mapw;
	int sideh = maph;
	int msgw = COLS;
	int msgh = LINES - maph - 2;
	int statusw = COLS;
	int statush = 2;

	ui_win_map = newwin(maph, mapw, 0, 0);
	ui_win_side = newwin(sideh, sidew, 0, mapw);
	ui_win_status = newwin(statush, statusw, LINES-2, 0);
	ui_win_messages = newwin(msgh, msgw, maph, 0);

	keypad(ui_win_map, TRUE);
}

void ui_suspend() {
	delwin(ui_win_map);
	delwin(ui_win_side);
	delwin(ui_win_status);
	delwin(ui_win_messages);
	echo();
	nocbreak();
	clear();
	refresh();
    endwin();
}

int ui_wprintf(WINDOW* win, const char *fmt, ...) {
	va_list fmtargs;
	char buffer[COLS*LINES];

	va_start(fmtargs, fmt);
	int ret = vsnprintf(buffer, sizeof(buffer)-1, fmt, fmtargs);	
	va_end(fmtargs);

	waddstr(win, buffer);
	return ret;
} 

void ui_print_map(const map_t *map) {
	int x,y;

	for(x=0; x < map->width; x++)
		for(y=0; y < map->height; y++)
			mvwaddch(ui_win_map, y, x, GETTILE(map,x,y)->character);
}

win_size_t *ui_win_dim(WINDOW* win) {
	win_size_t *dim = malloc(sizeof(win_size_t));

	dim->width = win->_maxx - win->_begx;
	if(dim->width < 0) dim->width = -dim->width;

	dim->height = win->_maxy - win->_begy;
	if(dim->height < 0) dim->height = -dim->height;
	
	dim->x = win->_begx;
	dim->y = win->_begy;

	return dim;
}

void ui_loop() {
	int key;
	while(ui_isrunning) {
		ui_print_map(map_current);

		ui_print_mob(player);

		refresh();
		wrefresh(ui_win_map);
		wrefresh(ui_win_side);
		wrefresh(ui_win_status);
		wrefresh(ui_win_messages);

		key = wgetch(ui_win_map);
		ui_player_interaction(key);
	}
}

void ui_player_interaction(int key) {
	switch(key){
		case 'q':
			ui_quit();
			break;
		case KEY_LEFT:
		case 'h':
			player_move(-1, 0);
			break;
		case KEY_RIGHT:
		case 'l':
			player_move(1, 0);
			break;
		case KEY_UP:
		case 'k':
			player_move(0, -1);
			break;
		case KEY_DOWN:
		case 'j':
			player_move(0, 1);
			break;
	}
}

void ui_quit() {
	ui_isrunning = 0;
}

void ui_print_mob(mob_t* mob) {
	mvwaddch(ui_win_map, mob->y, mob->x, mob->character);
}

