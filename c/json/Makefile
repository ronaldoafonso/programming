
CFLAGS += -Wall
LDFLAGS += -ljson-c


all: json

json: json.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o json json.o

json.o: json.c
	$(CC) $(CFLAGS) -c -o json.o json.c

clean:
	rm -f *.o json
