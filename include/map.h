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
enum map_type_st {
	MT_DUNGEON, ///< map is a dungeon
	MT_OUTDOOR, ///< map is outdoor
	MT_STATIC, ///< map is a static map
};

/**
 * struct describing a tile
 */
struct tile_st {
	unsigned int properties; ///< bitmask describing the properties of the map_tile
	char character; ///< character rendered on the map
};

typedef enum map_type_st map_type_t; ///< type for map types
typedef struct tile_st tile_t; ///< type for tiles
typedef struct map_st map_t; ///< type for maps

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

#define OFFSET(map, x, y) ((map)->height * (x) + (y))
#define GETTILE(map, x, y) ((map)->tiles[OFFSET(map,x,y)])

extern const tile_t* map_tile_null;
extern const tile_t* map_tile_floor;
extern const tile_t* map_tile_hall;
extern const tile_t* map_tile_wall_n;
extern const tile_t* map_tile_wall_ne;
extern const tile_t* map_tile_wall_e;
extern const tile_t* map_tile_wall_se;
extern const tile_t* map_tile_wall_s;
extern const tile_t* map_tile_wall_sw;
extern const tile_t* map_tile_wall_w;
extern const tile_t* map_tile_wall_nw;

extern map_t* map_current;

/**
 * structure describing a map
 */
struct map_st {
	map_type_t type; ///< type of the map
	int width; ///< width of the map
	int height; ///< height of the map
	tile_t **tiles;  ///< tiles of the map array of size width x height
};

/**
 * fills a map with a given tile
 * @param pmap the map to fill
 * @param ptile the tile which will fill the map
 */
void fill_map(map_t *pmap, tile_t *ptile);

void create_testmap(map_t *pmap);

/**
 * initializes a map
 * @param width width of the map
 * @param height height of the map
 * @return map_t* pointer to the created map structure
 */
map_t* mkmap(int width, int height);

#endif
