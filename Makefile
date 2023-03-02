# paths
SRC = ./src
INCLUDE = ./include

# silent command output
MAKE += --silent

# compiler options
CXX = g++
CXXFLAGS = -Wall -Werror -g -O0 -I$(INCLUDE)

# executable
EXEC = blackjack

# source and object files
SRCS = $(wildcard $(SRC)/*.cpp)
OBJS = $(patsubst %.cpp,%.o,$(SRCS))

all: run clean

$(EXEC): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJS)

%.o: %.cpp
	@$(CXX) -c -o $@ $< $(CXXFLAGS)

run: $(EXEC)
	@./$(EXEC)

clean:
	@$(RM) $(EXEC) $(OBJS)

.PHONY: all run clean