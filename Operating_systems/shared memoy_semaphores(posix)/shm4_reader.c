#include "shm4.h"

int main(void) { 

    FILE* fp_fifo;
    int* sharedPtr = NULL;
    int buf, shmfd;
    sem_t* sem;
    
    // create shared memory segment
    if((shmfd = shm_open(NAMESHM, O_CREAT|O_RDWR, 0666)) == -1){
        perror("shm open");
        exit(1);
    }

    // configure size of shared memory segment
    if(ftruncate(shmfd, sizeof(int)) == -1){
        perror("ftruncate");
        exit(1);
    }

    // map shared memory to actual process
    if((sharedPtr = mmap(NULL, sizeof(int), PROT_READ|PROT_WRITE, MAP_SHARED, shmfd, 0)) == (void*)-1){
       perror("mmap error");
       exit(1); 
    }

    // initialize and open semaphore
    if((sem = sem_open(NAMESEM, O_CREAT, 0666, 1)) == SEM_FAILED){
        perror("sem open");
        exit(1);
    }
    
    // print to stdout
    if(fprintf(stdout, "Integer in shared memory: %d\n", *sharedPtr) == -1){
        perror("fprintf");
        exit(1);
    }

    // create fifo
    if (mkfifo("RESULT_FIFO", 0777) == -1){
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
    if(fclose(fp_fifo) == EOF ){
        perror("fclose");
        exit(1);
    }

    // delete file
    if (unlink("RESULT_FIFO") == -1){
        perror("unlink");
        exit(1);
    }

    // unlink shared memory object 
    if(shm_unlink(NAMESHM) == -1){
        perror("shm_unlink");
        exit(1);
    }

    if(sem_unlink(NAMESEM) == -1){
        perror("shm_unlink");
        exit(1);
    }

    exit(0);
} 
