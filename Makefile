ifeq ($(DEBUG), true)
        CC = gcc -g
else
        CC = gcc
endif

all: main.o node.o song.o
	$(CC) -o myTunes.out main.o node.o song.o

main.o: main.c node.h
	$(CC) -c main.c

node.o: node.c node.h
	$(CC) -c node.c node.h

song.o: song.c song.h node.h
	$(CC) -c song.c song.h

memtest:
	valgrind --leak-check=yes ./myTunes.out

run:
	./myTunes.out

clean:
	rm *.o
	rm ./myTunes.out
