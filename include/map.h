#ifndef MAP_H
#define MAP_H

#include "room.h"

enum map_type_t {
	MT_DUNGEON,
	MT_OUTDOOR,
	MT_STATIC,
};


struct tile_t {
	unsigned int properties;
	const char* character;
};

tile_t[] map_tiles;

#define TILE_FLOOR '.'
#define TILE_PATH '#'
#define TILE_WALL_N '_'
#define TILE_WALL_NE '.'
#define TILE_WALL_E '|'
#define TILE_WALL_SE '\''
#define TILE_WALL_S '-'
#define TILE_WALL_SW '`'
#define TILE_WALL_W '|'
#define TILE_WALL_NW '.'

#define TILE_PROP_NORMAL 0x0
#define TILE_PROP_STICKY 0x1
#define TILE_PROP_SLIPPY 0x2
#define TILE_PROP_DUSTY 0x4
#define TILE_PROP_FLUID 0x8
#define TILE_PROP_FIRE 0x10
#define TILE_PROP_COLD 0x20
#define TILE_PROP_SHOCK 0x40
#define TILE_PROP_FLOATINGFLUID 0x80
#define TILE_PROP_UNPASSABLE 0x100


struct map_t {
	map_type_t map_type;
	int width;
	int height;
	tile_t[][] tiles; 
	size_t rooms_len;
	room_t[] rooms;
};
#endif
