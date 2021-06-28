.PHONY: all clean main lib lib2

COMPILER=g++
CXX_FLAGS=-std=c++17 -Wall -Wextra -pedantic -I./

all: main

main: main.cpp
	${COMPILER} ${CXX_FLAGS} $<

main.o: main.cpp lib.h lib2.h

clean:
	rm -rf *.out *.so *.o
