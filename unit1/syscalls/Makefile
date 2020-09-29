all: build build/handerror

build: 
	mkdir -p build

build/handerror: main.o
	gcc main.o -o build/handerror 

main.o: main.c 
	gcc -g -Wall -o main.o -c main.c

clean:
	rm *.o build/*

