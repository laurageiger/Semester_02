CC=gcc
CFLAGS= -std=gnu99 -Wall -Werror -Wextra
LDLIBS = -lpthread -lrt

.PHONY: all clean
all: task3b

task3: task3b.o task3b.h
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

clean:
	rm -f *.o task3b
