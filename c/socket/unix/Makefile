
CFLAGS += -Wall


all: usockd

usockd: usockd.o
	$(CC) $(CFLAGS) -o usockd usockd.o

usockd.o: usockd.c
	$(CC) $(CFLAGS) -c -o usockd.o usockd.c

clean:
	rm -f *.o usockd
