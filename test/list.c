#include <assert.h>
#include <stdlib.h>


#include "include/list.h"

#define VAL(X) *((int*)(X))

int main() {
	int iA[] = {0, 1, 2, 3, 4, 5, 6};

	list_t * list = list_create(iA);

	assert(list != NULL);
	assert(list->next == NULL);
	assert(list->value != NULL);
	assert( VAL(list->value) == 0);

	int i;
	for(i = 1; i<7; i++)
		list = list_append(list, &iA[i]);
	
	for(i = 0; i<7; i++) {
		assert(VAL(list_goto(list,i)->value) == i);
	}

	assert(list_goto(list, 100) == NULL);

	list = list_remove(list, 0);
	for(i = 0; i<6; i++) {
		assert(VAL(list_goto(list,i)->value) == (i+1));
	}

	list_destroy(list);
	list = list_create(iA);
	for(i = 1; i<7; i++)
		list = list_prepend(list, &iA[i]);
	
	for(i = 0; i<7; i++) {
		assert(VAL(list_goto(list,i)->value) == 6-i);
	}

	list = list_remove(list, 6);

	for(i = 0; i<6; i++) {
		assert(VAL(list_goto(list,i)->value) == 7-(i+1));
	}

return 0;
}
