#pragma once

#if defined(_MSC_VER)
	#define WEAK_SYMBOL __declspec(selectany)
#elif defined(__GNUC__)
	#define WEAK_SYMBOL __attribute__((weak))
#else
	#error "Non support weak symbol for this compiler"
#endif
