// Write a program to reverse a string using stack
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
char st[MAX], rev[MAX], stack[MAX];
int top = -1;

void push(char sym);
char pop();
void reverse();

int main(){
	printf("\nEnter String To be Reversed: ");
	scanf("%s", &st);
	printf("\n-----------------------------------\nEntered String: %s",st);
	reverse();
	printf("\n-----------------------------------\nReversed String: %s", rev);
}

void push(char sym){
	if(top == MAX-1){
		printf("\n***** Stack Overflow*****\n");
		return;	
	}
	top= top + 1;
	stack[top] = sym;
}

char pop(){
	char sym;
	if(top == -1){
		printf("\n***** Stack Underflow*****\n");
		exit(1);	
	}
	sym = stack[top];
	top= top - 1;
	return sym;
}

void reverse(){
	int i, p=0;
	char symbol;
	for(i=0; i<strlen(st); i++){
		symbol = st[i];
		push(symbol);
	}
	
	for(i=0; i<strlen(st); i++){
		symbol = pop();
		rev[p] = symbol;
		p++;
	}
}

