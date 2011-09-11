#include "include/object.h"

void obj_door_closed_use(mob_t* who, object_t* what);
void obj_door_open_use(mob_t* who, object_t* what);

const object_t objects[] = (object_t[]) { 
	{ .properties = 0, .character = ' ', .use = NULL, .combine = NULL },
	{ .properties = 0, .character = '%', .use = NULL, .combine = NULL },
	{ .properties = 0, .character = '+', .use = &obj_door_closed_use, .combine = NULL },
	{ .properties = 0, .character = '|', .use = &obj_door_open_use, .combine = NULL },
	{ .properties = 0, .character = '-', .use = &obj_door_open_use, .combine = NULL },

};

void obj_door_closed_use(mob_t* who, object_t* what) {
	///< @todo check whether the door is in a horizontal or vertical wall
	*what = objects[OBJ_DOOR_OPEN_H];
}

void obj_door_open_use(mob_t* who, object_t* what) {
	*what = objects[OBJ_DOOR_CLOSED];
}

