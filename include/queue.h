#ifndef QUEUE_H 
#define QUEUE_H

/**
 * @author Sebastian Claus
 * @date 2011/09/12
 * @brief implementation of a stack
 */

#include "stack.h"

typedef list_t queue_t; ///< queues are lists obviously.

/**
 * pushes something onto the queue
 * @param queue pointer to the queue
 * @param item the item to push
 * @return the queue on success or NULL on failure
 */
//queue_t *queue_push(queue_t *queue, void* item);
#define queue_enqueue(STACK, ITEM) list_insert_after(STACK, (STACK)->last, ITEM)

/**
 * pops the top element from queue
 * @param queue to pop from
 * @return the item poped or NULL if queue was empty
 */
//void *queue_dequeue(queue_t *queue);
#define queue_dequeue stack_pop

/**
 * gives the top element of the queue
 * @param queue pointer to the queue
 * @return pointer to the top element or NULL if queue is empty
 */
//void* queue_front(queue_t *queue);
#define queue_front stack_top

// some aliases
#define queue_create list_create
#define queue_destroy list_destroy
#define queue_empty list_empty

#endif

