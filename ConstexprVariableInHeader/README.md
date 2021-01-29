# ConstexprVariableInHeader

There are 2 main source files which are

1. `Main.cpp`
2. `Main2.cpp`

both consume `Lib.h` which defined `constexpr` variable either with or without `static` for the different in effect we will see in building the project.

# Explanation

`constexpr` variable at global scope has different meaning to `constexpr` defined within class scope.

At global scope, it will be internal linkage by default. But if it defined inside class scope with `static`, it will implied to be `inline`.

Anyway, `constexpr` at global scope will be optimized to be inlined if compiler sees it can, just only with no optimization applied (at least on GCC), such `constexpr` won't be inlined.

# Building

Compile `Main.cpp` and `Main2.cpp` with

```
g++ -std=c++17 -Wall -Wextra -pedantic -O0 <source-main-file.cpp>
```

As well as changing `-O0` to `-O0` to see different effect when no optimization applied.

