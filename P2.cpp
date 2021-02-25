#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
};

struct node* create_list(struct node*start);
void display(struct node *start);
struct node *add(struct node *start, int data);
struct node *common(struct node *start1, struct node *start2, struct node *start3);

int main()
{
	struct node *start1 = NULL, *start2 = NULL, *start3 = NULL;
	printf("\n-------------------------------------\nCreating List 1:\n");
	start1 = create_list(start1);
	printf("\n-------------------------------------\nCreating List 2:\n");
	start2 = create_list(start2);
	
	printf("\n-------------------------------------\nEntered Lists are:\n\nList1: ");display(start1);
	printf("\nList2: ");display(start2);
	start3 = common(start1,start2,start3);
	printf("\n\n--------------------------------\nList of common elements: \n");display(start3);
}

struct node *create_list(struct node *start){
	int i,n,data;
	printf("\nEnter number of nodes: ");
	scanf("%d",&n);
	start = NULL;
	if(n==0)
		return start;
	
	for(i=1; i<=n; i++){
		printf("\nEnter Element to be inserted: ");
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
		while(ptr!=NULL)
		{
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

struct node *common(struct node *start1, struct node *start2, struct node *start3){
	struct node *p1, *p2;	
	p1= start1; p2 = start2;
	while(p1->link!=NULL){
		while(p2!=NULL){
			if(p1->info == p2->info)
				start3 = add(start3,p1->info);
			p2=p2->link;
		}
		p1=p1->link; p2=start2;
	}
	return start3;
}


