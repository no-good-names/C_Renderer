CC = gcc

SRC_DIR= src
BUILD_DIR= bin
TEST_DIR= test

INCLUDE_PATHS= -IC:\SDL2\x64\include\SDL2
LIBRARY_PATHS= -LC:\SDL2\x64\lib
COMPILER_FLAGS= 
LINKER_FLAGS= -lmingw32 -lSDL2main -lSDL2

all: main bin

main: $(SRC_DIR)\main.c
		$(CC) $(SRC_DIR)\main.c $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(BUILD_DIR)\main

always: bin

bin:
		mkdir -p $(BUILD_DIR)