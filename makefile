all: main

main: main.c
	gcc -Wall main.c -o main
run:
	./main

clean:
	rm -rf main
