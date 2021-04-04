.PHONY: all clean

EXE = ReferenceIsAlsoOpaque
CXXFLAGS = -g -Wall -Wextra -pedantic -I./

all: $(EXE)

WidgetHelper.o: WidgetHelper.cpp
	g++ $(CXXFLAGS) -c $< -o $@

main.o: main.cpp
	g++ $(CXXFLAGS) -c $< -o $@

$(EXE): WidgetHelper.o main.o
	g++ $^ $(CXXFLAGS) -o $@

clean:
	echo $(OBJS)
	rm -rf *.o $(EXE)
