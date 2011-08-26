#include <stdlib.h>

#include "include/room.h"

room_t *mkroom(int width, int height) {
	room_t *proom = malloc(sizeof(room_t));
	proom->width = width;
	proom->height = height;

	return proom;
};

