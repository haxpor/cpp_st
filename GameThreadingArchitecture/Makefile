EXE = a.out
# only set if it's not set yet
DEBUG ?= 1

SOURCES = main.cpp Common.h
HEADERS = Common.h GameState.h GameThreadManager.h MathUtil.h ProfileCommon.h RenderingThreadManager.h TGAImage.h ThreadPool.h

OBJS = $(addsuffix .o, $(basename $(notdir $(SOURCES))))
HEADERSS = $(addsuffix .o, $(basename $(notdir $(HEADERS))))

CXX = g++

CXXFLAGS = -g -pg -Wall -Wextra -pedantic -std=c++11 -I./
CXXLDFLAGS = -pg -lpthread

ifneq ($(DEBUG), 1)
CXXFLAGS = -g -O2 -DNDEBUG -Wall -Wextra -pedantic -std=c++11 -I./
CXXLDFLAGS = -lpthread
endif

# optimized build

.PHONY: all clean

all: $(EXE)
	@echo Build complete

# include $(HEADERS) like this will make it depended by %.o target so it would catch the changes
# and recompile. Caveat is it will recompile all source files.
%.o:%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(EXE): $(OBJS)
	$(CXX) -o $@ $^ $(CXXLDFLAGS)

clean:
	rm -f $(EXE) $(OBJS)

