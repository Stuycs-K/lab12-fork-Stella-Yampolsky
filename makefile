.PHONY: clean run compile
compile: main.o
	@gcc -Wall -o pro main.o
run: pro
	@./pro
main.o: main.c
	@gcc -c main.c
clean:
	@rm *.o
	@rm pro
