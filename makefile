# Makefile to build the pthread application

DEPS=program.c 
FLAGS=-std=c99 -lpthread -o
EXEC=application
CC=clang # gcc

all: $(EXEC)

check: ./$(EXEC)

application: $(DEPS)
	$(CC) $(DEPS) $(FLAGS) $(EXEC)

clean:
	rm $(EXEC)

.PHONY: clean
.PHONY: all

