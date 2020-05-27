all: hello

hello: hello.o
	 gcc -o build/hello hello.o

hello.o: hello.c
	 gcc -c hello.c
     
clean:
	 rm hello.o build/hello