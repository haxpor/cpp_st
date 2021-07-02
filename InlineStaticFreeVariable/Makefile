.PHONY: all clean lib1.so lib2.so main

COMPILER=g++

CXX_FLAGS=-std=c++17 -Wall -Wextra -pedantic

all: main

main: main.o lib1.so lib2.so
	${COMPILER} $< -L./ -llib1 -llib2 

main.o: main.cpp
	${COMPILER} -c ${CXX_FLAGS} -Wno-unused-function $<

lib1.so: lib1.o
	${COMPILER} -shared $< -o lib$@

lib1.o: lib1.cpp lib1.h
	${COMPILER} -c ${CXX_FLAGS} -fPIC $<

lib2.so: lib2.o
	${COMPILER} -shared $< -o lib$@

lib2.o: lib2.cpp lib2.h
	${COMPILER} -c ${CXX_FLAGS} -fPIC $<

clean:
	rm -rf *.out *.so *.o
