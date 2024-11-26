.PHONY: read write compile clean

run: main
	@./main
	@echo done 

compile: main

main: main.o
	@gcc -o main main.o -Wall -lm

main.o:
	@gcc -c main.c

clean:
	@rm -f *.o *.out main