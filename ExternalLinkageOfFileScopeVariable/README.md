# ExternalLinkageOfFileScopeVariable

Following is list of symbols in `Lib.o`

```
                 U __cxa_atexit
                 U __dso_handle
0000000000000000 D g_externNum
                 U _GLOBAL_OFFSET_TABLE_
00000000000000aa t _GLOBAL__sub_I_g_externNum
0000000000000000 T Foo()
000000000000005d t __static_initialization_and_destruction_0(int, int)
0000000000000004 d g_internNum
                 U std::ostream::operator<<(int)
                 U std::ostream::operator<<(std::ostream& (*)(std::ostream&))
                 U std::ios_base::Init::Init()
                 U std::ios_base::Init::~Init()
                 U std::cout
                 U std::basic_ostream<char, std::char_traits<char> >& std::endl<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&)
0000000000000000 b std::__ioinit
```

Above is from `nm -C Lib.o` after we build the project with `make`.

We see that `g_externNum` lives inside initialized data section and is global (external linkage, denoted with `D`).
But `g_internNum` which also lives inside initialized data section, but it is local (internal linkgage).

We will see the following linking problem when try to build the `main.o` which link against `Lib.o`

For GCC,

```
++ -std=c++17 -Wall -Wextra -pedantic -I./ -c Lib.cpp
g++ -std=c++17 -Wall -Wextra -pedantic -I./ main.cpp Lib.o
/usr/bin/ld: Lib.o:(.data+0x0): multiple definition of `g_externNum'; /tmp/cc7plf1g.o:(.data+0x0): first defined here
collect2: error: ld returned 1 exit status
make: *** [Makefile:8: main.o] Error 1
```

For Clang,

```
lang++ -std=c++17 -Wall -Wextra -pedantic -I./ -c Lib.cpp
clang++ -std=c++17 -Wall -Wextra -pedantic -I./ main.cpp Lib.o
/usr/bin/ld: Lib.o:(.data+0x0): multiple definition of `g_externNum'; /tmp/main-7f9d4f.o:(.data+0x0): first defined here
clang: error: linker command failed with exit code 1 (use -v to see invocation)
make: *** [Makefile:8: main.o] Error 1
```

So even at implementation file, we can still leak the definition to outside.
We should always make definition at file scope inside implementation file internal; by using `static`.
