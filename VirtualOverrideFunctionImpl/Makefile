.PHONY: all clean

CC=g++
CXXFLAGS=-std=c++17 -Wall -Wextra -pedantic

all: a.out

a.out: Impl.o main.o
	$(CC) $^ -o $@

Impl.o: Impl.cpp Hdr.h
	$(CC) $(CXXFLAGS) -c $< -o $@

main.o: main.cpp Hdr.h
	$(CC) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.out *.o
