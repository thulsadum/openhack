#include <stdio.h>
#include "include/random.h"

int main(int argc, char** argv)
{
	int i;
	for(i=0; i<10; i++)
	    printf("%d\n", random(1,10));
	printf(":)");
	return 0;
}
