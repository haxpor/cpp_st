.PHONY: all clean

all: ConstExprFunction.o StaticConstExprFunction.o

ConstExprFunction.o: ConstExprFunction.cpp
	g++ -std=c++17 -O0 -c ConstExprFunction.cpp -S

StaticConstExprFunction.o: StaticConstExprFunction.cpp
	g++ -std=c++17 -O0 -c StaticConstExprFunction.cpp -S

clean:
	rm -rf *.out *.o *.s
