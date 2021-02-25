#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *link;
};

struct node* create_list(struct node*start);
void display(struct node *start);
void count(struct node *start);
void search(struct node *start, int data);
struct node *addatbeg(struct node *start, int data);
struct node *addatend(struct node *start, int data);
struct node *addafter(struct node *start, int data, int item);
struct node *addbefore(struct node *start, int data, int item);
struct node *addatpos(struct node *start, int data, int pos);
struct node *del(struct node *start, int data);
struct node *reverse(struct node *start);

int main(){
	struct node *start = NULL;
	int ch, data, item, pos;
	while(1){
		printf("\n-----------------------------------------");
		printf("\n1. Create List \n2. Display List \n3. Count No. Of Nodes \n4. Search For An element \n5. Insert After a node \n6. Insert before a node \n7. Insert at a given position \n8. Delete A node \n9. Reverse The List \n10. Quit");
		printf("\nEnter Choice: ");
		scanf("%d",&ch);
		printf("\n-----------------------------------------");
	
		switch(ch){
			case 1: start = create_list(start);
				break;
					
			case 2: display(start);
				break;
			
			case 3: count(start);
				break;
		
			case 4: printf("\nEnter element to be searched: ");
				scanf("%d",&data);
				search(start, data);
				break;
			
			case 5: printf("\nEnter element to be inserted: ");
				scanf("%d",&data);
				printf("\nEnter element after which you want the above element placed: ");				scanf("%d",&item);
				start = addafter(start, data,item);
				display(start);
				break;
		
			case 6: printf("\nEnter element to be inserted: ");
				scanf("%d",&data);
				printf("\nEnter element before which you want the above element placed: ");
				scanf("%d",&item);
				start = addbefore(start, data,item);
				display(start);
				break;
		
			case 7: printf("\nEnter element to be inserted: ");
				scanf("%d",&data);
				printf("\nEnter position at which you want the above element placed: ");
				scanf("%d",&pos);
				start = addatpos(start, data,pos);
				display(start);
				break;
					
			case 8: printf("\nEnter element to be deleted: ");
				scanf("%d",&data);
				start = del(start, data);
				display(start);
				break;
				
			case 9: start = reverse(start);
				display(start);
				break;
					
			case 10: exit(1);
			
			default: printf("\nWRONG CHOICE");
				 break;
		}
	}
}
struct node *create_list(struct node *start){
	int i,n,data;
	printf("\nEnter number of nodes: ");
	scanf("%d",&n);
	start = NULL;
	if(n==0)
		return start;
	
	printf("\nEnter Element to be inserted: ");
	scanf("%d",&data);
	start = addatbeg(start,data);
	for(i=2; i<=n; i++)
	{
		printf("\nEnter Element to be inserted: ");
		scanf("%d",&data);
		start = addatend(start,data);
	}
	return start;
}

void display(struct node *start){
	struct node *ptr;
	if(start ==NULL)
		printf("\nList is empty");
	else{
		ptr=start;
		printf("\nElements in the list are:\n");
		while(ptr!=NULL){
			printf("%d  ", ptr->info);
			ptr = ptr->link;
		}
	}	
}
void count(struct node *start){
	struct node *ptr; int ctr=0;
	ptr=start;
	while(ptr!=NULL){
		ptr = ptr->link;
		ctr++;
	}
	printf("\nNumber of elements in the list are: %d", ctr);
}
void search(struct node *start, int data){
	int flag =0;
	struct node *ptr =start;
	int pos =1;
	while(ptr!=NULL){
		if(ptr->info == data){
			flag =1;
			printf("\nItem %d found at position %d", data, pos);
		}
		ptr = ptr->link;
		pos++;
	}
	if(flag == 0)
		printf("\nItem %d not found in list", data);
}
struct node *addatbeg(struct node *start, int data){
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp ->info = data;
	temp->link = start;
	start = temp;
	return start;
}

struct node *addatend(struct node *start, int data){
	struct node *temp, *p;
	temp = (struct node*)malloc(sizeof(struct node));
	temp ->info = data;
	p = start;
	while(p->link!= NULL)
		p = p->link;
	
	p->link = temp;
	temp->link = NULL;
	return start;
}

struct node *addafter(struct node *start, int data, int item){
	struct node *temp, *p;
	p = start;
	while(p!=NULL){
		if(p->info == item){
			temp = (struct node*)malloc(sizeof(struct node));
			temp ->info = data;
			temp->link = p->link;
			p->link = temp;
			return start;
		}
		p = p->link;
	}
	printf("\nItem %d was not found in the list", item);
	return start;
}
struct node *addbefore(struct node *start, int data, int item){
	struct node *temp, *p;
	if(start == NULL){
		printf("\nList is empty");
		return start;
	}
	if(start->info == item){
		temp = (struct node*)malloc(sizeof(struct node));
		temp ->info = data;
		temp->link = start;
		start = temp;
		return start;
	}
	p = start;
	while(p->link != NULL){
		if(p->link->info == item){
			temp = (struct node*)malloc(sizeof(struct node));
			temp ->info = data;
			temp->link = p->link;
			p->link = temp;
			return start;
		}
		p = p->link;
	}
	printf("\nItem %d was not found in the list", item);
	return start;
}

struct node *addatpos(struct node *start, int data, int pos){
	struct node *temp, *p;
	int i;
	temp = (struct node*)malloc(sizeof(struct node));
	temp ->info = data;
	if(pos == 1){
		temp->link = start;
		start = temp;
		return start;
	}
	p = start;
	for(i=1; i<pos-1 && p!=NULL; i++)
		p = p->link;
	if(p==NULL)
		printf("\nThere are less than %d elements  in the list", pos);
	else{
		temp->link = p->link;
		p->link = temp;
	}
	return start;
}

struct node *del(struct node *start, int data){
	struct node *temp, *p;
	temp = (struct node*)malloc(sizeof(struct node));
	if(start == NULL){
		printf("\n List is Empty");
		return start;
	}
	if(start->info == data){
		temp = start;
	 start = start->link;
		free(temp);
		return start;
	}
	p = start;
	while(p->link != NULL){
		if(p->link->info == data)
		{
			temp = p->link;
			p->link = temp->link;
			free(temp);
			return start;
		}
		p = p->link;
	}	
}

struct node *reverse(struct node *start){
	struct node *prev, *next, *ptr;
	prev = NULL;
	ptr = start;
	while(ptr!= NULL){
		next = ptr->link;
		ptr->link = prev;
		prev = ptr;
		ptr = next;
	}
	start = prev;
	return start;
}

