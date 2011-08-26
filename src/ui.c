#include <stdarg.h>
#include <stdio.h>
#include "include/ui.h"

void ui_init() {
    initscr();

	noecho();
	cbreak();

#ifdef CFG_COLORS
	// yeah, wie use colors :D
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

//	ui_win_map = subwin(stdscr, maph, mapw, 0, 0);
//	ui_win_side = subwin(stdscr, sideh, sidew, 0, mapw);
//	ui_win_status = subwin(stdscr, statush, statusw, LINES-2, 0);
//	ui_win_messages = subwin(stdscr, msgh, msgw, maph, 0);
	ui_win_map = newwin(maph, mapw, 0, 0);
	ui_win_side = newwin(sideh, sidew, 0, mapw);
	ui_win_status = newwin(statush, statusw, LINES-2, 0);
	ui_win_messages = newwin(msgh, msgw, maph, 0);
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
