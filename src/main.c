#include <stdio.h>
#include "include/random.h"
#include "include/ui.h"
int main(int argc, char** argv)
{
    //do some initialisations
    random_init();
    ui_init();

	map_current = mkmap(80, 35);
	create_testmap(map_current);

	ui_isrunning = 1;
	ui_loop();


    ui_suspend();
    printf(":)\n");
    return 0;
}
