all: build build/whileloop

build: 
	mkdir -p build

build/whileloop: main.o
	gcc main.o -o build/whileloop 

main.o: main.c 
	gcc -g -Wall -o main.o -c main.c

clean:
	rm *.o build/*

