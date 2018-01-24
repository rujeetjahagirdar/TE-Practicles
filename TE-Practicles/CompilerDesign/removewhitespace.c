#include<stdio.h>
#include<stdlib.h>

void main() {
	FILE *f1;
	int lines=0;
	f1=fopen("input.c","r");
	char ch;
	while((ch=getc(f1))!=EOF) {
		if(ch=='	' || ch==' ' || ch=='\t') 
			;
		else if(ch=='\n')
			lines++;
		else {
			putc(ch,stdout);
		}
	}
	printf("\nNumber of lines= %d\n",lines);
	fclose(f1);
}
	
