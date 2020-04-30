.PHONY: all clean main lib

all: lib main

lib: cpp_lib.cpp cpp_lib.h
	g++ -c -Wall -Werror -std=c++11 -fPIC -I. cpp_lib.cpp
	g++ -shared -o libcpp.so cpp_lib.o

main: lib main.c
	gcc -Wall -Werror -o main -I. main.c -L. -lcpp

clean:
	rm *.o libcpp.so
	rm main
