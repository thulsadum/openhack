#ifndef PLAYER_H
#define PLAYER_H

#include "mob.h"

extern mob_t* player;

#define player_move(DX, DY) mob_move(player, DX, DY)
#endif
