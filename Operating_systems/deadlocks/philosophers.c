#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <pthread.h>
#include <unistd.h>

#define EAT_DURATION 500
#define NUM_PHILOSOPHER 5
#define EAT_ITERATIONS 1000
#define RIGHT_CHOPSTICK(n) (n)
#define LEFT_CHOPSTICK(n) (((n) + 1) % NUM_PHILOSOPHER)

pthread_t philosopher[NUM_PHILOSOPHER];
pthread_mutex_t chopstick[NUM_PHILOSOPHER];

/*
The programm creates five threads(philosophers) and five mutexes(chopsticks), the problem is that every thread
needs a left and a right chopstick but if every thread tries to lock the right chopstick at the same time then 
a deadlock occurs and the threads will starve.

A deadlock is a state in which each member of a group is waiting for another member, including itself, to take 
action, such as sending a message or more commonly releasing a lock. - Wikipedia

As ever thread takes the right chopstick and none hands it back every chopstick is taken and every thread waits
for the left chopstick. When executing the original code worked for some few cases, but most of the time a 
deadlock occured.
*/

void *dine(void *id) {
    int n = (int)(intptr_t) id;
    for (int i = 0; i < EAT_ITERATIONS; ++i) {
        /* 
        while loop for waiting for left and 
        right chopstick to be free
        */
        while(pthread_mutex_lock(&chopstick[RIGHT_CHOPSTICK(n)]) == -1 && pthread_mutex_lock(&chopstick[LEFT_CHOPSTICK(n)]) == -1){}
        usleep(EAT_DURATION);
        pthread_mutex_unlock(&chopstick[LEFT_CHOPSTICK(n)]);
        pthread_mutex_unlock(&chopstick[RIGHT_CHOPSTICK(n)]);
    }
    printf("Philosopher %d is done eating!\n", n);

    return (NULL);
}

int main() {

    for (int i = 0; i < NUM_PHILOSOPHER; ++i) {
        pthread_mutex_init(&chopstick[i], NULL);
    }

    for (int i = 0; i < NUM_PHILOSOPHER; ++i) {
        pthread_create(&philosopher[i], NULL, dine, (void *) (intptr_t) i);
    }

    for (int i = 0; i < NUM_PHILOSOPHER; ++i) {
        pthread_join(philosopher[i], NULL);
    }

    for (int i = 0; i < NUM_PHILOSOPHER; ++i) {
        pthread_mutex_destroy(&chopstick[i]);
    }

    return EXIT_SUCCESS;
}