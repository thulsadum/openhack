#include <assert.h>

#include "test.h"

#include "include/deque.h"

#define VAL(X) *((int*)X)

int main() {
	int iA[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	int i;

	dlog("creating deque...\n");
	deque_t *deque = deque_create();

	assert(deque != NULL);

	dlog("filling deque...\n");
	for(i=0; i<5; i++)
		deque = deque_push_front(deque, &iA[i]);
	for(; i<10; i++)
		deque = deque_push_back(deque, &iA[i]);
	
	assert(deque != NULL);
	dlog("front: %d, back: %d\n", VAL(deque_front(deque)->value),
		VAL(deque_back(deque)->value));
	assert(VAL(deque_front(deque)->value) == 4);
	assert(VAL(deque_back(deque)->value) == 9);

	dlog("poping deque's front...\n");
	for(i=4; i>=0; i--)
		assert(VAL(deque_pop_front(deque)) == i);
	for(i=5; i<10; i++)
		assert(VAL(deque_pop_front(deque)) == i);

	dlog("filling deque again...\n");
	for(i=0; i<10; i++)
		deque_push_front(deque, iA + i);
	dlog("poping deque's back...\n");
	for(i=0; i<10; i++)
		assert(VAL(deque_pop_back(deque)) == i);

	assert(deque_empty(deque));

	return 0;
}

