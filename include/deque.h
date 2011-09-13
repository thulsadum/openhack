#ifndef DEQUE_H_INCLUDED
#define DEQUE_H_INCLUDED

/**
 * @file deque.h
 * @author Sebastian Claus 
 * @date Mo 12 Sep 2011 12:06:40 CEST 
 * @brief implements a double-ended queue (deque)
 *
 */

#include "list.h"

typedef list_t deque_t; ///< a deque is a list. :)

/**
 * gets the front element of the deque
 */
#define deque_front(DEQUE) ((DEQUE)->first)

/**
 * gets the back element of the deque
 */
#define deque_back(DEQUE) ((DEQUE)->last)

/**
 * pushes an item to the back of the deque)
 */
#define deque_push_back(DEQUE, ITEM) \
	list_insert_after(DEQUE, deque_back(DEQUE), ITEM)

/**
 * pushes an item to the front of the deque
 */
#define deque_push_front(DEQUE, ITEM) \
	list_insert_before(DEQUE, deque_front(DEQUE), ITEM)

/**
 * pops an element from the front of the deque
 * @param deque pointer to the deque
 * @return the poped element
 */
void* deque_pop_front(deque_t *deque);

/**
 * pops an element from the back of the deque
 * @param deque pointer to the deque
 * @return the poped element
 */
void* deque_pop_back(deque_t *deque);

#define deque_create list_create
#define deque_destroy list_destroy
#define deque_empty list_empty


#endif //DEQUE_H_INCLUDED
