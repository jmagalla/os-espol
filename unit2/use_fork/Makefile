all: init example1 example2 example3 fork_wait

init: 
	mkdir -p build

example1:
	gcc -o build/example1 example1.c

example2:
	gcc -o build/example2 example2.c

example3:
	gcc -o build/example3 example3.c

fork_wait: 
	gcc -o build/fork_wait fork_wait.c

clean:
	rm build/*
