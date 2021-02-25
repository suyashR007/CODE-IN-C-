#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int stack_arr[MAX];
int top = -1;
void push(int item);
int pop();
int peek();
void display();

int main(){
	int ch, item;
	while(1){
		printf("\n_-----------------------------------\n1. Push \n2. Pop \n3. Display The Top Element \n4. Display all stack elements \n5. Quit");
		printf("\n\n Enter Your Choice: ");
		scanf("%d", &ch);
	
		switch(ch){
			case 1: printf("\n\n Enter the item to be pushed: ");
				scanf("%d", &item);
				push(item);
				break;
			case 2: item = pop();
				printf("\n\n Popped Item is: %d\n", item);
				break;		
			case 3: printf("\n\n Item At The Top is: %d\n", peek());
				break;
			
			case 4: display();
				break;
			case 5: exit(1);
				break;
					
			default: printf("\n\n Wrong Choice\n");
		}
	}
}

void push(int item){
	if(top == MAX-1){
		printf("\n***** Stack Overflow*****\n");
		return;	
	}
	top= top + 1;
	stack_arr[top] = item;		
}

int pop(){
	int item;
	if(top == -1){
		printf("\n***** Stack Underflow*****\n");
		exit(1);	
	}
	item = stack_arr[top];
	top= top - 1;
	return item;
}

int peek(){
	if(top == -1){
	    printf("\n*****Stack is empty*****\n");
	    exit(1);
	}
	return(stack_arr[top]);
}

void display(){
	if(top == -1){
	    printf("\n*****Stack is empty*****\n");
	    exit(1);
	}
	int i;
	printf("\n\n Stack contains: ");
	for(i =top; i>=0; i--)
	    printf("%d ", stack_arr[i]);
}

