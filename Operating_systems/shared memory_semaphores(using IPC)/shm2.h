#ifndef SHM2_H
#define SHM2_H

#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h> // fork
#include <sys/shm.h> // shared memory
#include <sys/stat.h> // mkfifo
#include <wait.h>
#include <errno.h> // error handling
#include <sys/sem.h> // semaphore

#define SHMKEY 2345
#define SEMKEY 6789

union semun { /* semun struct for manipulating sem */

	int              val;    /* Value for SETVAL */
	struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
	unsigned short  *array;  /* Array for GETALL, SETALL */
	struct seminfo  *__buf;  /* Buffer for IPC_INFO */
};

#endif
