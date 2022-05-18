//Program to demonstrate an IPC using pipe
#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#define MSGSIZE 256

char msg1[]="hello 1";
char msg2[]="hello 2";
char msg3[]="hello 3";
int prnerr(int ret, char *msg) {
	if (ret < 0) {
		perror(msg);
		exit(exit_failure);
	}
	return 0;
}
int main()
{
	char inbuf[MSGSIZE];
	int piped[2],i,ret;

	ret = pipe(piped);

	prnerr(ret,"error creating pipe");
	ret = write(piped[1],msg1,strlen(msg1));
	prnerr(ret,"unable to write msg to pipe");
	ret = write(piped[1],msg2,strlen(msg2));
	prnerr(ret,"unable to write msg to pipe");
	ret = write(piped[1],msg3,strlen(msg3));
	prnerr(ret,"unable to write msg to pipe");

	for(i = 0; i< 3; i++) {
     
		ret = read(piped[0],inbuf,MSGSIZE);
		prnerr(ret"error reading the pipe");
		cout << inbuf <<endl;
	}
	close(piped[0]);
	close(piped[1]);
	return 0;
}

