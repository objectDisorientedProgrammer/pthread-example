DEPS=program.c program.h
FLAGS=-std=c99 -lpthread -o
EXEC=application

all: application

application: program.c
	gcc $(DEPS) $(FLAGS) $(EXEC)

clean:
	rm $(EXEC)

.PHONY: clean
.PHONY: all
