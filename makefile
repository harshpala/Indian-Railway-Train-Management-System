# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -fPIC

# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# Targets
SHARED_LIBRARY = $(BUILD_DIR)/librailway.so
STATIC_LIBRARY = $(BUILD_DIR)/librailway.a
EXECUTABLE_SHARED = $(BUILD_DIR)/main_shared.exe
EXECUTABLE_STATIC = $(BUILD_DIR)/main_static.exe
TEST_EXECUTABLE = $(BUILD_DIR)/test_program.exe

# Source files
LIB_SOURCES = $(SRC_DIR)/Station.cpp $(SRC_DIR)/Platform.cpp $(SRC_DIR)/Line.cpp
MAIN_SOURCE = $(SRC_DIR)/main.cpp
TEST_SOURCE = $(SRC_DIR)/test_program.cpp
LIB_OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(LIB_SOURCES))

# Default target: Build everything
all: create_build_dir $(SHARED_LIBRARY) $(STATIC_LIBRARY) $(EXECUTABLE_SHARED) $(EXECUTABLE_STATIC) $(TEST_EXECUTABLE)

# Create build directory if it doesn't exist
create_build_dir:
	if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)

# Build the shared library (.so)
$(SHARED_LIBRARY): $(LIB_OBJECTS)
	$(CXX) $(CXXFLAGS) -shared -o $@ $(LIB_OBJECTS)

# Build the static library (.a)
$(STATIC_LIBRARY): $(LIB_OBJECTS)
	ar rcs $@ $(LIB_OBJECTS)

# Build the executable with shared library
$(EXECUTABLE_SHARED): $(MAIN_SOURCE) $(SHARED_LIBRARY)
	$(CXX) -o $@ $(MAIN_SOURCE) -L$(BUILD_DIR) -lrailway -I$(INCLUDE_DIR)

# Build the executable with static library
$(EXECUTABLE_STATIC): $(MAIN_SOURCE) $(STATIC_LIBRARY)
	$(CXX) -o $@ $(MAIN_SOURCE) -L$(BUILD_DIR) -lrailway -static -I$(INCLUDE_DIR)

# Build the test program executable
$(TEST_EXECUTABLE): $(TEST_SOURCE) $(LIB_OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $(TEST_SOURCE) $(LIB_OBJECTS) -I$(INCLUDE_DIR)

# Compile object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Clean up
clean:
	del /f $(BUILD_DIR)
