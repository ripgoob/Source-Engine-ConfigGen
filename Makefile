# Compiler
CC = gcc

# Directories
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN = hl2-tuner

# Flags
CFLAGS = -Wall -Wextra -Iinclude

# Collect .c files and convert to .o object files
SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Default target
all: $(BIN)

# Link object files to final binary
$(BIN): $(OBJS)
	$(CC) $(OBJS) -o $@

# Compile each .c to .o in obj/
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
.PHONY: all clean run list
# Run the program
run: $(BIN)
	./$(BIN) $(PRESET)
# Compiler and flags
# List available presets
list: $(BIN)
	./$(BIN) --list

# Clean build files
clean:
	rm -rf $(OBJ_DIR) $(BIN)