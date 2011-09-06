#include <stdio.h>
#include "include/random.h"
#include "include/ui.h"
int main(int argc, char** argv)
{
    //do some initialisations
    random_init();
    ui_init();

	win_size_t *dim_map = ui_win_dim(ui_win_map), 
		*dim_side = ui_win_dim(ui_win_side), 
		*dim_status = ui_win_dim(ui_win_status), 
		*dim_messages = ui_win_dim(ui_win_messages);

	
	ui_wprintf(ui_win_side, "side\n%d,%d", dim_side->width, dim_side->height);
	ui_wprintf(ui_win_status, "status\n%d,%d", dim_status->width,
		dim_status->height);
	ui_wprintf(ui_win_messages, "messages\n%d,%d", dim_messages->width,
		dim_messages->height);

	map_current = mkmap(80, 35);
	create_testmap(map_current);

	ui_isrunning = 1;
	ui_loop();


    ui_suspend();
    printf(":)\n");
    return 0;
}
