#include "shm1.h"

int main(void) { 

    FILE* fp_fifo;
    int* sharedPtr = NULL;
    int buf = 0;
    int shmid;
    
    // create shared memory segment
    if((shmid = shmget(KEY,1024,0666|IPC_CREAT)) == -1){
        perror("shmid");
        exit(1);
    }
  
    // shmat to attach to shared memory 
    if ((sharedPtr = shmat(shmid, NULL, 0)) == (int*) -1){
      perror("shmat");
      exit (0);
    }
    
    // print to stdout
    if(fprintf(stdout, "Integer in shared memory: %d\n", *sharedPtr) == -1){
        perror("fprintf");
        exit(1);
    }

    // create fifo
    if (mkfifo("RESULT_FIFO", 0777) == -1) {
        perror("mkfifo"); 
        exit(1);
    }
    // open fifo - read
    if((fp_fifo = fopen("RESULT_FIFO", "r")) == NULL){
        perror("fopen");
        exit(1);
    }

    // read from fifo
    if(fscanf(fp_fifo, "%d", &buf) == -1){
        perror("fscanf");
        exit(1);
    }

    // print to stdout
    if(fprintf(stdout, "Result from Fifo: %d\n", buf) == -1){
        perror("fprintf");
        exit(1);
    }

    // close fifo
    if(fclose(fp_fifo) == EOF) {
        perror("fclose");
        exit(1);
    }

    // delete fifo file
    if(unlink("RESULT_FIFO") == -1){
        perror("unlink");
        exit(1);
    }

    // detach from shared memory  
    if(shmdt(sharedPtr) == -1){
        perror("shmdt");
        exit(1);
    }

    // destroy segment
    if(shmctl(shmid, IPC_RMID, NULL) == -1){
        perror("shmctl");
        exit(1);
    }
  
    exit(0); 
} 
