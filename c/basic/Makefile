
CFLAGS += -Wall -Werror -g

LDFLAGS +=

OBJECTS = basic.o


all: basic

basic: $(OBJECTS)
	$(CC) -o basic $(OBJECTS) $(LDFLAGS)

.SUFFIXES:
.SUFFIXES: .c .o

.c.o:
	$(CC) -o $@ -c $(CFLAGS) $<

clean:
	rm -f *.o basic

.PHONY: all
.PHONY: clean
