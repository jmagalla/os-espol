all: build build/generator

build: 
	mkdir -p build

build/generator: generator.o utils.o 
	g++ generator.o utils.o -o build/generator

generator.o: generator.cpp
	g++ -o generator.o -c generator.cpp

utils.o: utils.cpp
	g++ -o utils.o -c utils.cpp

clean:
	rm *.o build/*