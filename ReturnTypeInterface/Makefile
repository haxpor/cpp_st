.PHONY: all clean

CXXFLAGS = -g -Wall -Wextra -pedantic -std=c++17 -I./

all: a.out

a.out: Lib.o Widget.o main.o
	g++ $(CXXFLAGS) $^ -o $@

Lib.o: Lib.cpp Lib.h
	g++ $(CXXFLAGS) -c $< -o $@

Widget.o: Widget.cpp Widget.h
	g++ $(CXXFLAGS) -c $< -o $@

main.o: main.cpp
	g++ $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o a.out
