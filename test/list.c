#include <assert.h>
#include <stdlib.h>

#include "test.h"

#include "include/list.h"

#define VAL(X) *((int*)(X))

int main() {
	int iA[] = {0, 1, 2, 3, 4, 5, 6};

	list_t * list = list_create();

	dlog("Stage 0\n");
	assert(list != NULL);
	assert(list->first == NULL);
	assert(list->last == NULL);

	dlog("Stage 1\n");
	dlog("Stage 1.1\n");

	int i;
	list = list_add(list, 0, iA);
	assert(list != NULL);
	for(i = 1; i<7; i++)
		list = list_add(list, i-1, &iA[i]);
	assert(list != NULL);

	dlog("Stage 1.2\n");
	
	for(i = 0; i<7; i++) {
		dlog("i: %d, addr: %x\n", i, list_goto(list, i)); //,VAL(list_goto(list, i)->value));
		assert(list_goto(list, i) != NULL);
		dlog(" val: %d\n", VAL(list_goto(list, i)->value));
		assert(VAL(list_goto(list,i)->value) == iA[i]);
	}

	assert(list->first->value == iA);
	assert(list->last->value == iA+6);

	assert(list_goto(list, 100) == NULL);

	dlog("Stage 2\n");
	list = list_remove(list, 0);
	assert(list != NULL);
	dlog("removed first element\n");
	for(i = 0; i<6; i++) {
		assert(VAL(list_goto(list,i)->value) == (i+1));
	}

	list_destroy(list);

	dlog("Stage 3\n");
	list = list_create();
	for(i = 0; i<7; i++)
		list_insert(list, 0, &iA[i]);
	
	for(i = 0; i<7; i++) {
		assert(VAL(list_goto(list,i)->value) == 6-i);
	}

	dlog("Stage 4\n");
	list = list_remove(list, 6);

	for(i = 0; i<6; i++) {
		assert(VAL(list_goto(list,i)->value) == 7-(i+1));
	}

return 0;
}
