#ifndef SHM4_H
#define SHM4_H

#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h> // fork
#include <sys/shm.h> // shared memory
#include <sys/stat.h> // mkfifo
#include <wait.h>
#include <errno.h> // error handling

#include <fcntl.h> // O_RDONLY, O_WRONLY
#include <sys/sem.h>
#include <semaphore.h>
#include <sys/mman.h>

#define NAMESHM "shm"
#define NAMESEM "sem"

#endif
