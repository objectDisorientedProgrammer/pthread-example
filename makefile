# Makefile to build the pthread application

DEPS=program.c program.h
FLAGS=-std=c99 -lpthread -o
EXEC=application

all: $(EXEC)

check: ./$(EXEC)

application: $(DEPS)
	gcc $(DEPS) $(FLAGS) $(EXEC)

clean:
	rm $(EXEC)

.PHONY: clean
.PHONY: all

