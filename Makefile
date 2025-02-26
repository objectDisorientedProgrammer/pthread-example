# Makefile to build the pthread application

CI=commandInterpreter
TL=threadLib
DEPS= $(CI).o $(TL).o # program file(s)
FLAGS=-std=c99 -lpthread
EXEC=runner # compiled program name
CC=clang # compiler

all: $(EXEC)

check: $(EXEC)
	./$(EXEC)

$(CI).o: $(CI).c
	$(CC) $(FLAGS) -c $(CI).c

$(TL).o: $(TL).c
	$(CC) $(FLAGS) -c $(TL).c

$(EXEC): $(DEPS)
	$(CC) main.c $(DEPS) $(FLAGS) -o $(EXEC)

clean:
	rm $(EXEC) $(CI).o $(TL).o

.PHONY: clean
.PHONY: all
