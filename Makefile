ifeq ($(DEBUG), true)
        CC = gcc -g
else
        CC = gcc
endif

all: main.o node.o
	$(CC) -o myTunes.out main.o node.o

main.o: main.c node.h
	$(CC) -c main.c

node.o: node.c node.h
	$(CC) -c node.c node.h

memtest:
	valgrind --leak-check=true ./myTunes.out

run:
	./myTunes.out

clean:
	rm *.o
	rm ./myTunes.out
