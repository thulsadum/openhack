#include <stdlib.h>

#include "include/list.h"

list_t *list_create() {
	list_t *list = malloc(sizeof(list_t));
	
	list->first = NULL;
	list->last = NULL;

	return list;
}

void list_destroy(list_t *list) {
	if(list == NULL) return;
	while((list = list_remove(list, 0)) != NULL && !list_empty(list))
		;
}

node_t *list_goto(list_t* list, int n) {
	if(list == NULL) return NULL;

	node_t *node = list->first;

	for(;n>0 && node!= NULL; n--)
		node = node->next;
	for(;n<0 && node!= NULL; n++)
		node = node->prev;
	return node;
}

list_t *list_remove(list_t *list, int n) {
	if(list_empty(list)) return list;

	node_t *node = list_goto(list, n);
	if(node == NULL) return NULL;
	
	// prev list next
	// prev next

	if(node->next != NULL)
		node->next->prev = node->prev;
	else
		list->last = node->prev;

	if(node->prev != NULL)
		node->prev->next = node->next;
	else
		list->first = node->next;

	free(node);

	return list;
}

list_t *list_insert_before(list_t *list, node_t *node, void * value) {
	if(list == NULL) return NULL;
	if(!list_empty(list) && node == NULL) return NULL;
	if(list_empty(list) && node != NULL) return NULL;

	node_t *new = malloc(sizeof(node_t));
	new->value = value;

	if(list_empty(list) ){
		new->prev = NULL;
		new->next = NULL;
		list->first = new;
		list->last = new;
	}else{
		// prev list next
		// prev new list next
		new -> next = node;
		new -> prev = node->prev;

		if(node->prev != NULL) node->prev->next = new;
		else list-> first = new;

		node->prev = new;

	}
	return list;
}

list_t *list_insert_after(list_t *list, node_t *node, void * value) {
	if(list == NULL) return NULL;
	if(!list_empty(list) && node == NULL) return NULL;
	if(list_empty(list) && node != NULL) return NULL;

	node_t *new = malloc(sizeof(node_t));
	new->value = value;

	if(list_empty(list) ){
		new->prev = NULL;
		new->next = NULL;
		list->first = new;
		list->last = new;
	}else{
		// prev list next
		// prev list new next
		new -> prev = node;
		new -> next = node->next;

		if(node->next != NULL) node->next->prev = new;
		else list-> last = new;

		node->next = new;
	}
	return list;
}

