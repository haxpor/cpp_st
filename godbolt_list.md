# The following is the online tests on godbolt.org

* https://godbolt.org/z/8hh7a633v - nested pointer of the parent class that is allocated on the heap won't be deallocated automatically if `delete` the parent object only, we need to `delete` each individual of the class's data member as well
* https://godbolt.org/z/eKMvfqP7v - compare passing a pointer by value and by reference 
* https://godbolt.org/z/eaozssao5 - double pointer memory deletion handling (no leak, checked with valgrind on Linux)
* https://godbolt.org/z/rEahKqGsf - double pointer memory deletion handling with the main pointer array is as of opaque pointer type (no leak, checked with valgrind on Linux)
* https://godbolt.org/z/bbErcGsGG - validate that ::operator new is just a global scope function that we can call (included store address of function into std::function, and demonstrate the use of allocate memory, and deallocate memory using ::operator new/delete, and placement new)
* https://godbolt.org/z/zfEezvrK1 - share common code in implementing output operator for a custom type without having to duplicate implementation for both ASCII string, and wide-string character
