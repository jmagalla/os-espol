all: init mutex producer prod_wcond

init: 
	mkdir -p build

mutex: use_mutex.c
	gcc -o build/mutex use_mutex.c -lpthread

producer: prod_no_cond.c
	gcc -o build/producer prod_no_cond.c -lpthread

prod_wcond: prod_condition.c
	gcc -o build/prod_wcond prod_condition.c -lpthread

clean:
	rm build/*
