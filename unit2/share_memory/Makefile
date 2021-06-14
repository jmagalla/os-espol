all: init producer consumer

init: 
	mkdir -p build

producer: 
	gcc -g -Wall -o build/producer producer.c -lrt

consumer:
	gcc -g -Wall -o build/consumer consumer.c -lrt
     
clean:
	 rm build/*
