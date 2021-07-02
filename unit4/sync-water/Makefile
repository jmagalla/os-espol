all: init build/water-sync

init: 
	mkdir -p build

build/water-sync: main.c
	gcc -o build/water-sync main.c -lpthread

clean:
	rm build/*
	