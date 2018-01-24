#include<stdio.h>
#include<stdlib.h>

struct process {
	int pid,arrivalTime,brusTime,waiTime,turnTime,remainingTime,priority;
	char status;
};

void main() {
	int n,i,t,temp;
	int totTime=0,totTurn=0,totWait=0;
	printf("Enter the number of processes:\n");
	scanf("%d",&n);
	struct process p[n];
	

	printf("Enter the arrival time:\n");
	for(i=0;i<n;i++) {
		scanf("%d",&p[i].arrivalTime);
		p[i].pid=i+1;
		p[i].status='N';
		p[i].waiTime=0;
		p[i].turnTime=0;
	}
	

	printf("Enter the brust time:\n");
	for(i=0;i<n;i++) {
		scanf("%d",&p[i].brusTime);
		totTime=totTime+p[i].brusTime;
		p[i].remainingTime=p[i].brusTime;
	}

	
	printf("ENter priorities:\n");
	for(i=0;i<n;i++) {
		scanf("%d",&p[i].priority);
	}


	for(t=0;t<totTime;t++) {
		for(i=0;i<n;i++) {
			if(p[i].arrivalTime<=t && p[i].remainingTime>0) {
				p[i].status='R';
				temp=i;
			}
			if(p[i].remainingTime==0)
				p[i].status='E';
		}
		for(i=0;i<n;i++) {
			if(p[i].status=='R' && (p[i].priority<=p[temp].priority)) {
				if(p[i].priority==p[temp].priority) {
					if(p[i].arrivalTime<=p[temp].arrivalTime)
						temp=i;
					else
						temp=temp;
				}
				else
					temp=i;
			}
		}
		p[temp].remainingTime--;
		printf("%d ",p[temp].pid);
		for(i=0;i<n;i++) {
			if(p[i].status=='R' && i!=temp)
				p[i].waiTime++;
		}
		for(i=0;i<n;i++) {
			p[i].turnTime=p[i].brusTime+p[i].waiTime;
			totWait=totWait+p[i].waiTime;
			totTurn=totTurn+p[i].turnTime;
		}
	}

	printf("\n");
	printf("Process\tAT\tBT\tPrio\tWT\tTT\n");
	for(i=0;i<n;i++) {
		printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].arrivalTime,p[i].brusTime,p[i].priority,p[i].waiTime,p[i].turnTime);
	}
}