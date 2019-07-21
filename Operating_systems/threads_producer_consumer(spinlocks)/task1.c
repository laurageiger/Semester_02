#include "task1.h"

void* threadHandler(void* counter){
    int sum = 0, get;
    
    while(1){
        pthread_spin_lock(&spinlock);
        if(!empty()){
            get = front();
            pop();
            if(get == 1){
                sum += 1;
            }
            // unlock if get == 0
            else {
                pthread_spin_unlock(&spinlock);
                break;
            }
        }
        // unlock if queue is empty
        pthread_spin_unlock(&spinlock);
    }
    // print to stdout
    fprintf(stdout, "The sum of thread%d is %d\n", *((int*)counter), sum);

    // exit thread
    pthread_exit(NULL);
}

int main(int argc, char** argv) { 

    pthread_t tid[THREADS_NUM];
    int counter[THREADS_NUM];
    srand(time(NULL));
    pthread_spin_init(&spinlock, 0);

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
        pthread_spin_lock(&spinlock);
        push(1);
        pthread_spin_unlock(&spinlock);
    }
    for(int i = 0; i < 5; i++){
        pthread_spin_lock(&spinlock);
        push(0);
        pthread_spin_unlock(&spinlock);
    }
    fprintf(stdout, "done\n");

    // wait for all threads
    fprintf(stdout, "Wait for all threads ... \n");
    for(int i = 0; i < THREADS_NUM; i++){
        pthread_join(tid[i], NULL);
    }
    fprintf(stdout, "done\n");

    // destroy mutex object
    pthread_spin_destroy(&spinlock);
    exit(0); 
} 
