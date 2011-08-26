#include <stdlib.h>

#define MAP_IMPL

#include "include/map.h"

map_t *mktestMap(){
	map_t *map = malloc(sizeof(map_t));
	map->type = MT_STATIC;
	map->width = 10;
	map->height = 10;
	map->tiles = malloc(map->width*map->height*sizeof(tile_t));
	int x,y;
	for(x=0; x<map->width; x++)
		for(y=0; y<map->height; y++)
			(map->tiles)[x][y] = TILE(floor);
	return map;
}


