EXE = a.out

SOURCES = main.cpp Common.h
HEADERS = Common.h GameState.h GameThreadManager.h MathUtil.h ProfileCommon.h RenderingThreadManager.h TGAImage.h ThreadPool.h

OBJS = $(addsuffix .o, $(basename $(notdir $(SOURCES))))
HEADERSS = $(addsuffix .o, $(basename $(notdir $(HEADERS))))

CXX = g++
CXXFLAGS = -g -pg -Wall -Wextra -pedantic -std=c++11 -I./
CXXLDFLAGS = -pg -lpthread

# include $(HEADERS) like this will make it depended by %.o target so it would catch the changes
# and recompile. Caveat is it will recompile all source files.
%.o:%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

all: $(EXE)
	@echo Build complete

$(EXE): $(OBJS)
	$(CXX) -o $@ $^ $(CXXLDFLAGS)

clean:
	rm -f $(EXE) $(OBJS)

