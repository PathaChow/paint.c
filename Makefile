paint.out: finalCopy1.o
	gcc -g -Wall -Werror -o paint.out finalCopy1.o

finalCopy1.o: finalCopy1.c input1.h
	gcc -g -Wall -Werror -c -o finalCopy1.o finalCopy1.c

clean:
	rm -f *.o *.out
