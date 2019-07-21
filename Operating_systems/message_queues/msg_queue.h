#ifndef HEADER_H
#define HEADER_H

#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 77

struct message_buf {
    long msg_type;
    char msg_text[256];
} message_buf;

#endif