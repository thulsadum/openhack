#include "include/stack.h"

// implemented by macro in header
//stack_t *stack_push(stack_t *stack, void* item) {
//	return list_insert_before(stack, stack->first, item);
//}

void* stack_top(stack_t *stack) {
	if(stack == NULL || stack_empty(stack)) return NULL;
	return stack->first->value;
}

void* stack_pop(stack_t* stack) {
	void* val = stack_top(stack);
	list_remove_node(stack, stack->first);
	return val;
}

