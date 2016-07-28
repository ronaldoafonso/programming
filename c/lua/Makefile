
CFLAGS += -Wall
LDFLAGS += -llua5.1

all: lua lmod.so

lua: lua.o
	$(CC) $(CFLAGS) $(LDFLAGS) -o lua lua.o

lua.o: lua.c
	$(CC) $(CFLAGS) -c -o lua.o lua.c

lmod.so: lmod.o
	$(CC) $(CFLAGS) -shared -o lmod.so lmod.o

lmod.o: lmod.c
	$(CC) $(CFLAGS) -fPIC -c -o lmod.o lmod.c

clean:
	rm -f *.o *.so lua
