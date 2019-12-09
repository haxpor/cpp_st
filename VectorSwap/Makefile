.PHONY: all clean

all:
	g++ -g -std=c++11 -c VectorSwap.cpp
	objdump -d -M intel -S VectorSwap.o > VectorSwap.s
	@echo Done. Now look at VectorSwap.s file.
	@echo "Try searching for std::swap or std::vector::swap in such file."

clean:
	rm -rf *.o *.s
