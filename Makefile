# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

# Target executable name
TARGET = card_program

# Source files
SRCS = main.cpp card.cpp user.cpp ninenine.cpp
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files to object files
%.o: %.cpp $(CXX) $(CXXFLAGS) -c $< -o $@

# Dependencies
main.o: main.cpp ninenine.h
card.o: card.cpp card.h
user.o: user.cpp card.h
ninenine.o: ninenine.cpp ninenine.h card.h user.h

# Clean up generated files
clean: 
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean