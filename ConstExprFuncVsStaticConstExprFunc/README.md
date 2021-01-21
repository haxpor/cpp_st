# Note

Included is the assembly code generated from GCC 9.3.0, and MSVC 19.27.29112.
Both `constexpr` and `static constexpr` will attempt to inline function for us if possible although MSVC needs us to declare receiving variable from calling constexpr function to be `constexpr` to make it happen.

Anyway, (not included in the source code) `static constexpr` for variable will be inline for both GCC and MSVC.

# Build

## Linux

Execute `make` then inspect `*.s` files to see inlining in effect (PS: value `55`).

## Windows

Execute `buld_win.bat` then inspect `*.asm` files to see inlining in effect (PS: value `55`).s
