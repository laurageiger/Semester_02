#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

static sigset_t signalmask;
pid_t childPid;

void handler1(int signal){
	if(signal == SIGALRM){
		kill(childPid, SIGUSR1);
	}
	else if(signal == SIGCHLD){
		exit(0);
	}
}


void handler2(int signal){
	if(signal == SIGUSR2){	
		exit(0);
	}
	else if(signal == SIGUSR1){
		printf("Output String\n");
	}
	else if(signal == SIGALRM){
		sigprocmask(SIG_UNBLOCK, &signalmask, NULL);
	}
}

int main(void){

    struct sigaction signal1;
    struct sigaction signal2;

	signal1.sa_handler = &handler1;
	signal2.sa_handler = &handler2;

	
	sigemptyset(&signalmask);
	sigaddset(&signalmask, SIGUSR2);
	
	pid_t pid = fork();

	if(pid > 0){
		sleep(5);
		childPid = pid;
		printf("ChildPid: %d\n", childPid);

		kill(childPid, SIGUSR2);
		sigaction(SIGALRM, &signal1, NULL);
		sigaction(SIGCHLD, &signal1, NULL);
		while(1){
			alarm(5);
			pause();
		}
	}
	else if (pid == 0){
		sigprocmask(SIG_BLOCK, &signalmask, NULL);
		alarm(13);
        sigaction(SIGALRM, &signal2, NULL);
		while(1){
			sigaction(SIGUSR2, &signal2, NULL);
			sigaction(SIGUSR1, &signal2, NULL);
		}

	}
	else{
		perror("fork");
		exit(1);
	}

	return EXIT_SUCCESS;
}
