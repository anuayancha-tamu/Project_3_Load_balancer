# Makefile for Load Balancer Project

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

# Source and object files
SRCS = main.cpp LoadBalancer.cpp WebServer.cpp RequestQueue.cpp Request.cpp Firewall.cpp
OBJS = $(SRCS:.cpp=.o)

# Target executable
TARGET = loadbalancer

# Default target
all: $(TARGET)

# Linking
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compilation rule
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET) log.txt