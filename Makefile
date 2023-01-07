CC = gcc
CFLAGS = -Wall -g

all: insertionSort searchInText

searchInText: searchInText.o
	$(CC) $(CFLAGS) -o txtfind searchInText.o

searchInText.o: searchInText.c
	$(CC) $(CFLAGS) -c searchInText.c

insertionSort: insertionSort.o
	$(CC) $(CFLAGS) -o isort insertionSort.o

insertionSort.o: insertionSort.c
	$(CC) $(CFLAGS) -c insertionSort.c

.PHONY: clean all

clean:
	rm txtfind isort *.o