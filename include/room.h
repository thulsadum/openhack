#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

/**
 * @file room.h
 * @author Sebastian Claus <anthrax2k4@freenet.de>
 * @date Fr 26 Aug 2011 16:31:44 CEST 
 * @brief defining room_t and some functions
 *
 */

/**
 * the room structure
 */
struct _room_t {
	int width; ///< the width of the room
	int height; ///< the height of the room
};


typedef struct _room_t room_t; ///< type for abbriative usage

/** create room structure with given dimension
 * @param width int width of the room
 * @param height int heigt of the room
 * @return pointer to the created room sructure
 */
room_t *mkroom(int width, int height);


#endif //ROOM_H_INCLUDED
