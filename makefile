all: random.o
	gcc -o test random.o

random.o: random.c
	gcc -c random.c

run:
	./test

clean:
	rm test
	rm num.txt
	rm *.o
