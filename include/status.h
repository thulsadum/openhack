#ifndef STATUS_H_INCLUDED
#define STATUS_H_INCLUDED

/**
 * @file status.h
 * @author Sebastian Claus <anthrax2k4@freenet.de>
 * @date Di 30 Aug 2011 18:31:21 CEST 
 * @brief definition of function return values, with respect to error conditions
 *
 */


/**
 * boolean return status
 */
enum status_bool_en {
	st_b_success=0, ///< function was successful
	st_b_fail=-1, ///< function failed
};

typedef enum status_bool_en status_bool; ///< type for status_bool_en

#endif //STATUS_H_INCLUDED
