#include <stdlib.h>

#include "include/list.h"

#ifdef CFG_REWIND_LISTS
#undef list_insert
#undef list_add
#undef list_remove
#endif

list_t *list_create(void *item) {
	list_t *list = malloc(sizeof(list_t));

	list->value = item;
	list->prev = NULL;
	list->next = NULL;
	return list;
}

void list_destroy(list_t *list) {
	if(list == NULL) return;
	while((list = list_remove(list, 0)) != NULL)
		;
}

list_t *list_goto(list_t* list, int n) {
	for(;n>0 && list!= NULL; n--)
		list = list->next;
	for(;n<0 && list!= NULL; n++)
		list = list->prev;
	return list;
}

list_t *list_insert(list_t *list, int n, void *item) {
	list = list_goto(list, n);
	if(list == NULL) return NULL;

	list_t *tmp = malloc(sizeof(list_t));
	tmp->value = item;
	
	list->prev = tmp;
	tmp->next = list;

	return list;
}

list_t *list_add(list_t *list, int n, void *item) {
	list = list_goto(list, n);
	if(list == NULL) return NULL;

	list_t *tmp = malloc(sizeof(list_t));
	tmp->value = item;
	
	// ... prev list next
	// ... prev list tmp next
	
	tmp->prev = list;
	tmp->next = list->next;

	if(list->next != NULL) list->next->prev = tmp;
	list->next = tmp;

	return tmp;
}

list_t *list_remove(list_t *list, int n) {
	list = list_goto(list, n);
	if(list == NULL) return NULL;
	list_t *tmp = list;
	
	// prev list next
	// prev next

	if(list->next != NULL)
		list->next->prev = list->prev;
	if(list->prev != NULL)
		list->prev->next = list->next;
	
	if(list->next != NULL)
		list = list->next;
	else
		list = list->prev;

	free(tmp);

	return list;
}

list_t *list_first(list_t *list) {
	if(list == NULL) return NULL;

	while(list->prev != NULL)
		list = list->prev;
	return list;
}

list_t *list_last(list_t *list) {
	if(list == NULL) return NULL;

	while(list->next != NULL)
		list = list->next;
	return list;
}
