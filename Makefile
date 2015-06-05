# Specify compiler and settings
CC = gcc
CFLAGS = -Werror -Wall -Wextra

# Set up a phony target to build everything
.PHONY: all
all: assign2

assign2: a2lib.h a2lib.c

# Recompile if something changes
%: %.c
	$(CC) $(CFLAGS) -o $@ $^

#cleaning the objecr files so they do not create swap
clean: 
		rm -rf *o hello
