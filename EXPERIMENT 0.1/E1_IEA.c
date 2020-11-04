//program to Insert an ELEMENT in a an Array....

 #include<stdio.h>
 
 int main()
 {
 	int a[100],n,i,pos,target,temp;
 	printf("Enter the SIZE of the array\n");
 	scanf("%d", &n);
 	
 	printf("Enter the ELEMENTS of the Array\n");
 	for(i=0;i<n;i++)
 	{
 		scanf("%d", &a[i]);
     }
	 
	 
	 printf("\n\nEnter the Postion and Element\n");
	 scanf("%d\n%d", &pos, &target);
	 
	  for(i=n;i>=pos-1;i--)
	  {
	  	a[i+1]=a[i];
	  }
	
	a[pos-1]=target;
 	
 	printf("FINAL Array after Insertion element in an Array\n");
 		for(i=0;i<=n;i++)
     	{
 		printf("%d ",a[i]);
         }
 
 
	return 0;
 }
 
 
 
