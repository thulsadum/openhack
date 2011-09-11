#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include "status.h"
#include "mob.h"
#include "map.h"

/**
 * @file object.h
 * @author Sebastian Claus <anthrax2k4@freenet.de>
 * @date Di 30 Aug 2011 16:33:08 CEST 
 * @brief structures, macros and functions for object manipulation
 *
 */

typedef struct object_st object_t; ///< short hand for object_st structures for abbrivative usage

typedef void (*use_fn_t)(object_t*, mob_t*); ///< function pointer for usecallbacks
typedef void (*combine_fn_t)(object_t*, object_t*); ///< function pointer for combine callbacks

/**
 * strcuture describing objects
 */
struct object_st {
	unsigned int properties; ///< properties of the object
	char character; ///< character of the object when rendered on the map
	use_fn_t use; ///< callback if object is useable or NULL otherwise
	combine_fn_t combine; ///< callback if object is combineable or NULL otherwise
};

extern const object_t objects[]; ///< all avaible objects

int object_spawn(map_t* map, int x, int y);

// aliases for objects
#define OBJ_VOID 0x0
#define OBJ_APPLE 0x1
#define OBJ_DOOR_CLOSED 0x2
#define OBJ_DOOR_OPEN_H 0x3
#define OBJ_DOOR_OPEN_V 0x4

/**
 * initilizing the objects array
 * @return st_b_success on success, st_b_fail on failure
 */
//status_bool objects_init();

#ifndef NULL
#define NULL 0
#endif

#endif //OBJECT_H_INCLUDED
