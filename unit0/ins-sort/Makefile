all: build build/ins-sort

build: 
	mkdir -p build

build/ins-sort: ins-sort.o utils.o
	g++ ins-sort.o utils.o -o buildcd /ins-sort

ins-sort.o: main.cpp
	g++ -o ins-sort.o -c main.cpp

utils.o: utils.cpp
	g++ -o utils.o -c utils.cpp

clean:
	rm *.o build/*