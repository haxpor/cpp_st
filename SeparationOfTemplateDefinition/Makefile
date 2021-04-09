.PHONY: all clean

EXE = septd
CXXFLAGS = -g -Wall -Wextra -pedantic -std=c++17 -I./
all: $(EXE)

$(EXE): TemplateLib.o main.o
	g++ $(CXXFLAGS) $^ -o $@

TemplateLib.o: TemplateLib.cpp TemplateLib.h
	g++ $(CXXFLAGS) -c $< -o $@

main.o: main.cpp
	g++ $(CXXFLAGS) -c $< -o $@

clean:
	rm -f *.o $(EXE)
