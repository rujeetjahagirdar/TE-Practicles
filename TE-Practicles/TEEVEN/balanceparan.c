#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int top=-1;
char stack[100];
char c;
bool valid=true;

void show() {
    int i;
    for(i=0;i<top+1;i++)
        printf("%c  ",stack[i]);
    printf("\n");
}

void push(char c,char stack[]) {
	if(top==99)
		printf("Stack if Full\n");
	else {
		top++;
		stack[top]=c;
		printf("pushed\n");
		show();
	}
}

void pop() {
	if(top==-1)
		printf("Stack is empty\n");
	else {
		top--;
		printf("poped\n");
	}
}

bool isStackEmpty(char stack []) {
	if(top==-1)
		return true;
	return false;
}

void main() {
	FILE *f1;
	f1=fopen("input.c","r");
	if(f1==NULL)
		printf("Error opening file\n");
	else {
		while((c=getc(f1))!=EOF) {
			if((c==')'||c=='}'||c==']'||c=='>')&& isStackEmpty(stack)==true)
				valid=false;
			if(valid==true) {
				if(c=='('||c=='{'||c=='['||c=='<')
					push(c,stack);
				else if(c==')' && stack[top]=='(') {
					pop();
					valid=true;
				}
				else if(c=='}' && stack[top]=='{') {
					pop();
					valid=true;
				}
				else if(c==']' && stack[top]=='[') {
					pop();
					valid=true;
				}
				else if(c=='>' && stack[top]=='<') {
					pop();
					valid=true;
				}
			}
		}
	if(valid==true && isStackEmpty(stack)==true)
		printf("No Error\n");
	else
		printf("Error\n");
	}
}