#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]) {

	int pfd[2];
	pid_t pid;

	if(pipe(pfd) == -1){ // create pipe
		perror("pipe");
	}

	switch(pid = fork()) {
		case -1:
			perror("fork"); 
			break;

		case 0: // child ls
			if(close(pfd[0]) == -1){
				perror("close read child");
			}
			if(dup2(pfd[1], STDOUT_FILENO) == -1){ // duplicate file descriptor
				perror("dup2 child");
			} 
			if(close(pfd[1]) == -1){
				perror("close write child");
			}  
			if(execl("/bin/ls", "ls", NULL) == -1){ // execute ls
				perror("execvp ls");
			} 
			exit(0);
			break;
	
		default: //parent grep
			wait(NULL); // wait for child
			if(close(pfd[1]) == -1){
				perror("close write parent");
			}
			if(dup2(pfd[0], STDIN_FILENO) == -1){
				perror("dup2 parent");
			} 
			if(close(pfd[0]) == -1){
				perror("close read parent");
			} 
			if(execl("/bin/grep", "grep", argv[1], NULL) == -1){ // execute grep
				perror("execl grep");
			} 
			break;
	}
    return EXIT_SUCCESS;

}