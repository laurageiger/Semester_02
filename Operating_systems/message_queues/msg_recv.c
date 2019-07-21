#include "msg_queue.h"

bool running = true;

void intHandler(){
	running = false;
}

void web(){
	srand(time(NULL)+3); // for pseudo random numbers
    int msgqid, msgflg = IPC_CREAT | 0666; // read and write access for server
	int cntr = 1;

    key_t key = ftok("progfile", KEY); // unique key

    msgqid = msgget(key, msgflg);
    message_buf.msg_type = 1;


    while(true){
        int seconds = rand() % 6 + 2; // random number between 2 and 7
        sleep(seconds);
       	sprintf(message_buf.msg_text, "[web]: %d message", cntr);
		if(msgsnd(msgqid, &message_buf, sizeof(message_buf), IPC_NOWAIT) == -1){ // IPC_NOWAIT if message queue full, message not written to queue
            perror("msgsend web");
            exit(EXIT_FAILURE);
        }
		cntr++;
    }
}

void middleware(){
	srand(time(NULL)+1); // for pseudo random numbers
    int msgqid, msgflg = IPC_CREAT | 0666; // read and write access for server
	int cntr = 1;

    key_t key = ftok("progfile", KEY); // unique key

    msgqid = msgget(key, msgflg);
    message_buf.msg_type = 2;


    while(true){
        int seconds = rand() % 6 + 2; // random number between 2 and 7
        sleep(seconds);
        sprintf(message_buf.msg_text, "[middle-ware]: %d message", cntr);
		if(msgsnd(msgqid, &message_buf, sizeof(message_buf), IPC_NOWAIT) == -1){ // IPC_NOWAIT if message queue full, message not written to queue
            perror("msgsend middleware");
            exit(EXIT_FAILURE);
        }
		cntr++;
    }
}

void database(){
	srand(time(NULL)+2); // for pseudo random numbers
    int msgqid, msgflg = IPC_CREAT | 0666; // read and write access for server
	int cntr = 1;

    key_t key = ftok("progfile", KEY); // unique key

    if((msgqid = msgget(key, msgflg)) == -1) { // create message queue
        perror("msgget database");
        exit(EXIT_FAILURE);
    }
    message_buf.msg_type = 3;


    while(true){
        int seconds = rand() % 6 + 2; // random number between 2 and 7
        sleep(seconds);
        sprintf(message_buf.msg_text, "[database]: %d message", cntr);
		if(msgsnd(msgqid, &message_buf, sizeof(message_buf), IPC_NOWAIT) == -1){ // IPC_NOWAIT if message queue full, message not written to queue
            perror("msgsend database");
            exit(EXIT_FAILURE);
        }
		cntr++;
    }
}

void server(){
	struct sigaction sig;
	sig.sa_handler = intHandler;
	sigaction(SIGINT, &sig, NULL);
	int msgflg = 0666;

	
	key_t key = ftok("progfile", KEY); 
	int msgqid = msgget(key, msgflg);

	while(running){
		if(msgrcv(msgqid, &message_buf, sizeof(message_buf), 0, 0) == -1){
			perror("cannot receive message");
			exit(EXIT_FAILURE);
		}
		printf("%s\n", message_buf.msg_text);
	}
	
	// remove message queue
	if(msgctl(msgqid, IPC_RMID, NULL) == -1){ 
		perror("msgctl database");
		exit(EXIT_FAILURE);
	}


}

int main(void) {
	int msgqid;
	
	key_t key = ftok("progfile", KEY); 
	
	if((msgqid= msgget(key, 0666 | IPC_CREAT)) == -1){
        fprintf(stderr, "error creating message queue\n");
    }
	
	pid_t pid[3];
    switch(pid[0] = fork()) {
        case -1: perror("fork error"); break;
        case 0: 
            switch (pid[1] = fork()) {
                case -1: perror("fork error"); break;
                case 0:
                    switch (pid[2] = fork()) {
                        case -1: perror("fork error"); break;
                        case 0: web(); break;
                        default: middleware(); break;
                    }
                default: database(); break; 
            }
        default: server(); break;
    }

	return EXIT_SUCCESS;
}