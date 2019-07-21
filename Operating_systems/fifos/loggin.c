#include "header.h"

bool running = true;

void intHandler(){ // handler for sigint
	running = false;
}

void web(){
	srand(time(NULL)); // for pseudo random numbers
    int web;
	int cntr = 1;
	char message[256];

    web = open(WEB_SERVER, O_WRONLY); // opens file (pathname) and write only
	

    while(true){
        int seconds = rand() % 5 + 2; // random number between 2 and 7
        sleep(seconds);
		sprintf(message, "[web]: message %d\n", cntr);
        if(write(web, message, strlen(message) + 1) == -1) {
		    perror("write database");
		    exit(EXIT_FAILURE);
	    }
		cntr++;
    }
}

void middleware(){
	srand(time(NULL)); // for pseudo random numbers
    int middleware;
	int cntr = 1;
	char message[256];

    middleware = open(MIDDLEWARE_SERVER, O_WRONLY); // opens file (pathname) and write only


    while(true){
        int seconds = rand() % 5 + 2; // random number between 2 and 7
        sleep(seconds);
		sprintf(message, "[middleware]: message %d\n", cntr);
        if(write(middleware, message, strlen(message) + 1) == -1) {
		    perror("write database");
		    exit(EXIT_FAILURE);
	    }
		cntr++;
    }
}

void database(){
	srand(time(NULL)); // for pseudo random numbers
    int database;
	int cntr = 1;
	char message[256];

    database = open(DATABASE_SERVER, O_WRONLY); // opens file (pathname) and write only


    while(true){
        int seconds = rand() % 6 + 2; // random number between 2 and 7
        sleep(seconds);
		sprintf(message, "[database]: message %d\n", cntr);
        if(write(database, message, strlen(message) + 1) == -1) {
		    perror("write database");
		    exit(EXIT_FAILURE);
	    }
		cntr++;
    }
}

void server(){
	struct sigaction sig;
	sig.sa_handler = intHandler;
	sigaction(SIGINT, &sig, NULL);

	int database, middleware, web;
	
	database = open(DATABASE_SERVER, O_RDONLY); // opens file and read only
	
	if(database == -1) {
		perror("open database");
		exit(EXIT_FAILURE);
	}
	
	middleware = open(MIDDLEWARE_SERVER, O_RDONLY);
	
	if(middleware == -1) {
		perror("open database");
		exit(EXIT_FAILURE);
	}
	
	web = open(WEB_SERVER, O_RDONLY);
	
	if(web == -1) {
		perror("open database");
		exit(EXIT_FAILURE);
	}
	
	char buff[PIPE_BUF];
	fd_set set;
	int maxfd;

	while(running) {
		//clear set
		FD_ZERO(&set);
		//add sets
		FD_SET(database, &set);
		FD_SET(middleware, &set);
		FD_SET(web, &set);
	
		maxfd = database;
		if(maxfd < middleware)
			maxfd = middleware;
		if(maxfd < web)
			maxfd = web;
			
		// selecting next one (nothing to write, no exceptions, no timeout)
		select(maxfd + 1, &set, NULL, NULL, NULL);
	
		if(FD_ISSET(database, &set)){ // tests if file descriptor is part of the set
			if(read(database, buff, sizeof(buff)) > 0){
				printf("%s", buff);
			}
		}
		if(FD_ISSET(middleware, &set)){
			if(read(middleware, buff, sizeof(buff)) > 0){
				printf("%s", buff);
			}
		}
		if(FD_ISSET(web, &set)){
			if(read(web, buff, sizeof(buff)) > 0){
				printf("%s", buff);
			}
		}
		
		
	}

	if(close(database)) { // closing databse FIFO
		perror("close database");
		exit(EXIT_FAILURE);
	}

    if(remove(DATABASE_SERVER) == -1) { // deleting DatabaseServer file
		perror("unlink database");
		exit(EXIT_FAILURE);
	}

	if(close(web)) { // closing web FIFO
		perror("close database");
		exit(EXIT_FAILURE);
	}

    if(unlink(WEB_SERVER) == -1) { // deleting WebServer file
		perror("unlink database");
		exit(EXIT_FAILURE);
	}

	if(close(middleware)) { // closing middleware FIFO
		perror("close database");
		exit(EXIT_FAILURE);
	}

    if(unlink(MIDDLEWARE_SERVER) == -1) { // deleting MiddlewareServer file
		perror("unlink database");
		exit(EXIT_FAILURE);
	}
}


int main(void) {
	if(mkfifo(DATABASE_SERVER, O_CREAT | 0666) == -1) { // make FIFO, pathname and mode
		perror("mkfifo database");
		exit(EXIT_FAILURE);
	}

	if(mkfifo(MIDDLEWARE_SERVER, O_CREAT | 0666) == -1) { // make FIFO, pathname and mode
		perror("mkfifo database");
		exit(EXIT_FAILURE);
	}

	if(mkfifo(WEB_SERVER, O_CREAT | 0666) == -1) { // make FIFO, pathname and mode
		perror("mkfifo database"); 
		exit(EXIT_FAILURE);
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
                        case 0: middleware(); break;
                        default: web(); break;
                    }
                default: database(); break; 
            }
        default: server(); break;
    }


	return EXIT_SUCCESS;
}