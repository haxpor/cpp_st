# The following is the online tests on godbolt.org

* https://godbolt.org/z/8hh7a633v - nested pointer of the parent class that is allocated on the heap won't be deallocated automatically if `delete` the parent object only, we need to `delete` each individual of the class's data member as well
* https://godbolt.org/z/eKMvfqP7v - compare passing a pointer by value and by reference 
* https://godbolt.org/z/eaozssao5 - double pointer memory deletion handling
