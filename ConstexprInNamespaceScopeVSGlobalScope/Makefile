.PHONY: all clean

COMPILER := g++

all: Main.o

Main.o: Consumer1.o Consumer2.o Main.cpp
	$(COMPILER) -std=c++17 -Wall -Wextra -pedantic -I./ Main.cpp Consumer1.o Consumer2.o

Consumer1.o: Consumer1.cpp Consumer1.h
	$(COMPILER) -std=c++17 -Wall -Wextra -pedantic -I./ -c Consumer1.cpp

Consumer2.o: Consumer2.cpp Consumer2.h
	$(COMPILER) -std=c++17 -Wall -Wextra -pedantic -I./ -c Consumer2.cpp

clean:
	rm -rf *.out *.o
