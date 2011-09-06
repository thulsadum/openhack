#include "include/mob.h"

void mob_move(mob_t* mob, int dx, int dy) {
	mob->x += dx;
	mob->y += dy;
}
