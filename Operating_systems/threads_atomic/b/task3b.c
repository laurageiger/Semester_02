#include "task3b.h"

void* threadHandler(void* x){

    for(int i = 0; i < 10000; i++){
        atomic_fetch_add((int*)x, 1);
    }     

    // exit thread
    pthread_exit(NULL);
}

int main(void) { 
    int x = 0; 
    pthread_t tid[THREADS_NUM];

    fprintf(stdout, "Variable x before incrementing: %d\n", x);

    // create 5 threads
    fprintf(stdout, "Create 1000 threads ...\n");
    for(int i = 0; i < THREADS_NUM; i++){
        pthread_create(&(tid[i]), NULL, threadHandler, &x);
    }
    fprintf(stdout, "done\n");



    // wait for all threads
    fprintf(stdout, "Wait for all threads ... \n");
    for(int i = 0; i < THREADS_NUM; i++){
        pthread_join(tid[i], NULL);
    }
    fprintf(stdout, "done\n");

    fprintf(stdout, "Variable x after incrementing: %d\n", x);

    exit(0); 
} 
