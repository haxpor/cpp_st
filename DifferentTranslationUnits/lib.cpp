#include "lib.h"

#ifdef USE_EXTERN
int one_instance_variable = 1;
#else
static int one_instance_variable = 1;
#endif

void increment_variable()
{
    one_instance_variable++;
}

int get_variable()
{
    return one_instance_variable;
}
