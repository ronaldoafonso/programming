
CFLAGS += -Wall
LDFLAGS += -lpcap


all: tpcap

tpcap: tpcap.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o tpcap tpcap.o

tpcap.o: tpcap.c
	$(CC) $(CFLAGS) -c -o tpcap.o tpcap.c

clean:
	rm -f *.o tpcap
