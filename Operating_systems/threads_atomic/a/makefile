CC=gcc
CFLAGS= -std=gnu99 -Wall -Werror -Wextra
LDLIBS = -lpthread -lrt

.PHONY: all clean
all: task3a

task3: task3a.o task3a.h
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

clean:
	rm -f *.o task3a
