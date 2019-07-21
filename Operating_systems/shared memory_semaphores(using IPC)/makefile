CFLAGS = -std=gnu99 -Wall -Werror -Wextra

.PHONY: all clean

all: shm2_reader shm2_writer 

clean:
	$(RM) shm2_reader shm2_writer 

shm1_reader: shm2_reader.c  shm2.h

shm2_writer: shm2_writer.c shm2.h
