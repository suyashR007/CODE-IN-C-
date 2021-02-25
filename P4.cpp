// Write a Program to check nesting of parentheses using stack
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50

char expn[MAX], stack[MAX];
int top = -1;

void push(char sym);
char pop();
void check();

int main(){
	int ch;
	while(1){
		printf("\n--------------------\n1. Check Expression\n2. Exit ");
		printf("\n\n Enter Your Choice: ");
		scanf("%d", &ch);
	
		switch(ch){
			case 1: printf("\n Enter Expression: ");
				gets(expn);
				gets(expn);
				check();
				break;
			case 2: exit(1);
				break;		
			default: printf("\n\n Wrong Choice\n");
		}	
	}	
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

void check(){
	char temp;
	int i, flag =0;
	for(i=0; i<strlen(expn); i++){
		if(expn[i] == '(' || expn[i] == '{' || expn[i] == '[')
			push(expn[i]);
		
		if(expn[i] == ')' || expn[i] == '}' || expn[i] == ']'){
			if(top == -1)
				flag =1;
			else{
				temp = pop();
				if(expn[i] == ')' && (temp == '{' || temp == '['))
					flag = 1;
				if(expn[i] == '}' && (temp == '(' || temp == '['))
					flag = 1;
				if(expn[i] == ']' && (temp == '(' || temp == '{'))
					flag = 1;
			}
		}
	}
	if(top >= 0)
		flag = 1;
	
	if(flag == 0)
		printf("\n Valid Expression");
	else
		printf("\n Invalid Expression");
}

