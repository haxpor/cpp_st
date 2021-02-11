Most of the source files are compiled with (unless noted inside the source file)

`g++ -std=c++17 -Wall -Wextra -pedantic <source-file1> <source-file2> ...`

this is similar and features equivalent if compile with clang, just substitute
`clang` in-place of `g++` for the above command.

then you can execute via `./a.out`.

For the case of MSVC, you can execute the following

`cl.exe /EHsc /std:c++17 /W4 <source-file1> ...`

Most of program is a simple single source file program, thus you can judge by its file name for what
to expect. Otherwise for more complex program, it should be inside a directory. Read comment inside main source file of each program for more information on how to compile (in case it's complicated, or what is it demonstrated).

This is by design not to have any build system.

## Note ##

If any source file needs to access resource at run time, those resource files will be inside `res` directory.
