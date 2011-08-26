#include <stdio.h>
#include "include/random.h"
#include "include/ui.h"
int main(int argc, char** argv)
{
    //do some initialisations
    random_init();
    ui_init();

	ui_wprintf(ui_win_map, "map");
	ui_wprintf(ui_win_side, "side");
	ui_wprintf(ui_win_status, "status");
	ui_wprintf(ui_win_messages, "messages");

	ui_printf("LINES: %d, COLS: %d", LINES, COLS);

	refresh();
	wrefresh(ui_win_map);
	wrefresh(ui_win_side);
	wrefresh(ui_win_status);
	wrefresh(ui_win_messages);
	getch();

    ui_suspend();
    printf(":)\n");
    return 0;
}
