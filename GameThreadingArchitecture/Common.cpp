#include "Common.h"

std::atomic_flag Logger::lock = ATOMIC_FLAG_INIT;
char Logger::fmtBuffer[MAX_BUFFER_SIZE];
