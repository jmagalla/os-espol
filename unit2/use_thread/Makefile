all: init simple onethread nthread use_join

init: 
	mkdir -p build

simple: simple_example.c
	gcc -o build/simple simple_example.c -lpthread

onethread: multi_matrix/onethread.c
	gcc -o build/onethread multi_matrix/onethread.c -lpthread

nthread: multi_matrix/twothreads.c
	gcc -o build/twothreads multi_matrix/twothreads.c -lpthread

use_join:
	gcc -o build/use_join use_join.c -lpthread