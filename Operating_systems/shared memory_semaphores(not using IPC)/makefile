CFLAGS = -std=gnu99 -Wall -Werror -Wextra

.PHONY: all clean

all: shm1_reader shm1_writer 

clean:
	$(RM) shm1_reader shm1_writer 

shm1_reader: shm1_reader.c  shm1.h

shm2_writer: shm1_writer.c shm1.h
