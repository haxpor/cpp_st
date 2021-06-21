.PHONY: all main libdummy clean

COMPILER=g++
CXX_FLAGS=-std=c++17 -Wall -Wextra -pedantic -g

all: libdummy main

main: main.cpp
	${COMPILER} $< -L. -ldummy

libdummy: libdummy.o
	${COMPILER} -shared -o libdummy.so libdummy.o

libdummy.o: libdummy.cpp libdummy.h
	${COMPILER} -c -fPIC -I. $<

clean:
	rm -rf *.out *.so *.o
