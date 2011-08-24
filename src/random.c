#include "include/random.h"

#include <time.h>
#include <stdlib.h>

void random_init()
{
    time_t now = time(NULL);
    srand(now);
}

int random()
{
    clock_t ticks = clock();
    return ticks + rand();
}

int random(int min, int max)
{
    return random()%(max-min) + min;
}
