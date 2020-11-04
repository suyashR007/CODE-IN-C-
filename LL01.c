//TRY TO MAKE LINKLIST IN C....

 #include<stdio.h>
 #include<stdlib.h>
 
 typedef struct node
 {
 	
 	int data;
 	struct node*next;
 }node;
 
  int main()
 {
 	int n=0;
 	node*head=NULL;
 	printf("\n HOW MANY NODES:");
 	scanf("%d",&n);
 	Head=createll(n);
 	display(head);
 	return 0;
 }
 
 int createll(int n);
 void display(node*head);
 
 
 int createll(int n)
 {
 	int i=0;
 	node*head=NULL;
 	node*temp=NULL;

 	node*p=NULL;
 	
 	for(i=0;i<n;i++)
 	{
 		temp=(node*)malloc(sizeof(node));
 		printf("\nEnter data for %d:",i+1);
 		scanf("%d",&(temp->data));
 		temp->next=NULL;
 		
 		if(head==NULL)
 			head=temp;
 		else
 		{
 			p=head;
 			while(p!=NULL)
 				p=p->next;
 			p->next=NULL;
		 }
	 }
	return head;
 }
 
 void display(node*head)
 {
 	node*p=head;
 	while(p!=NULL)
 	{
 		print("%d->",p->data);
 		p=p->next;
	 }
 }
