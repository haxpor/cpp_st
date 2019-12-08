CXX = g++
CXXFLAGS_NON = -O2 -I. -o FindMaxNonSIMD.out
CXXFLAGS = -O2 -I. -msse2 -o FindMaxSIMD.out

.PHONY: all clean

all:
	$(CXX) FindMaxNonSIMD.cpp $(CXXFLAGS_NON)
	$(CXX) FindMaxSIMD.cpp $(CXXFLAGS)
	@echo "Done"

clean:
	rm -rf FindMaxNonSIMD.out FindMaxSIMD.out
