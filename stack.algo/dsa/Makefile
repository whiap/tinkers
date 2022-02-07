all: test_qsort test_stackli
.PHONY: all clean

CFLAG = -g -Wall -Wextra

test_qsort: test_qsort.o
	gcc $(CFLAGS) -o test_qsort test_qsort.o
test_qsort.o: test_qsort.c
	gcc $(CFLAGS) -c test_qsort.c
test_stackli: test_stackli.o stackli.o
	gcc $(CFLAGS) -o test_stackli test_stackli.o stackli.o
test_stackli.o: test_stackli.c
	gcc $(CFLAGS) -c test_stackli.c

stackli.o: stackli.c fatal.h
	gcc $(CFLAGS) -c stackli.c fatal.h

clean:
	rm -f *.o *.gch test_stackli test_qsort


