#ifndef STACK_H
#define STACK_H

/**
 * @file stack.h
 * @author Sebastian Claus
 * @date 2011/09/12
 * @brief implementation of a stack
 */

#include "list.h"

typedef list_t stack_t; ///< stacks are lists obviously.

/**
 * pushes something onto the stack
 * @param stack pointer to the stack
 * @param item the item to push
 * @return the stack on success or NULL on failure
 */
//stack_t *stack_push(stack_t *stack, void* item);
#define stack_push(STACK, ITEM) list_insert_before(STACK, (STACK)->first, ITEM)

/**
 * pops the top element from stack
 * @param stack to pop from
 * @return the item poped or NULL if stack was empty
 */
void *stack_pop(stack_t *stack);

/**
 * gives the top element of the stack
 * @param stack pointer to the stack
 * @return pointer to the top element or NULL if stack is empty
 */
void* stack_top(stack_t *stack);

// some aliases
#define stack_create list_create
#define stack_destroy list_destroy
#define stack_empty list_empty

#endif

