
CFLAGS += -Wall -pthread


all: thread

thread: thread.o
	$(CC) $(CFLAGS) -o thread thread.o

thread.o: thread.c
	$(CC) $(CFLAGS) -c -o thread.o thread.c

clean:
	rm -f *.o thread
