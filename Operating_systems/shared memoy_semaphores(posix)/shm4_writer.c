#include "shm4.h"

int main(void) { 

    FILE* fp_fifo;
    int* sharedPtr;
    int shmfd;
    sem_t* sem;
    pid_t childPid;

    
    // shmget returns an identifier in shmfd 
    if((shmfd = shm_open(NAMESHM, O_RDWR, 0666)) == -1){
        perror("shm open");
        exit(1);
    }
  
    // map shared memory to actual processsemp
    if((sharedPtr = mmap(NULL, sizeof(int), PROT_READ|PROT_WRITE, MAP_SHARED, shmfd, 0)) == (void*)-1){
       perror("mmap error");
       exit(1); 
    }

    // open semaphore
    if((sem = sem_open(NAMESEM, O_CREAT, 0666, 1)) == SEM_FAILED){
        perror("sem open");
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
                if(sem_wait(sem) == -1){
                    perror("sem wait");
                    exit(1);
                }
                // increase sharedPtr 1000semp
                for(int j = 0; j < 10000; j++){
                    // increase value of pointer
                    (*sharedPtr)++;
                }
                if(sem_post(sem) == -1){
                    perror("sem post");
                    exit(1);
                }
                exit(0);
        }
    }
    // wait for all children to exit
    for(int i = 0; i < 1000; i++){
        wait(NULL);
    }

    if(sem_wait(sem) == -1){
        perror("sem wait");
        exit(1);
    }
    // print to stdout
    if(fprintf(stdout, "Send result to Fifo: %d\n", *sharedPtr) == -1){
        perror("fprintf");
        exit(1);
    }
    if(sem_post(sem) == -1){
        perror("sem post");
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
    
    

    exit(0);
} 
