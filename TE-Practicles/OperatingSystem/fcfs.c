#include<stdio.h>
#include<stdlib.h>
struct process {
	int pid,arrivalTime,brusTime,startTime,turnTime,waitTime,endTime;
};

void main() {
	int n,i,j;
	int totwait=0,totturn=0;
	printf("Enter the number of processes:\n");
	scanf("%d",&n);
	struct process p[n];
	struct process temp;
	printf("Enter arrival time for processes:\n");
	for(i=0;i<n;i++) {
		scanf("%d",&p[i].arrivalTime);
		p[i].pid=i+1;
	}
	printf("Enter the brust time for processes:\n");
	for(i=0;i<n;i++) {
		scanf("%d",&p[i].brusTime);
	}

	for(i=0;i<n;i++) {
		for(j=i+1;j<n;j++) {
			if(p[j].arrivalTime<=p[i].arrivalTime) {
				if(p[j].arrivalTime==p[i].arrivalTime) {
					;
				}
				else {
					temp=p[j];
					p[j]=p[i];
					p[i]=temp;
				}
			}
		}
	}

	p[0].startTime=p[0].arrivalTime;
	p[0].endTime=p[0].startTime+p[0].brusTime;
	for(i=1;i<n;i++) {
		p[i].startTime=p[i-1].startTime+p[i-1].brusTime;
		p[i].endTime=p[i].startTime+p[i].brusTime;
	}

	for(i=0;i<n;i++) {
		p[i].waitTime=p[i].startTime-p[i].arrivalTime;
		p[i].turnTime=p[i].endTime-p[i].arrivalTime;
	}
	for(i=0;i<n;i++) {
		totturn=totturn+p[i].turnTime;
		totwait=totwait+p[i].waitTime;
	}

	printf("Process is:\n");
	printf("Process\tAT\tBT\tWT\tTT\n");
	for(i=0;i<n;i++) {
		printf("P%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].arrivalTime,p[i].brusTime,p[i].waitTime,p[i].turnTime);
	}
	printf("Avg Wait=%f\nAvg Turn=%f\n",(float)totwait/(float)n,(float)totturn/(float)n);
}