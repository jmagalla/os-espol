all: init ercallfunc erdivbyzero exitwerror

init:
	mkdir -p build

ercallfunc: callfunc.c 
	 gcc -o build/ercallfunc callfunc.c

erdivbyzero: divbyzero.c 
	 gcc -o build/erdivbyzero divbyzero.c

exitwerror: exitwerror.c 
	 gcc -o build/exitwerror exitwerror.c

clean:
	 rm build/*
