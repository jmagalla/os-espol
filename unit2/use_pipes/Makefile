all: init simplepipe pipewfork

init: 
	mkdir -p build

simplepipe: 
	gcc -o build/simplepipe simplepipe.c

pipewfork: 
	gcc -o build/pipewfork pipewfork.c

clean:
	 rm build/*
