# Makefile to build the pthread application

DEPS=program.c # program file(s)
FLAGS=-std=c99 -lpthread -o
EXEC=application # compiled program name
CC=clang # compiler

all: $(EXEC)

check: $(EXEC)
	./$(EXEC)

application: $(DEPS)
	$(CC) $(DEPS) $(FLAGS) $(EXEC)

clean:
	rm $(EXEC)

.PHONY: clean
.PHONY: all
