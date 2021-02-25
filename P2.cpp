// Write a program for conversion of infix to postfix and evaluation of postfix
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define TAB '\t'
#define BLANK ' '
#define MAX 50
void push(long int symbol);
long int pop();
int isEmpty();
int isFull();
void infix_to_postfix();
long int eval_post();
int instack_priority(char symbol);
int symbol_priority(char symbol);
int white_space(char symbol);
char infix[MAX], postfix[MAX];
long int stack[MAX]; int top;

main(){
	long int value; top = -1;
	printf("\n Enter Infix Expression: ");
	gets(infix);
	infix_to_postfix();
	printf("\n\n Postfix Expression: %s", postfix);
	value = eval_post();
	printf("\n\n Value of Expression: %ld", value);
}

void push(long int symbol){
	if(isFull()){
		printf("\n\n Stack Overflow\n");
		return;	
	}
	top= top + 1;
	stack[top] = symbol;		
}

long int pop(){
	long int symbol;
	if(isEmpty()){
		printf("\n\n Stack Underflow\n");
		exit(1);	
	}
	symbol = stack[top];
	top= top - 1;
	return symbol;
}

int isEmpty(){
	if(top == -1)
		return 1;
	else
		return 0;
}
int isFull(){
	if(top == MAX-1)
		return 1;
	else
		return 0;
}

long int eval_post(){
	unsigned int i;
	long int a,b, temp, result;
	for(i=0; i<strlen(postfix); i++){
		if(postfix[i] <= '9' && postfix[i] >= '0')
			push(postfix[i] - '0');
			
		else{
			a = pop(); b=pop();
			switch(postfix[i]){
				case '+': temp = b + a; break;
				case '-': temp = b - a; break;				
				case '*': temp = b * a; break;
				case '/': temp = b / a; break;
				case '%': temp = b % a; break;
				case '^': temp = pow(b,a); break;
			}
			push(temp);
		}
	}
	result = pop();
	return result;
}

void infix_to_postfix(){
	unsigned int i, p =0;
	char symbol,next;
	for(i=0; i<strlen(infix); i++){
		symbol = infix[i];
		if(!white_space(symbol)){
			switch(symbol){
				case '(': push(symbol);
					 break;
				case ')': while((next=pop()) != '(')
					postfix[p++] = next;
					  break;
		
				case '+': 
				case '-': 				
				case '*': 
				case '/': 
				case '%': 
				case '^': while(!isEmpty() && instack_priority(stack[top]) >= symbol_priority(symbol))
					postfix[p++] = pop();
					push(symbol);
					break;
				
				default: postfix[p++] = symbol;
			}
		}
	}
	while(!isEmpty())
		postfix[p++] = pop();
	postfix[p++] = '\0';
}

int instack_priority(char symbol){
	switch(symbol){
		case '(': return 0;
		case '+': 
		case '-': return 1;
		case '*': 
		case '/': 
		case '%': return 2;
		case '^': return 4;
		default: return 0;
	}
}
int symbol_priority(char symbol){
	switch(symbol){
		case '(': return 0;
		case '+': 
		case '-': return 1;
		case '*': 
		case '/': 
		case '%': return 2;
		case '^': return 3;
		default: return 0;
	}
}

int white_space(char symbol){
	if(symbol == BLANK || symbol == TAB)
		return 1;
	else
		return 0;
}

