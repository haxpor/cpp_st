.PHONY: all main libdummy clean

COMPILER=g++
CXX_FLAGS=-std=c++17 -Wall -Wextra -pedantic -g -O0

all: libdummy main

main: main.cpp
# need to use -fPIC or -fpic (see https://gcc.gnu.org/onlinedocs/gcc/Code-Gen-Options.html#Code-Gen-Options)
# to avoid segmentation fault
	${COMPILER} $< -fPIC -ldl

libdummy: libdummy.o
	${COMPILER} -shared -o libdummy.so libdummy.o

libdummy.o: libdummy.cpp libdummy.h
	${COMPILER} -c -fPIC -I. $<

clean:
	rm -rf *.out *.so *.o
