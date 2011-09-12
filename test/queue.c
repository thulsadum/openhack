#include <assert.h>

#include "test.h"
#include "include/queue.h"

#define VAL(X) *((int*) (X))

int main() {
	int iA[] = {0,1,2,3,4,5,6,7,8,9};

	dlog("creating queue...\n");
	queue_t *queue = queue_create();


	assert(queue != NULL);
	assert(queue_empty(queue));

	int i;

	dlog("filling queue...\n");
	for(i=0; i<10; i++)
		queue = queue_enqueue(queue, iA+i);
	assert(queue != NULL);

	dlog("checking queue...\n");
	for(i=0; i<10; i++){
		assert(VAL(queue_dequeue(queue)) == i);
	}
	return 0;
}

