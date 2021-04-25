.PHONY: all clean

EXE=a.out
CXXFLAGS=-std=c++17 -Wall -Wextra -pedantic -Wno-unused-function -g

all: profile

profile: $(EXE)
release: $(EXE)
release: CXXFLAGS += -O2

$(EXE): Lib.o
	g++ $(CXXFLAGS) main.cpp Lib.o

Lib.o: Lib.cpp
	g++ $(CXXFLAGS) -c $<

clean:
	rm -f *.o a.out
