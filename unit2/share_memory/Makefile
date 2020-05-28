all: init producer consumer

init: 
	mkdir -p build

producer: 
	gcc -o build/producer producer.c -lrt

consumer:
	gcc -o build/consumer consumer.c -lrt
     
clean:
	 rm build/*
