//5. WAP to find the duplicate elements in a LL.

#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
};

struct node* create_list(struct node*start);
void display(struct node *start);
struct node *add(struct node *start, int data);
struct node *duplicate(struct node *start1, struct node *start2);

int main(){
	struct node *start1 = NULL, *start2 = NULL;
	printf("\n-------------------------------------\nCreating List 1:\n");
	start1 = create_list(start1);
	printf("\n-------------------------------------\nEntered List: ");display(start1);
	
	start2 = duplicate(start1,start2);
	printf("\n\n--------------------------------\nList of Duplicate Numbers: \n");display(start2);
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

struct node *duplicate(struct node *start1, struct node *start2){
	struct node *p1, *p2, *p3;	
	p1= start1; p2 = start1->link;
	int flag;
	
	while(p1!=NULL){
		while(p2!=NULL){
			if(p1->info == p2->info && p1->link != p2->link){
				if(start2 == NULL)
					start2 = add(start2, p2->info);	
				else{
					flag=0; p3=start2;
					while(p3!=NULL){
						if(p3->info == p2->info)
							flag=1;
						p3= p3->link;
					}
					if(flag == 0)
						start2 = add(start2, p2->info);	
				}
			}
			p2=p2->link;
		}
		p1=p1->link; 
		p2=start1;
	}
	return start2;
}


