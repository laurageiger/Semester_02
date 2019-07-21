CFLAGS = -std=gnu11 -pthread -Wall -Werror -Wextra -g
LDFLAGS = -pthread

.PHONY: all clean

all: msg_recv
clean:
	$(RM) msg_recv
	
msg_recv: msg_recv.c
	$(CC) $(CFLAGS) $^ -o $@