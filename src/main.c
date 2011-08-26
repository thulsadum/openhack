#include <stdio.h>
#include "include/random.h"
#include "include/ui.h"
int main(int argc, char** argv)
{
    //do some initialisations
    random_init();
    ui_init();

	waddstr(ui_win_map, "map");
	waddstr(ui_win_side, "side");
	waddstr(ui_win_status, "status");
	waddstr(ui_win_messages, "messages");
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
