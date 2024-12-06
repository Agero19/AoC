# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c2x

# Directories and files
SRCS = day_1.c distance_check.c sorting.c utility.c
HEADERS = distance_check.h sorting.h utility.h
OBJS = $(SRCS:.c=.o)
TARGET = run
DATA_DIR = data

# Build target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile individual source files into object files
%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

# Run the application
run: $(TARGET)
	./$(TARGET)

# Clean build files
clean:
	rm -f $(OBJS) $(TARGET)

# Clean and rebuild
rebuild: clean all

# Phony targets
.PHONY: all run clean rebuild
