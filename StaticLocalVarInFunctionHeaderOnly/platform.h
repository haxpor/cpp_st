#pragma once

#ifdef _WIN32
#define dllexport __declspec(dllexport)
#define dllimport __declspec(dllimport)
#else
#define dllexport __declspec(dllexport)
#define dllimport __declspec(dllimport)
#endif
