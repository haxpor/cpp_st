# ConstexprInNamespaceScopeVSGlobalScope

Prove-of-concept for difference of `constexpr` vs `inline constexpr` for non-static
variable at global, and namespace scope (no difference).

So in conclusion, `constexpr` will have internal linkage thus will violate ODR-use
when multiple translation-units refer to it as we can inspect from the difference
of memory address shown.

`g_num2` and `g_num4` should be a way to go for declaration/definition of ODR
global variable that we want it to have just one instance for entire program
for multiple translation units to refer to.

# Build

`Makefile` is provided to build for both GCC or Clang.

Execute it like the following

## Build for GCC

By default, `Makefile` will base on compiling with `g++`.

```
make
```

or

```
make COMPILER=g++
```

## Build for Clang

```
make COMPILER=clang++
```

