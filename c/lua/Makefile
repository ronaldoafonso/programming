
CFLAGS += -Wall
LDFLAGS += -llua5.1

all: lua

lua: lua.o
	$(CC) $(LDFLAGS) lua.o -o lua

lua.o: lua.c
	$(CC) $(CFLAGS) -c lua.c -o lua.o

clean:
	rm -f *.o lua
