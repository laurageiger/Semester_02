#include "task2.h"

int global_sum = 0;

void* threadHandler(void* counter){
    int sum = 0, get;
    
    while(1){
        // one thread per time
        pthread_mutex_lock(&lock);
        if(!empty()){
            get = front();
            pop();
            if(get == 1){
                sum += 1;
            }
            // unlock if get == 0
            else {
                pthread_mutex_unlock(&lock);
                break;
            }
        }
        // unlock if queue is empty
        pthread_mutex_unlock(&lock);
    }
    // print to stdout
    fprintf(stdout, "The sum of thread%d is %d\n", *((int*)counter), sum);
    global_sum += sum;
    // exit thread
    pthread_exit(NULL);
}

int main(void) { 

    pthread_t tid[THREADS_NUM];
    int counter[THREADS_NUM];
    srand(time(NULL));
    
    // create queue 
    create();

    // create 5 threads
    fprintf(stdout, "Create 5 consumers ...\n");
    for(int i = 0; i < THREADS_NUM; i++){
        counter[i] = i;
        pthread_create(&(tid[i]), NULL, threadHandler, (void*)&counter[i]);
    }
    fprintf(stdout, "done\n");

    fprintf(stdout, "Fill queue ... \n");
    for(int i = 0; i < ENTRIES; i++){
        pthread_mutex_lock(&lock);
        push(1);
        pthread_mutex_unlock(&lock);
    }
    for(int i = 0; i < 5; i++){
        pthread_mutex_lock(&lock);
        push(0);
        pthread_mutex_unlock(&lock);
    }
    fprintf(stdout, "done\n");

    // wait for all threads
    fprintf(stdout, "Wait for all threads ... \n");
    for(int i = 0; i < THREADS_NUM; i++){
        pthread_join(tid[i], NULL);
    }
    fprintf(stdout, "done\n");

    fprintf(stdout, "total sum: %d\n", global_sum);
    // destroy mutex object
    pthread_mutex_destroy(&lock);
    exit(0); 
} 
