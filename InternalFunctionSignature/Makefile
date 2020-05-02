.PHONY: main clean problem

CXXFLAGS=-Wall -Werror -pedantic -std=c++11

all: lib.o main

problem: lib-problem.o main

lib.o: lib.cpp lib.h
	g++ $(CXXFLAGS) -c lib.cpp -o lib.o

lib-problem.o: lib.cpp lib.h
	g++ $(CXXFLAGS) -DPROBLEM -c lib.cpp -o lib.o

main: main.cpp
	g++ $(CXXFLAGS) main.cpp lib.o -o main

clean:
	rm -rf *.o main
