
CFLAGS += -g -Wall -liptc -lip4tc


all: ipt

ipt: ipt.o
	$(CC) $(CFLAGS) -o ipt ipt.o

ipt.o: ipt.c
	$(CC) $(CFLAGS) -c -o ipt.o ipt.c

clean:
	rm -f *.o ipt
