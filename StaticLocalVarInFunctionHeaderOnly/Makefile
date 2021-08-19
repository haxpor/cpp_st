.PHONY: all clean a.out

CC=g++
CXX_FLAGS_COMMON=-std=c++17 -Wall -Wextra -pedantic -O2 -DANOTHER_API= -DANOTHER2_API=

all: a.out

a.out: main.o libanother.so libanother2.so
	g++ $(CXX_FLAGS_COMMON) $< -L. -lanother -lanother2 -o $@

main.o: main.cpp Lib.h
	g++ $(CXX_FLAGS_COMMON) -c $< -o $@

libanother.so: another.o
	g++ $(CXX_FLAGS_COMMON) -shared $< -o $@

another.o: another.cpp another.h Lib.h platform.h
	g++ $(CXX_FLAGS_COMMON) -fPIC -c $< -o $@

libanother2.so: another2.o
	g++ $(CXX_FLAGS_COMMON) -shared $< -o $@

another2.o: another2.cpp another2.h Lib.h platform.h
	g++ $(CXX_FLAGS_COMMON) -fPIC -c $< -o $@

clean:
	rm -rf *.out *.o *.so
