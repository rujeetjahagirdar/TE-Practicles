#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

void main () {
	int n,f,i,j=0,k,l;
	int count=0;
	printf("Enter the number of pages:\n");
	scanf("%d",&n);
	int pages[n];
	printf("Enter the pages:\n");
	for(i=0;i<n;i++) {
		scanf("%d",&pages[i]);
	}
	printf("Enter the number of frames:\n");
	scanf("%d",&f);
	int memory[f];
	for(i=0;i<f;i++)
		memory[i]=9999;

	bool exists(int page,int memory[]) {
		for(l=0;l<f;l++) {
			if(memory[l]==page)
				return true;
		}
		return false;
	}

	for(i=0;i<n;i++) {
		if(exists(pages[i],memory)==false) {
			memory[j]=pages[i];
			count++;
			if(j==f-1)
				j=0;
			else
				j++;
		}
		for(k=0;k<f;k++)
			printf("%d ",memory[k]);
		printf("\n");
	}
	printf("Page Faults: %d\n",count);
}