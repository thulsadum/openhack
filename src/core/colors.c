#include <curses.h>

#include "include/colors.h"

void colors_init() {
	start_color();


#ifdef CFG_BLACK
	init_color(COLOR_BLACK, CFG_BLACK);
#endif
#ifdef CFG_RED
	init_color(COLOR_RED, CFG_RED);
#endif
#ifdef CFG_GREEN
	init_color(COLOR_GREEN, CFG_GREEN);
#endif
#ifdef CFG_YELLOW
	init_color(COLOR_YELLOW, CFG_YELLOW);
#endif
#ifdef CFG_BLUE
	init_color(COLOR_BLUE, CFG_BLUE);
#endif
#ifdef CFG_MAGENTA
	init_color(COLOR_MAGENTA, CFG_MAGENTA);
#endif
#ifdef CFG_CYAN
	init_color(COLOR_CYAN, CFG_CYAN);
#endif
#ifdef CFG_WHITE
	init_color(COLOR_WHITE, CFG_WHITE);
#endif

// extra colors
#ifdef CFG_GRAY
	init_color(COLOR_GRAY, CFG_GRAY);
#else
	init_color(COLOR_GRAY, 500, 500, 500);
#endif

	use_default_colors();
	int col;

	assume_default_colors(COLOR_GRAY, -1);
	for(col = 0; col < 16; col++) {
		init_pair(col+1, col, -1);
	}
}
