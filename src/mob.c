#include "include/mob.h"
#include "include/map.h"
#include "include/ui.h"
#include "include/player.h"

void mob_move(mob_t* mob, int dx, int dy) {
	int x = mob->x + dx;
	int y = mob->y + dy;

	if(x < 0 || y < 0 || x >= map_current->width || y >= map_current->height) {
		if(mob == player)
			ui_print( "Crossing strangers tides?");
		return;
	}
	if(GETTILE(map_current, x, y)->properties & TILE_PROP_UNPASSABLE) {
		if(mob == player)
			ui_print("Hmpf, noway.");
		return;
	}

	mob->x = x;
	mob->y = y;

}
