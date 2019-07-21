#ifndef SHM1_H
#define SHM1_H

#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h> // fork
#include <sys/shm.h> // shared memory
#include <sys/stat.h> // mkfifo
#include <wait.h>
#include <errno.h> // error handling

#define KEY 2345

#endif
