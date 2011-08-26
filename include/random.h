#ifndef RANDOM_H
#define RANDOM_H

/**
 * @file random.h
 * @author Sebastian Claus
 * @date 2011-08-24
 * @brief some simple random functions
 */

/**
 * gets an random number in an given range.
 * @param min int minimal value. inclusive bound
 * @param max int maximal value. exlcusive bound
 * @return int between min and max
 */
int oh_random_range(int min, int max);

/**
 * get an random number
 * @return int a random number
 */
int oh_random();

/**
 * called for initialising random generator
 */
void random_init();

#define randomRange oh_random_range

#endif //RANDOM_H
