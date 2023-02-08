EXE = main.out

SOURCES = main.cpp
SOURCES += Another.cpp Another2.cpp

OBJS = $(addsuffix .o, $(basename $(notdir $(SOURCES))))

CXX = g++
CXXFLAGS = -std=c++11 -I./

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(EXE)
	@echo Build complete

$(EXE): $(OBJS) 
	$(CXX) -o $@ $^

clean:
	rm -f $(EXE) $(OBJS)

