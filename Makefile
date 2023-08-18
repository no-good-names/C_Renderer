# Created by: no-good-names
# Created on: 2023-07-31
# Updated on: 2023-08-18

CC = gcc
SRC_DIR= src
BUILD_DIR= bin

INCLUDE_PATHS= -IC:\SDL2\x64\include\SDL2
LIBRARY_PATHS= -LC:\SDL2\x64\lib
COMPILER_FLAGS= -w
LINKER_FLAGS= -lmingw32 -lSDL2main -lSDL2

.PHONY: all clean run

all: $(BUILD_DIR)/main

$(BUILD_DIR)/main: $(SRC_DIR)/main.c
	@echo "Building..."
	@mkdir -p $(BUILD_DIR)
	@$(CC) $(SRC_DIR)\main.c $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(BUILD_DIR)/main
	@echo "Building finished."

clean: 
	@echo "Cleaning..."
	@rm -rf $(BUILD_DIR)
	@echo "Cleaning finished."

run: all
	@echo "Running..."
	@.\$(BUILD_DIR)\main
	@echo "Task finished."
