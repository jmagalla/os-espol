all: build build/hello

#target: prerequisites
build: 
	 mkdir -p build

build/hello: hello.o
	 gcc hello.o -o build/hello 

hello.o: hello.c
	 gcc -c hello.c

clean:
	 rm *.o build/* 