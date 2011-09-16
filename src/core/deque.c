#include "include/deque.h"

void *deque_pop_front(deque_t *deque) {
	void *element = deque_front(deque)->value;
	list_remove_node(deque, deque_front(deque));
	return element;
}

void *deque_pop_back(deque_t *deque) {
	void *element = deque_back(deque)->value;
	list_remove_node(deque, deque_back(deque));
	return element;
}
