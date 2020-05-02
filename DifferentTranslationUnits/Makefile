.PHONY: all extern main main-extern lib lib-extern another_tu another_tu-extern clean

CXXFLAGS = -std=c++11 -Wall -Werror -pedantic -I.

all: lib another_tu main
	@echo "Built normally"

extern: lib-extern another_tu-extern main-extern
	@echo "Built via USE_EXTERN"

lib: lib.o

lib-extern: lib-extern.o

lib.o: lib.cpp lib.h
	g++ $(CXXFLAGS) -c lib.cpp -o $@

lib-extern.o: lib.cpp lib.h
	g++ $(CXXFLAGS) -DUSE_EXTERN -c lib.cpp -o $@

# this will be a proving point for different translation unit compiling this whole program
another_tu: another_tu.o 

another_tu-extern: another_tu-extern.o

another_tu.o: another_tu.cpp another_tu.h lib.h
	g++ $(CXXFLAGS) -c another_tu.cpp -o $@

another_tu-extern.o: another_tu.cpp another_tu.h lib.h
	g++ $(CXXFLAGS) -DUSE_EXTERN -c another_tu.cpp -o $@

main: main.cpp lib.o another_tu.o
	g++ $(CXXFLAGS) main.cpp lib.o another_tu.o -o main

main-extern: main.cpp lib-extern.o another_tu-extern.o
	g++ $(CXXFLAGS) -DUSE_EXTERN main.cpp lib-extern.o another_tu-extern.o -o main

clean:
	rm -rf *.o main

