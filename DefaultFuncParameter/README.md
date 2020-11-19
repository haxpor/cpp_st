# Things to pay attention

Look at `ConsumerHeader.h` for the declaration of `foo` function which defines default parameter. Source file that implements this function has no need to define default parameter again, but if it defines any, such value needs to be the same as what defined in the header otherwise the following compile error will happen.

```
ConsumerHeader.cpp:3:6: error: default argument given for parameter                                                                                                                                                                                                         1 of ‘void Consumer::foo(int)’                                                                                                                                                                                                                                              3 | void Consumer::foo(int a=30)                                                                                                                                                                                                                                              |      ^~~~~~~~                                                                                                                                                                                                                                                           In file included from ConsumerHeader.cpp:1:                                                                                                                                                                                                                                 ConsumerHeader.h:17:15: note: previous specification in ‘virtual void
Consumer::foo(int)’ here                                                                                                                                                                                                                                                    17 |  virtual void foo(int a=20) override;
```

Also look at the comment inside `ConsumerHeader.h` for the case when default
parameter can be omitted and nullify the previously defined default function parameter
as set via included header file that it includes from.
