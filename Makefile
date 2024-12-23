# Compiler and Flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude -lsfml-graphics -lsfml-window -lsfml-system

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BIN_DIR = bin
RESOURCES_DIR = resources

# Source and Object Files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BIN_DIR)/%.o)
TARGET = SheepFight

# Rules
$all: $(TARGET)

# Build the main executable
$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CXX) $(OBJS) -o $(TARGET) $(CXXFLAGS) 

# Compile each source file into an object file
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

# Create bin directory if it doesn't exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Clean up generated files
clean:
	rm -rf $(BIN_DIR) $(TARGET)

# Phony targets
.PHONY: all clean run

#bin files : $ ^ -o  g++ $(CXX) + .Phony : if ( correct : ) 
