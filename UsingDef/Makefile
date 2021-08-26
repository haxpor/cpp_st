.PHONY: all clean

CC=g++
CXXFLAGS=-std=c++17 -Wall -Wextra -pedantic

all: main.cpp Hdr.h MyAnotherType.h
	$(CC) $(CXXFLAGS) $<

clean:
	rm -f *.out
