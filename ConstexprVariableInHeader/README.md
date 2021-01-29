# ConstexprVariableInHeader

There are 2 main source files which are

1. `Main.cpp`
2. `Main2.cpp`

both consume `Lib.h` which defined `constexpr` variable either with or without `static` for the different in effect we will see in building the project.

# Explanation

`constexpr` variable at global scope has different meaning to `constexpr` defined within class scope.

At global scope, it will be internal linkage by default. But if it defined inside class scope with `static`, it will implied to be `inline`.

Anyway, `constexpr` at global scope will be optimized to be inlined if compiler sees it can, just only with no optimization applied (at least on GCC), such `constexpr` won't be inlined.

# Non-optimization level or level 1 when built MSVC

All of those `constexpr` will be shown inside `.rdata` section for constant values as follows. We can use `dumpbin.exe` utility (official document: https://docs.microsoft.com/en-us/cpp/build/reference/dumpbin-reference?view=msvc-160) with `dumpbin.exe /ALL <exe-file> > output.log` then futher inspect or grep from such output file. Following is what we will find.

```
...
SECTION HEADER #3
  .rdata name
       0 physical address
       0 virtual address
      37 size of raw data
    BC95 file pointer to raw data (0000BC95 to 0000BCCB)
       0 file pointer to relocation table
       0 file pointer to line numbers
       0 number of relocations
       0 number of line numbers
40400040 flags
         Initialized Data
         8 byte align
         Read Only

RAW DATA #3
  00000000: 67 5F 76 61 72 69 61 62 6C 65 3A 20 00 00 00 00  g_variable: ....
  00000010: 67 5F 76 61 72 69 61 62 6C 65 32 3A 20 00 00 00  g_variable2: ...
  00000020: 55 74 69 6C 3A 3A 67 5F 75 74 69 6C 56 61 72 69  Util::g_utilVari
  00000030: 61 62 6C 65 3A 20 00                             able: .
...
```

# Level 2 optimization when built with MSVC

There won't be any of those variables inside `.rdata` section anywhere in executable file, but not to mention there's still is in `.obj` which should be normal or compiler to use it for optimize later in linking step.

# GCC

GCC is more heavily in optimize the program. Although at optimization level 0, `constexpr` variable without inline at global scope won't be inlined. Other than that, all will be inlined.

# Building

Compile `Main.cpp` and `Main2.cpp` with

```
g++ -std=c++17 -Wall -Wextra -pedantic -O0 <source-main-file.cpp>
```

As well as changing `-O0` to `-O0` to see different effect when no optimization applied.

