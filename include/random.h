#ifndef RANDOM_H
#define RANDOM_H

/**
 * @author Sebastian Claus
 * @date 2011-08-24
 * some simple random functions
 */

/**
 * gets an random number in an given range.
 * @param min int minimal value. inclusive bound
 * @param max int maximal value. exlcusive bound
 * @return int between min and max
 */
int random(int min, int max);

/**
 * get an random number
 * @return int a random number
 */
int random();

/**
 * called for initialising random generator
 */
void random_init();
#endif //RANDOM_H
