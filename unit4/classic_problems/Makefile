all: init philospher

init: 
	mkdir -p build

philospher: philospher.c
	gcc -o build/philospher philospher.c -lpthread

clean:
	rm build/*
