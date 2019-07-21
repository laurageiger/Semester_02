#ifndef TASK2_H
#define TASK2_H

#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
#include <errno.h> // error handling
#include <pthread.h>
#include <time.h>
#include "myqueue.h"


#define THREADS_NUM 5
#define ENTRIES 10000
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER; 

int total = 0;

#endif
