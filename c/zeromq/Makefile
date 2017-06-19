
CFLAGS += -Wall -Werror -g

LDFLAGS += -lzmq

OBJECTS = push_client.o


all: push_client

push_client: $(OBJECTS)
	$(CC) -o push_client $(OBJECTS) $(LDFLAGS)

.SUFFIXES:
.SUFFIXES: .c .o

.c.o:
	$(CC) -o $@ -c $(CFLAGS) $<

clean:
	rm -f *.o push_client

.PHONY: all
.PHONY: clean
