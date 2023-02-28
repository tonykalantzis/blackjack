# paths
SRC = ./src
INCLUDE = ./include

# silent command output
MAKE += --silent

# compiler options
CXX = g++
CXXFLAGS = -Wall -Werror -g -O0 -I$(INCLUDE)

# .o and executable
EXEC = exec
OBJS = $(SRC)/Card.o $(SRC)/Deck.o $(SRC)/Player.o $(SRC)/Blackjack.o $(SRC)/main.o

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