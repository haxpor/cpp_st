#pragma once

#include "StructVar.h"
#include "WeakSymbol.h"

// declared it outside of the class scope
extern StructVar g_structVar2;

WEAK_SYMBOL StructVar g_structVar3;
extern StructVar g_structVar4;

struct Lib2
{
};
