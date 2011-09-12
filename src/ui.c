#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "include/ui.h"
#include "include/player.h"
#include "include/queue.h"

int ui_isrunning;

static queue_t *msgQ;
static int msgPos = 0;
static int msgCount = 0;

void ui_init() {
    initscr();

	noecho();
	cbreak();

	msgQ = queue_create();

	ui_printf("ehlo to openhack. :)");

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

void ui_loop() {
	int key;
	while(ui_isrunning) {
		ui_print_map(map_current);

		ui_print_mob(player);

		ui_show_messages();

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

void ui_printf(const char *fmt, ...) {
	va_list fmtargs;
	char *buffer = malloc(sizeof(char)*COLS*LINES);

	va_start(fmtargs, fmt);
	int ret = vsnprintf(buffer, sizeof(buffer)-1, fmt, fmtargs);	
	va_end(fmtargs);

	if(ret >= sizeof(buffer-1)) ret = sizeof(buffer)-1;
	else buffer = realloc(buffer, ret); 

	if(buffer == NULL) return; // and so we send the message to the
								// write-only-memory
	addstr(buffer);
	queue_enqueue(msgQ, buffer);
	msgCount++;

	int maxy, maxx;

	getmaxyx(ui_win_messages, maxy, maxx);

	if(msgCount > maxy) msgPos++;
}

void ui_show_messages() {
	node_t *cur = list_goto(msgQ, msgPos);
	int i, maxy, maxx;

	char *msg;

	getmaxyx(ui_win_messages, maxy, maxx);

	werase(ui_win_messages);

	for(i=0; cur!=NULL && i < maxy; i++) {
		msg = cur->value;

		mvwaddstr(ui_win_messages, i, 0, msg);

		cur = cur->next;
	}

}
