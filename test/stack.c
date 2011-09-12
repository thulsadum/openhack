#include <assert.h>

#include "test.h"
#include "include/stack.h"

#define VAL(X) *((int*) (X))

int main() {
	int iA[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

	dlog("creating stack...\n");
	stack_t *stack = stack_create();


	assert(stack != NULL);
	assert(stack_empty(stack));

	int i;

	dlog("filling stack...\n");
	for(i=0; i<10; i++)
		stack = stack_push(stack, iA+i);
	assert(stack != NULL);

	dlog("checking stack...\n");
	for(i=0; i<10; i++)
		assert(VAL(stack_pop(stack)) == i);

	return 0;
}

