CXX := g++

.PHONY: all clean

all:
	$(CXX) -c -Wall -O0 -fpic MyLib.cpp
	$(CXX) -shared -o libMyLib.so MyLib.o
# also output assembly so we can inspect whether such 'static constexpr` is inlined or not
	$(CXX) -S -Wall -Winline -O0 main.cpp -I. -L. -lMyLib -o main.out

clean:
	rm -rf MyLib.o libMyLib.so main.o main.out main.s
