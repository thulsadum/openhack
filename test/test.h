#ifndef TEST_H
#define TEST_H

#include <stdio.h>

#include "config.h"

#ifdef CFG_DEBUG_TESTS
#include <stdio.h>

#define dlog(...) printf("Debug: " __VA_ARGS__)

#else

#define dlog(...)

#endif

#endif
