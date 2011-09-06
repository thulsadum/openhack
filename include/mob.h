#ifndef MOB_H_INCLUDED
#define MOB_H_INCLUDED

/**
 * @file mob.h
 * @author Sebastian Claus <anthrax2k4@freenet.de>
 * @date Di 30 Aug 2011 16:53:01 CEST 
 * @brief definitions for mobs
 *
 */

typedef struct mob_st mob_t; ///< type for mob_st
typedef struct attributes_st attributes_t; ///< type for attributes_st
typedef struct loot_st loot_t; ///< type for loot_st

typedef void (*logic_fn_t)(mob_t*); ///< type for function pointers to logic callback

/**
 * describing the loot of a monster
 */
struct loot_st {
	unsigned int objectId; ///< id (array index) of the object to drop;
	unsigned int prop_num; ///< propability numerator
	unsigned int prup_denom; ///< propability denomerator: chance = prop_num/prop_denom
};

/// @todo decide underlying rules
struct attributes_st {
	int str;
	int dex;
};

struct mob_st {
	unsigned int properties;
	char character;
	int x;
	int y;
	//attributes_t attributes;
	//logic_fn_t logic_callback;
	//loot_t loots[];
};

/**
 * moves a mob.
 * @param mob the mob to move.
 * @param dx delta x.
 * @param dy delta y.
 */
void mob_move(mob_t* mob, int dx, int dy);


#endif //MOB_H_INCLUDED
