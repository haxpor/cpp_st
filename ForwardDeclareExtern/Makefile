.PHONY: all clean

OUT = a.out
CXXFLAGS=-std=c++17 -Wall -Wextra -pedantic

all: $(OUT)

$(OUT): main.o Lib.o
	g++ $(CXXFLAGS) $^ -o $@

main.o: main.cpp Type.h Lib.h
	g++ $(CXXFLAGS) -c $< -o $@

Lib.o: Lib.cpp Lib.h
	g++ $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf *.o $(OUT)
