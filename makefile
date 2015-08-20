DEPS=program.c program.h
FLAGS=-o
EXEC=application

all: application

application: program.c
	gcc $(DEPS) $(FLAGS) $(EXEC)
