all: init exec example1 example2

init: 
	mkdir -p build

exec: 
	gcc -o build/exec exec.c -lrt

example1:
	gcc -o build/example1 example1.c -lrt

example2:
	gcc -o build/example2 example2.c -lrt

clean:
	 rm build/*
