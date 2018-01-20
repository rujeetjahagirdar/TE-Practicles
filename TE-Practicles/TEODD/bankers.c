#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void main () {
	int n,m,i,j,k;
	char answer;
	printf("Enter the number of processes:\n");
	scanf("%d",&n);
	printf("Enter the number of resources:\n");
	scanf("%d",&m);

	struct process {
		int pid,allocation[m],need[m],max[m];
		bool finish;
	};

	struct process p[n];
	int work[m];
	int available[m];
	int exeQueue[n];
	int exeCounter=0;
	bool exeCompleted;

	for(i=0;i<n;i++) {
		p[i].pid=i;
		printf("Enter allocation:\n");
		for(j=0;j<m;j++)
			scanf("%d",&p[i].allocation[j]);
	}

	for(i=0;i<n;i++) {
		printf("Enter max:\n");
		for(j=0;j<m;j++)
			scanf("%d",&p[i].max[j]);
	}

	printf("Enter available:\n");
	for(j=0;j<m;j++)
		scanf("%d",&available[j]);

	for(i=0;i<n;i++) {
		for(j=0;j<m;j++) {
			p[i].need[j]=p[i].max[j]-p[i].allocation[j];
		}
	}

	
	void printer() {
		printf("Process\tAllocation\tMax\tNeed\n");
		for(i=0;i<n;i++) {
			printf("P%d\t",i);
			for(j=0;j<m;j++) {
				printf("%d ",p[i].allocation[j]);
			}
			printf("\t");
			for(j=0;j<m;j++) {
				printf("%d ",p[i].max[j]);
			}
			printf("\t");
			for(j=0;j<m;j++) {
				printf("%d ",p[i].need[j]);
			}
			printf("\n");
		}
		printf("Available:\n");
		for(j=0;j<m;j++)
			printf("%d ",available[j]);
		printf("\n");
	}


	bool isNeedLess(struct process temp) {
		for(j=0;j<m;j++) {
			if(temp.need[j]>work[j])
				return false;
		}
		return true;
	}

	void safe() {
		for(j=0;j<m;j++) {
			work[j]=available[j];
		}

		for(i=0;i<n;i++)
			p[i].finish==false;

		for(k=0;k<n;k++) {
			for(i=0;i<n;i++) {
				if(p[i].finish==false && isNeedLess(p[i])==true) {
					p[i].finish=true;
					for(j=0;j<m;j++) {
						work[j]=work[j]+p[i].allocation[j];
					}
					exeQueue[exeCounter]=p[i].pid;
					exeCounter++;
				}	
			}
		}

		exeCompleted=true;
		for(i=0;i<n;i++) {
			if(p[i].finish==false) {
				exeCompleted=false;
			}
		}

		if(exeCompleted==true) {
			printf("Safe sequence is:\n");
			for(exeCounter=0;exeCounter<n;exeCounter++) {
				printf("P%d ",exeQueue[exeCounter]);
			}
			printf("\n");
		}
		else {
			printf("Unsafe\n");
		}
	}


	void request() {
		int n,requestedResource[m],j;
		printf("Enter the pid\n");
		scanf("%d",&n);
		printf("Enter the request\n");
		for(j=0;j<m;j++) {
			scanf("%d",&requestedResource[j]);
		}
		for(j=0;j<m;j++) {
			if(requestedResource[j]>available[j]) {
				printf("Invalid request\n");
				request();
			}
			else {
				for(j=0;j<m;j++) {
					p[n].allocation[j]=p[n].allocation[j]+requestedResource[j];
					available[j]=available[j]-requestedResource[j];
					p[n].need[j]=p[n].max[j]-p[n].allocation[j];
				}
				printer();
				safe();
			}
		}
	}


	printer();
	safe();

	printf("\nDo you want to request resource(y/n)?\n");
	scanf("%s",&answer);
	if(answer=='y')
		request();
	else
		exit(0);
}
