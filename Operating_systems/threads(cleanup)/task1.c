#include "task1.h"

void clean_handler(void *fp){
    if(fclose((FILE *) fp) == -1){ 
        perror("fclose");
        exit(1);
    }
}

void* threadHandler(void* counter){
    pthread_t tid = pthread_self();
    FILE* fp;
    char filename[32];

    // sleep for eiter 0, 1, 2, or 3 seconds
    sleep(rand()%4);

    /*
    // make thread not cancelable until unblocked
    if(pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL) != 0){
        perror("pthread_setcancelstate");
        exit(1);
    }
    */

    // get name
    sprintf(filename, "thread%d.txt", *((int*)counter));

    // open file
    fp = fopen(filename, "w");

    /* 
    // unblock cancelability
    if(pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL) != 0){
        perror("pthread_setcancelstate");
        exit(1);
    }
    */

     // close file when canceled
    pthread_cleanup_push(clean_handler, fp);
    
    // write into file
    fprintf(fp, "%ld\n", (long int)tid);

    // write to stdout
    fprintf(stdout, "Write into file thread%d.txt -->  %ld\n", *((int*)counter), (long int)tid);
   
    // close file, 1 for executing function
    pthread_cleanup_pop(1);

    // exit thread
    pthread_exit(NULL);
}

int main(void) { 

    pthread_t tid[THREADS_NUM];
    int counter[THREADS_NUM];
    srand(time(NULL));

    // creating threads
    fprintf(stdout, "Create 10 threads ...\n");
    for(int i = 0; i < THREADS_NUM; i++){
        counter[i] = i;
        if((pthread_create(&(tid[i]), NULL, threadHandler, (void*)&counter[i])) == -1){
            perror("pthread create\n");
            exit(1);
        }
        
    }
    fprintf(stdout, "done\n");

    // cancel thread with chance of cancellation of 50%
    fprintf(stdout, "Cancel some threads ... \n");
    for(int i = 0; i < THREADS_NUM; i++){
        if(rand()%2){
            fprintf(stdout, "cancel thread%d \n", i);
            if(pthread_cancel(tid[i]) == -1){
                perror("pthread_cancel");
                exit(1);
            }
        }
    }
    fprintf(stdout, "done\n");

    // wait for threads
    fprintf(stdout, "Wait for all threads ... \n");
    for(int i = 0; i < THREADS_NUM; i++){
        if((pthread_join(tid[i], NULL)) == -1){
            perror("pthread join\n");
            exit(1);
        }
    }
    
    fprintf(stdout, "done\n");
    exit(0); 
} 
