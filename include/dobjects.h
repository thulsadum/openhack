#ifndef DOBJECTS_H
#define DOBJECTS_H

#include "types.h"

/**
 * @author Sebastian Claus
 * @date 2011/09/08
 * @brief defining dungeon objects
 */

/**
 * structure for describing a dungeon object
 * (e.g. doors, traps, ...)
 */
struct dobject_st {
	prop_t properties;
	char character;
};

#define DOBJ_PROP_UNPASSABLE 0x1

#endif
