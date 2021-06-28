.PHONY: all clean main lib lib2

COMPILER=g++
CXX_FLAGS=-std=c++17 -Wall -Wextra -pedantic -I./ -L./

all: main lib lib2

main: main.o lib lib2
	${COMPILER} ${CXX_FLAGS} $< -llib -llib2

main.o: main.cpp lib.h lib2.h
	${COMPILER} ${CXX_FLAGS} -c $<

lib: lib.o
	${COMPILER} -shared $< -o liblib.so
lib.o: lib.cpp lib.h
	${COMPILER} -c ${CXX_FLAGS} -fPIC $<

lib2: lib2.o
	${COMPILER} -shared $< -o liblib2.so

lib2.o: lib2.cpp lib2.h
	${COMPILER} -c ${CXX_FLAGS} -fPIC $<

clean:
	rm -rf *.out *.so *.o
