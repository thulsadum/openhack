#ifndef LIST_H
#define LIST_H

#include "../config.h"

/**
 * @author Sebastian Claus
 * @date 2011/09/10
 * @brief defining an ADT list
 */

/**
 * type for lists
 */
typedef struct list_st list_t;

/**
 * call back function for list_map
 * @param the current node of the map iteration
 */
typedef void (*list_map_fn_t)(list_t*);

/**
 * structure describing a list
 */
struct list_st {
	void *value; ///< reference to object
	list_t *next; ///< pointer to next list item
	list_t *prev; ///< pointer to previous list item
};


/**
 * applies a function to each list element
 * @param list pointer to the list
 * @param callback the function to call
 * @return the manipulated list
 * @todo implement!
 */
list_t *list_map(list_t *list, list_map_fn_t callback);


/**
 * creates a new list
 * @param item pointer to the referenced object
 * #return the list
 */
list_t * list_create(void* item);

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
list_t *list_goto(list_t *plist, int n);

/**
 * adds an item to the list (before position)
 * @param plist pointer to the list
 * @param n position to add the item (left of item)
 * @param item pointer to the item
 * @return manipulated list or NULL on failure
 */
list_t *list_insert(list_t *plist, int n, void* item);
/**
 * adds an item to the list (after position)
 * @param plist pointer to the list
 * @param n position to add the item (right of item)
 * @param item pointer to the item
 * @return manipulated list or NULL on failure
 */
list_t *list_add(list_t *plist, int n, void* item);

/**
 * goto last element of a list
 * @param pointer to the list
 * @return pointer to the fast forwarded list
 */
list_t *list_last(list_t* plist);

/**
 * goto first element of a list
 * @param pointer to the list
 * @return pointer to the rewinded list
 */
list_t *list_first(list_t* plist);

/**
 * removes the n-th element from the list
 * @param plist pointer to the list
 * @param n index of element to remove
 * @return pointer to the updated list
 */
list_t *list_remove(list_t *plist, int n);

#ifdef CFG_REWIND_LISTS
/**
 * wrap list_insert into list_first so the list is rewinded after insertion
 */
#define list_insert(LIST, POS, ITEM) list_first(list_insert(LIST, POS, ITEM))
/**
 * wrap list_add into list_first so the list is rewinded after insertion
 */
#define list_add(LIST, POS, ITEM) list_first(list_add(LIST, POS, ITEM))
/**
 * wrap list_remove into list_first so the list is rewinded after deletion
 */
#define list_remove(LIST, POS) list_first(list_remove(LIST, POS))

#endif

/**
 * adds an item after the last element of a list
 * @param LIST pointer to the list
 * @param ITEM pointer to the item
 * @return @see list_add
 */
#define list_append(LIST, ITEM) list_add(list_last(LIST), 0, ITEM)

/**
 * adds an item before the last element of a list
 * @param LIST pointer to the list
 * @param ITEM pointer to the item
 * @return @see list_insert
 */
#define list_prepend(LIST, ITEM) list_insert(list_first(LIST), 0, ITEM)

#ifndef NULL
#define NULL 0
#endif

#endif
