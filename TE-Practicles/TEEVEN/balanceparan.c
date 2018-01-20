#include<stdio.h>
#include<stdlib.h>
char stack[100];
int top=-1;
push(char c, char stack []) {
    if(top==99)
        printf("Stack is full\n");
    else {    
        top++;
        stack[top]=c;
    }
}

pop() {
    if(top==-1)
        printf("Stack is empty\n");
    else
        top++;
}

show() {
    int i;
    for(i=0;i<top;i++)
        printf("%c  ",stack[i]);
    printf("\n");
}

void main() {
    FILE *f1;
    f1=fopen("input.c","r");
    char ch;
    while((ch=getc(f1))!=EOF) {
        if(ch=='(' || ch=='{' || ch=='<' || ch=='[')
            push(ch,stack);
        else if(ch==')' && stack[top]=='(') 
            pop();
        else if(ch=='}' && stack[top]=='{') 
            pop();
        else if(ch==']' && stack[top]=='[') 
            pop();
        else if(ch=='>' && stack[top]=='<') 
            pop();
        show();
    }
    if(top==-1) {
    printf("No error\n");
    }    
    else
        printf("Error!\n");
}
