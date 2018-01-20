#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main() {
	int pid;
	pid=fork();
	if(pid<0)
		printf("Fork failed\n");
	else if(pid==0)
		execlp("/bin/ls","ls",NULL);
	else {
		wait(NULL);
		printf("In parent process\n");
	}
}