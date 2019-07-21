#include "shm2.h"

int main(void) { 

    FILE* fp_fifo;
    int* sharedPtr;
    int shmid, semid;
    pid_t childPid;

    // allocate shared memory segment
    if((shmid = shmget(SHMKEY,1024,0666|IPC_CREAT)) == -1){
        perror("shmid");
        exit(1);
    }
    // get semaphore set identifier
    if((semid = semget(SEMKEY, 1, 0666|IPC_CREAT)) == -1){
        perror("semget");
        exit(1);
    }
  
    // initialize semaphore
    union semun arg;
    arg.val = 1;
    if(semctl(semid, 0, SETVAL, arg ) == -1) {
        perror("semctl SETVAL");
        exit(1);
    }

    // reset semaphore semp - for decrementing semaphore
    struct sembuf semp[1];
    semp[0].sem_num = 0;
    semp[0].sem_flg = 0;
    semp[0].sem_op = -1;

    // reset semaphore semv - for incrementing semaphore
    struct sembuf semv[1];
    semv[0].sem_num = 0;
    semv[0].sem_flg = 0;
    semv[0].sem_op = +1;

    
    if(semop(semid, semp, 1) == -1){
        perror("semop semp");
        exit(1);
    }
  
    // shmat to attach to shared memory 
    if ((sharedPtr = shmat(shmid, 0, 0)) == (void*) -1) { // attach shm segment
        perror("shmat");
        exit(1);
    }

    if(semop(semid, semv, 1) == -1){
        perror("semop semv");
        exit(1);
    }
    
    // fork 1000 processes
    for(int i = 0; i < 1000; i++){
        childPid = fork();
        switch(childPid){
            case -1:
                perror("fork");
                exit(1);
            case 0:
                if(semop(semid, semp, 1) == -1){
                    perror("semop semp");
                    exit(1);
                } 
                // increase sharedPtr 10000 times per child
                for(int j = 0; j < 10000; j++){
                      
                    // increase value of pointer
                    (*sharedPtr)++;
                }
                if(semop(semid, semv, 1) == -1){
                    perror("semop semv");
                    exit(1);
                }

                exit(0);
        }
    }
    // wait for all children to exit
    for(int i = 0; i < 1000; i++){
        wait(NULL);
    }

    if(semop(semid, semp, 1) == -1){
        perror("semop semp");
        exit(1);
    }
    
    // print to stdout
    if(fprintf(stdout, "Send result to Fifo: %d\n", *sharedPtr) == -1){
        perror("fprintf");
        exit(1);
    }
    if(semop(semid, semv, 1) == -1){
        perror("semop semv");
        exit(1);
    }
    
    // open fifo - write
    if((fp_fifo = fopen("RESULT_FIFO", "w")) == NULL){
        perror("fopen");
        exit(1);    
    }  

    // write to fifo
    if(fprintf(fp_fifo, "%d", *sharedPtr) == -1){
        perror("fprintf");
        exit(1);
    }

    // close fifo
    if (fclose(fp_fifo) == EOF ){
        perror("fclose");
        exit(1);
    }
      
    /// detach from shared memory  
    if(shmdt(sharedPtr) == -1){
        perror("shmdt");
        exit(1);
    }
     
    return EXIT_SUCCESS;
} 
