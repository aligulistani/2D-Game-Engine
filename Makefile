# Compiler and flags
CC = g++
CFLAGS = -I"./libraries/include/"
LDFLAGS = -L"./libraries/lib/" -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lbox2d

# Source and build directories
SRC_DIR = src
BUILD_DIR = build

# Target executable
TARGET = main.exe

# Source files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# Default rule
all: # Rule to compile source files into object files
	$(CC) $(SOURCES) $(CFLAGS) $(LDFLAGS) -o $(TARGET) 

run:
	make clean && make && ./$(TARGET)

.PHONY: clean
clean: 
	rm -f $(TARGET)