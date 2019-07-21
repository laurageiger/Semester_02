CC=gcc
CFLAGS= -std=gnu99 -Wall -Werror -Wextra
LDLIBS = -lpthread -lrt

.PHONY: all clean
all: shm4_reader shm4_writer

shm4_reader: shm4_reader.o shm4.h
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

shm4_writer: shm4_writer.o shm4.h
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

clean:
	rm -f *.o shm4_reader shm4_writer
