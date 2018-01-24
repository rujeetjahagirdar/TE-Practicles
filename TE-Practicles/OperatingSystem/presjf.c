#include<stdio.h>
#include<stdlib.h>
struct process {
	int pid,arrivaTime,brusTime,waitTime,turnTime,remainTime;
	char status;
};

void main() {
	int i,n,t;
	int totwait=0,totturn=0,totTime=0;
	int temp;
	printf("Enter the number of processes:\n");
	scanf("%d",&n);
	struct process p[n];
	printf("Enter arrival time:\n");
	for(i=0;i<n;i++) {
		scanf("%d",&p[i].arrivaTime);
		p[i].pid=i+1;
		p[i].status='N';
		p[i].waitTime=0;
		p[i].turnTime=0;
	}
	printf("Enter the brust time:\n");
	for(i=0;i<n;i++) {
		scanf("%d",&p[i].brusTime);
		totTime=totTime+p[i].brusTime;
		p[i].remainTime=p[i].brusTime;
	}

	for(t=0;t<totTime;t++) {
		for(i=0;i<n;i++) {
			if(p[i].arrivaTime<=t && p[i].remainTime>0) {
				p[i].status='R';
				temp=i;
			}
			if(p[i].remainTime==0)
				p[i].status='E';
		}

		for(i=0;i<n;i++) {
			if(p[i].status=='R'&&(p[i].remainTime<=p[temp].remainTime)) {
				if(p[i].remainTime==p[temp].remainTime) {
					if(p[i].arrivaTime<=p[temp].arrivaTime)
						temp=i;
					else
						temp=temp;
				}
				else
					temp=i;
			}
		}
		p[temp].remainTime--;
		printf("%d ",p[temp].pid);
		printf("\n");
		for(i=0;i<n;i++) {
			if(p[i].status=='R' && i!=temp)
				p[i].waitTime++;
		}
	}

	for(i=0;i<n;i++) {
		p[i].turnTime=p[i].waitTime+p[i].brusTime;
		totwait=totwait+p[i].waitTime;
		totturn=totturn+p[i].turnTime;
	}

	printf("Process\tAT\tBT\tWT\tTT\n");
	for(i=0;i<n;i++) {
		printf("P%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].arrivaTime,p[i].brusTime,p[i].waitTime,p[i].turnTime);
	}



}