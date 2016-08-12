
CFLAGS += -Wall


all: sig

sig: sig.o
	$(CC) $(CFLAGS) -o sig sig.o

sig.o: sig.c
	$(CC) $(CFLAGS) -c -o sig.o sig.c

clean:
	rm -f *.o sig
