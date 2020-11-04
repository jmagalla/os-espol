all: build build/simple build/onethread build/nthreads build/use_join

build: 
	mkdir -p build

build/simple: simple_example.c
	gcc -o build/simple simple_example.c -lpthread

build/onethread: multi_matrix/onethread.c
	gcc -o build/onethread multi_matrix/onethread.c -lpthread

build/nthreads: multi_matrix/twothreads.c
	gcc -o build/nthreads multi_matrix/twothreads.c -lpthread

build/use_join:
	gcc -o build/use_join use_join.c -lpthread

clean: 
	rm -R build/
