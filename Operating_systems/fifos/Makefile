CFLAGS = -std=gnu11 -pthread -Wall -Werror -Wextra -g
LDFLAGS = -pthread

.PHONY: all clean

all: loggin
clean:
	$(RM) loggin
	
loggin: loggin.c
	$(CC) $(CFLAGS) $^ -o $@