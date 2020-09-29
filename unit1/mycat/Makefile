all: build build/mycat

build:
	mkdir -p build

build/mycat: main.cpp 
	 g++ -g -Wall -o build/mycat main.cpp

clean:
	 rm *.o build/*
