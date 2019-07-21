#ifndef TASK1_H
#define TASK1_H

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
pthread_spinlock_t spinlock;

#endif
