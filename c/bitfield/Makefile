
CFLAGS += -Wall -Werror -g

LDFLAGS +=

OBJECTS = bitfield.o


all: bitfield

bitfield: $(OBJECTS)
	$(CC) -o bitfield $(OBJECTS) $(LDFLAGS)

.SUFFIXES:
.SUFFIXES: .c .o

.c.o:
	$(CC) -o $@ -c $(CFLAGS) $<

clean:
	rm -f *.o bitfield

.PHONY: all
.PHONY: clean
