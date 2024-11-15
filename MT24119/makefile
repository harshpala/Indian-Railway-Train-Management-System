# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -fPIC

# Targets
SHARED_LIBRARY = librailway.so
STATIC_LIBRARY = librailway.a
EXECUTABLE_SHARED = main_shared.exe
EXECUTABLE_STATIC = main_static.exe

# Source files
LIB_SOURCES = Station.cpp Platform.cpp Line.cpp
MAIN_SOURCE = main.cpp
LIB_OBJECTS = $(LIB_SOURCES:.cpp=.o)

# Default target: Build everything
all: $(SHARED_LIBRARY) $(STATIC_LIBRARY) $(EXECUTABLE_SHARED) $(EXECUTABLE_STATIC)

# Build the shared library (.so)
$(SHARED_LIBRARY): $(LIB_OBJECTS)
	$(CXX) $(CXXFLAGS) -shared -o $@ $(LIB_OBJECTS)

# Build the static library (.a)
$(STATIC_LIBRARY): $(LIB_OBJECTS)
	ar rcs $@ $(LIB_OBJECTS)

# Build the executable with shared library
$(EXECUTABLE_SHARED): $(MAIN_SOURCE) $(SHARED_LIBRARY)
	$(CXX) -o $@ $(MAIN_SOURCE) -L. -lrailway

# Build the executable with static library
$(EXECUTABLE_STATIC): $(MAIN_SOURCE) $(STATIC_LIBRARY)
	$(CXX) -o $@ $(MAIN_SOURCE) -L. -lrailway -static

# Compile object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	del /f $(LIB_OBJECTS) $(SHARED_LIBRARY) $(STATIC_LIBRARY) $(EXECUTABLE_SHARED) $(EXECUTABLE_STATIC)
