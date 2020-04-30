Demonstrate that it is possible to link against C++ shared library dynamically with C program.

After `make`, then check with

```
readelf -d main
```

you will see that the main program requires both `libcpp.so` and C standard library, but nothing about C++ standard library.

Try to do it again with `libcpp.so`, you will see now it requires C++ standard library.
