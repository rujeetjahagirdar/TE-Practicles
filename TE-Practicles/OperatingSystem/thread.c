#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int sum;
void *runner(void *param);

void main (int argc, char *argv[]) {
	pthread_t tid;
	pthread_attr_t attr;
	if(argc!=2) {
		printf("Usage: ./a.out <integer>\n");
		return (-1);
	}
	if(atoi(argv[1])<0) {
		printf("Error integer must be >=0\n");
		return (-1);
	}
	pthread_attr_init(&attr);
	pthread_create(&tid,&attr,runner,argv[1]);
	pthread_join(tid,NULL);
	printf("Sum= %d\n",sum);
}

void *runner(void *param) {
	int i,n=atoi(param);
	sum=0;
	for(i=0;i<=n;i++)
		sum=sum+i;
	pthread_exit(0);
}