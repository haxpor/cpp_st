all: V2

V2: main.cpp lib.cpp lib.h
	g++ -std=c++17 -DV2 $^

base: main.cpp lib.cpp lib.h
	g++ -std=c++17 $^

clean:
	rm -rf a.out
