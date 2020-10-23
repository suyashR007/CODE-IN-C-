//Linklist in C(CODE=01)

 #include<stdio.h>
 #include<stdlib.h>
 
 typedef struct node
 {
 	int data;
 	struct node*next;
 }node;
 
 node*createLinkList(int n);
 void displayList(node*head);
 
 
 int main()
 {
 	int n=0;
 	node*HEAD=NULL;
 	printf("\nHow Many Nodes:");
 	scanf("%d", &n);
 	HEAD=createLinkList(n);
 	displayList(HEAD);
 	
 	return 0;
 }
 
 
 
  node*createLinkList(int n)
  {
  	int i=0;
  	node*head=NULL;
  	node*temp=NULL;
  	node*p=NULL;
  	
	for(i=0;i<n;i++)
	{
		temp=(node*)malloc(sizeof(node));
		printf("\nEnter the data for node number %d: ",i+1);
		scanf("%d",&(temp->data));
		temp->next=NULL;
		
		if(head==NULL)
		{
			head=temp;
		}
		else
		{
			p=head;
			while(p->next!=NULL)
				p=p->next;
			p->next=temp;
		}	
	}  	
  	
  	return head;
  }
  
   void displayList(node*head)
   {
   	node*p=head;
   	while(p!=NULL)
   	{
   		printf("%d->",p->data);
   		p=p->next;
	   }
   }
