GCC = gcc
CFLAGS = -Wall -Wshadow
OBJS = ex5.o bmp.o

ex5: $(OBJS)
	$(GCC) $(CFLAGS) $(OBJS) -o $@

.c.o: 
	$(GCC) $(CFLAGS) -c $*.c 

clean:
	rm *.o ex5

test: ex5
	./ex5 testcases/car.bmp outputs/car_out.bmp
	diff outputs/car_out.bmp testcases/car_sol.bmp
	./ex5 testcases/airplane.bmp outputs/airplane_out.bmp
	diff outputs/airplane_out.bmp testcases/airplane_sol.bmp
	./ex5 testcases/purduetrain.bmp outputs/purduetrain_out.bmp
	diff outputs/purduetrain_out.bmp testcases/purduetrain_sol.bmp
	./ex5 testcases/wizard.bmp outputs/wizard_out.bmp
	diff outputs/wizard_out.bmp testcases/wizard_sol.bmp

testmem: ex5
	valgrind --tool=memcheck --leak-check=summary ./ex5 testcases/car.bmp outputs/car_out.bmp
	valgrind --tool=memcheck --leak-check=summary ./ex5 testcases/airplane.bmp outputs/airplane_out.bmp
	valgrind --tool=memcheck --leak-check=summary ./ex5 testcases/purduetrain.bmp outputs/purduetrain_out.bmp
	valgrind --tool=memcheck --leak-check=summary ./ex5 testcases/wizard.bmp outputs/wizard_out.bmp

