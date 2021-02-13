.PHONY: all clean

COMPILER := g++

all: main.o

main.o: main.cpp Lib.o
	${COMPILER} -std=c++17 -Wall -Wextra -pedantic -I./ main.cpp Lib.o

Lib.o: Lib.h Lib.cpp
	${COMPILER} -std=c++17 -Wall -Wextra -pedantic -I./ -c Lib.cpp

clean:
	rm -rf *.out *.o
