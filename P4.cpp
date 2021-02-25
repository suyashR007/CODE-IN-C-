//4. WAP to divide a LL into 2 parts depending on the info part: into ODD LL and EVEN LL and display both the LLs.

#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
};

struct node* create_list(struct node*start);
void display(struct node *start);
struct node *add(struct node *start, int data);
struct node *odd(struct node *start1, struct node *start2);
struct node *even(struct node *start1, struct node *start3);

int main(){
	struct node *start1 = NULL, *start2 = NULL, *start3 = NULL;		
	printf("\n-------------------------------------\nCreating List:\n");
	start1 = create_list(start1);
	printf("\n-------------------------------------\nEntered List: ");display(start1);
	
	start2 = odd(start1,start2);
	printf("\n\n--------------------------------\nList of Odd Numbers: \n");display(start2);
	start3 = even(start1,start3);
	printf("\n\n--------------------------------\nList of Even Numbers: \n");display(start3);
}

struct node *create_list(struct node *start){
	int i,n,data;
	printf("\nEnter number of nodes: ");
	scanf("%d",&n);
	start = NULL;
	if(n==0)
		return start;
	printf("\nEnter Elements:\n");
	for(i=1; i<=n; i++){
		scanf("%d",&data);
		start = add(start,data);
	}
	return start;
}

void display(struct node *start){
	struct node *ptr;
	if(start ==NULL)
		printf("\nList is empty");
	else{
		ptr=start;
		while(ptr!=NULL){
			printf("%d  ", ptr->info);
			ptr = ptr->link;
		}
	}
}

struct node *add(struct node *start, int data){
	struct node *temp, *p;
	temp = (struct node*)malloc(sizeof(struct node));
	temp ->info = data;
	if(start == NULL){
		temp ->info = data;
		temp->link = start;
		start = temp;
		return start;
	}
	p = start;
	while(p->link!= NULL)
		p = p->link;
	
	p->link = temp;
	temp->link = NULL;
	return start;
}

struct node *odd(struct node *start1, struct node *start2){
	struct node *p;	
	p= start1;
	while(p!=NULL){
		if(p->info%2 == 1)
				start2 = add(start2,p->info);
		p=p->link;
	}
	return start2;
}

struct node *even(struct node *start1, struct node *start3){
	struct node *p;	
	p= start1;
	while(p!=NULL){
		if(p->info%2 == 0)
				start3 = add(start3,p->info);
		p=p->link;
	}
	return start3;
}

