#include "defs.h"
#include "lib.h"

/**
 * Initialize global variable is possible
 * not to have compile time function to do the thing.
 * But in C, it is not possible.
 */
const char* g_myName = GetName(eValue1);
