.PHONY: all clean

# allow compiler to be changed from externally at command line
# e.g. make COMPILER=clang++
COMPILER ?= g++
CXXFLAGS = -g -Wall -Wextra -pedantic -std=c++17 -O2
COMMON_HEADER_FILES = WeakSymbol.h

all: a.out

# Order of dependent object files here is important to dictate which definition symbol compiler will use
a.out: Lib1.o Lib2.o main.o 
	$(COMPILER) $(CXXFLAGS) $^ -o $@

Lib1.o: Lib1.cpp Lib1.h $(COMMON_HEADER_FILES)
	$(COMPILER) $(CXXFLAGS) -c $< -o $@

Lib2.o: Lib2.cpp Lib2.h StructVar.h $(COMMON_HEADER_FILES)
	$(COMPILER) $(CXXFLAGS) -c $< -o $@

main.o: main.cpp $(COMMON_HEADER_FILES)
	$(COMPILER) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o a.out
