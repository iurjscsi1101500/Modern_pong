UNAME_S := $(shell uname -s)
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
ifeq ($(UNAME_S), Linux)
LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
else ifeq ($(UNAME_S), Darwin)
LDFLAGS = -framework IOKit -framework Cocoa -framework OpenGL -lraylib
else
LDFLAGS = -lraylib -lopengl32 -lgdi32 -lwinmm
endif
SRCS = src/main.cpp src/ball.cpp src/menu.cpp src/paddle.cpp
OBJS = $(SRCS:.cpp=.o)
EXEC = PONG
all: $(EXEC)
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS) $(EXEC)
