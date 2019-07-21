#include "shm2.h"

int main(void) { 

    FILE* fp_fifo;
    int* sharedPtr = NULL;
    int buf, shmid, semid;
    
    // create shared memory segment
    if((shmid = shmget(SHMKEY,1024,0666|IPC_CREAT)) == -1){
        perror("shmid");
        exit(1);
    }
    // create semaphore
    if((semid = semget(SEMKEY, 1, 0666|IPC_CREAT)) == -1){
        perror("semget");
        exit(1);
    }

    union semun arg;
    arg.val = 1;
    if(semctl(semid, 0, SETVAL, arg ) == -1) {
        perror("semctl SETVAL failed");
        exit(EXIT_FAILURE);
    }

    struct sembuf semp[1];
    semp[0].sem_num = 0;
    semp[0].sem_flg = 0;
    semp[0].sem_op = -1;

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
    if(fclose(fp_fifo) == EOF ) {
        perror("fclose");
        exit(1);
    }

    // delete file
    if (unlink("RESULT_FIFO") == -1){ // delete file
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

    if(semctl(semid, 0, IPC_RMID, arg) == -1){
        perror("semctl");
        exit(1);
    }
    
  
    return EXIT_SUCCESS; 
} 
