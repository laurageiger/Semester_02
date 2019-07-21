#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void){

    int childPid;

    printf("I'm the parent with the pid [%d].\n", getpid());

    for(int i = 0; i < 12; i++){
        childPid = fork();
        switch(childPid){
            case -1:
                perror("fork");
                exit(1);
            case 0:
                printf("I'm a child with the pid [%d]. My parent is [%d]\n", getpid(), getppid());
                exit(0);
        }

    }

    for(int i = 0; i < 12; i++){
        wait(NULL);
    }

    printf("12 child processes have been created.\n");

    /*
    output is not consistent and cannot be predicted
    because it depends on the scheduling
    of the processes
    */

    return EXIT_SUCCESS;
}