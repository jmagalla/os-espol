all: build build/simple build/use_exit build/onethread build/nthreads build/use_join

build: 
	mkdir -p build

build/simple: simple_example.c
	gcc -Wall -o build/simple simple_example.c -lpthread

build/use_exit: use_exit.c
	gcc -Wall -o build/use_exit use_exit.c -lpthread

build/onethread: multi_matrix/onethread.c
	gcc -Wall -o build/onethread multi_matrix/onethread.c -lpthread

build/nthreads: multi_matrix/twothreads.c
	gcc -Wall -o build/nthreads multi_matrix/twothreads.c -lpthread

build/use_join:
	gcc -Wall -o build/use_join use_join.c -lpthread

clean: 
	rm -R build/
