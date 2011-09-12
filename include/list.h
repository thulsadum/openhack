#ifndef LIST_H
#define LIST_H

/**
 * @file list.h
 * @author Sebastian Claus
 * @date 2011/09/10
 * @brief defining an ADT list
 */

/**
 * type for lists
 */
typedef struct list_st list_t;
/**
 * type for nodes
 */
typedef struct node_st node_t;

/**
 * call back function for list_map
 * @param the current node of the map iteration
 */
typedef void (*list_map_fn_t)(node_t*);

/**
 * structure describing a list node
 */
struct node_st {
	void* value;
	node_t *next;
	node_t *prev;
};

/**
 * structure describing a list
 */
struct list_st {
//	node_t *head; ///< current list element
//	node_t *tail; ///< next list element

	node_t *first; ///< pointer to first list element
	node_t *last; ///< pointer to last list element
};


/**
 * applies a function to each list element
 * @param list pointer to the list
 * @param callback the function to call
 */
void list_map(list_t *list, list_map_fn_t callback);


/**
 * creates a new list
 * @param item pointer to the referenced object
 * #return the list
 */
list_t * list_create();

/**
 * destroys an entire list.
 * @param plist pointer to the list
 */
void list_destroy(list_t* plist);

/**
 * get n-th list element
 * @param plist pointer to the list to walk through
 * @param n index of desired element
 * @return list_t pointing to the found element. NULL otherwise
 */
node_t *list_goto(list_t *plist, int n);

/**
 * adds an item to the list (before position)
 * @param plist pointer to the list
 * @param n position to add the item (left of item)
 * @param item pointer to the item
 * @return manipulated list or NULL on failure
 */
//list_t *list_insert(list_t *plist, int n, void* item);
#define list_insert(LIST, N, ITEM) list_insert_before(LIST, list_goto(LIST, N), ITEM)

/**
 * adds an item to the list (after position)
 * @param plist pointer to the list
 * @param n position to add the item (right of item)
 * @param item pointer to the item
 * @return manipulated list or NULL on failure
 */
//list_t *list_add(list_t *plist, int n, void* item);
#define list_add(LIST, N, ITEM) list_insert_after(LIST, list_goto(LIST, N), ITEM)

/**
 * removes the n-th element from the list
 * @param plist pointer to the list
 * @param n index of element to remove
 * @return pointer to the updated list
 */
//list_t *list_remove(list_t *plist, int n);
#define list_remove(LIST, N) list_remove_node(LIST, list_goto(LIST, N))
/**
 * removes a node from the list
 * @param plist pointer to the list
 * @param node pointer to the node
 * @return the list or NULL on failure
 */
list_t *list_remove_node(list_t *plist, node_t* node);

/**
 * inserts an item before a node
 * @param plist pointer to list
 * @param node the node. @note: must be in list or will construct realy strange
 * lists.
 * @param pointer to stored object
 * @return the list or NULL on failure
 */
list_t *list_insert_before(list_t *plist, node_t *node, void* value);

/**
 * inserts an item after a node
 * @see list_insert_after for parameter description
 */
list_t *list_insert_after(list_t *plist, node_t *node, void* value);

/**
 * checks whether a list is empty or not/
 * @param LIST pointer to list, to check
 */
#define list_empty(LIST) (((LIST)->first == NULL) && ((LIST)->last == NULL))

/**
 * adds an item after the last element of a list
 * @param LIST pointer to the list
 * @param ITEM pointer to the item
 * @return @see list_add
 */
#define list_append(LIST, ITEM) list_add(*((LIST)->last), 0, ITEM)

/**
 * adds an item before the last element of a list
 * @param LIST pointer to the list
 * @param ITEM pointer to the item
 * @return @see list_insert
 */
#define list_prepend(LIST, ITEM) list_insert(*((LIST)->first), 0, ITEM)

#ifndef NULL
#define NULL 0
#endif

#endif
