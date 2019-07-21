#include "shm1.h"

int main(void) { 

    FILE* fp_fifo;
    int* sharedPtr;
    int shmid;
    pid_t childPid;
  
    // shmget returns an identifier in shmid 
    if((shmid = shmget(KEY,1024,0666|IPC_CREAT)) == -1){
        perror("shmid");
        exit(1);
    }
  
    // shmat to attach to shared memory 
    if ((sharedPtr = shmat(shmid, 0, 0)) == (int*) -1){
      perror("shmat");
      exit (0);
    }
    
    // fork 1000 processes
    for(int i = 0; i < 1000; i++){
        childPid = fork();
        switch(childPid){
            case -1:
                perror("fork");
                exit(1);
            case 0:
                // increase sharedPtr 10000 times per child
                for(int j = 0; j < 10000; j++){
                    // increase value of pointer
                    (*sharedPtr)++;
                }
                exit(0);
        }
    }

    // wait for all children to exit
    for(int i = 0; i < 1000; i++){
        wait(NULL);
    }

    // print to stdout
    if(fprintf(stdout, "Send result to Fifo: %d\n", *sharedPtr) == -1){
        perror("fprintf");
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
      
    // detach from shared memory  
    if(shmdt(sharedPtr) == -1){
        perror("shmdt");
        exit(1);
    }
     
    exit(0);
} 
