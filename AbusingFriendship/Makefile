.PHONY: all clean

EXE = af
CXXFLAGS = -g -std=c++17 -Wall -Wextra -pedantic -I./

all: $(EXE)

# This line if we link against Cert.o then we cann't inject our bypassed to call Authorize() from our Intruder component
# So we need to only link against our Intruder component (object file).
# We have to peek into the declaration of Cert class and re-declare it locally in our implementation file.
# TODO: Uncomment next line then comment following line to see the effect that Intruder won't work.
#$(EXE): Authorizer.o Cert.o Intruder.o main.o
$(EXE): Authorizer.o Intruder.o main.o
	g++ $(CXXFLAGS) $^ -o $@

Authorizer.o: Authorizer.cpp Authorizer.h
	g++ $(CXXFLAGS) -c $< -o $@

Cert.o: Cert.cpp Cert.h
	g++ $(CXXFLAGS) -c $< -o $@

Intruder.o: Intruder.cpp Intruder.h
	g++ $(CXXFLAGS) -c $< -o $@

main.o: main.cpp
	g++ $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf *.o
