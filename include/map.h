#ifndef MAP_H
#define MAP_H

#include <sys/types.h>

#include "room.h"

/**
 * @file map.h
 * @author Sebastian Claus
 * @date 2011-08-26
 * @brief map specification
 */

/**
 * enum specifying the type of the map
 */
enum _map_type_t {
	MT_DUNGEON, ///< map is a dungeon
	MT_OUTDOOR, ///< map is outdoor
	MT_STATIC, ///< map is a static map
};

/**
 * struct describing a tile
 */
struct _tile_t {
	unsigned int properties; ///< bitmask describing the properties of the map_tile
	char character; ///< character rendered on the map
};

typedef enum _map_type_t map_type_t;
typedef struct _tile_t tile_t;
typedef struct _map_t map_t;

#define TILE_PROP_NORMAL 0x0 ///< tile is normal w/o modification
#define TILE_PROP_STICKY 0x1 ///< tile is sticky => slows down
#define TILE_PROP_SLIPPY 0x2 ///< tile is slippy => may fall
#define TILE_PROP_DUSTY 0x4 ///< tile is dusty => may leave foot prints
#define TILE_PROP_FLUID 0x8 ///< tile is a fluid => must swim!
#define TILE_PROP_FIRE 0x10 ///< tile is on fir => causes fire damage
#define TILE_PROP_COLD 0x20 ///< tile is cold => causes cold damage
#define TILE_PROP_SHOCK 0x40 ///< tile is shocking => causes shock damage
#define TILE_PROP_FLOATING 0x80 ///< tile is floating => may turn neighbor tiles into this tile
#define TILE_PROP_UNPASSABLE 0x100 ///< tile is unpassable (e.g. walls)

#define TILE(T) map_tile_##T

#ifdef MAP_IMPL
const tile_t map_tile_floor = { TILE_PROP_NORMAL, '.' };
const tile_t map_tile_hall = { TILE_PROP_NORMAL, '#' };
const tile_t map_tile_wall_n = { TILE_PROP_UNPASSABLE, '-'};
const tile_t map_tile_wall_ne = { TILE_PROP_UNPASSABLE, '.'};
const tile_t map_tile_wall_e = { TILE_PROP_UNPASSABLE, '|'};
const tile_t map_tile_wall_se = { TILE_PROP_UNPASSABLE, '\''};
const tile_t map_tile_wall_s = { TILE_PROP_UNPASSABLE, '-'};
const tile_t map_tile_wall_sw = { TILE_PROP_UNPASSABLE, '\''};
const tile_t map_tile_wall_w = { TILE_PROP_UNPASSABLE, '|'};
const tile_t map_tile_wall_nw = { TILE_PROP_UNPASSABLE, '.'};
#endif

/**
 * structure describing a map
 */
struct _map_t {
	map_type_t type; ///< type of the map
	int width; ///< width of the map
	int height; ///< height of the map
	tile_t **tiles;  ///< tiles of the map array of size width x height
};

map_t *mktestMap();

#endif
