#include <stdlib.h>
#include <string.h>

#include "include/map.h"

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


void fill_map(map_t *pmap, tile_t *ptile) {
	if(pmap == NULL) return;
	int i;
	for(i = 0; i<(pmap->width*pmap->height); i++)
		pmap->tiles[i] = ptile;
}

map_t *mkmap(int width, int height){
	map_t *pmap = malloc(sizeof(map_t));
	if(pmap == NULL) return NULL;
	(pmap)->width = width;
	(pmap)->height = height;
	(pmap)->tiles = malloc(width * height * sizeof(tile_t*));
	if(pmap->tiles == NULL){
		free(pmap);
		return NULL;
	}
	return pmap;
}

void create_testmap(map_t* pmap) {
	/// @todo there is a bug here
	/// @bug does not make correct maps if map is not a sqaure...
	fill_map(pmap, &TILE(hall));
	int i;
	for(i=0; i < pmap->width; i++)
		GETTILE(pmap, i, pmap->height/2) = &TILE(wall_n);
	for(i=0; i < pmap->height; i++)
		GETTILE(pmap, pmap->width/2, i) = &TILE(wall_e);
}
