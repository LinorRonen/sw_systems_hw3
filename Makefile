CC = gcc
CFLAGS = -Wall -g

.PHONY: all clean

all: isort txtfind

isort: insertionSort.o
	$(CC) $(CFLAGS) $^ -o $@

txtfind: searchInText.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o isort txtfind