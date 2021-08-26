#pragma once

#include <functional>

struct MyAnotherType;

using MyAliasedType = MyAnotherType;
using MyFuncSigT = std::function<void(MyAnotherType&)>;
