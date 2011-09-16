#include <time.h>
#include <stdlib.h>

#include "include/random.h"
void random_init()
{
    time_t now = time(NULL);
    srand(now);
}

int oh_random()
{
    clock_t ticks = clock();
    return ticks + rand();
}

int oh_random_range(int min, int max)
{
    return random()%(max-min) + min;
}
