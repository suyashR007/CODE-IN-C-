//Program to search an Element in Array...

 #include<stdio.h>
 
 int main()
 {
 	int a[100],i,n,srch,pos,target=0;
	
	printf("Enter the size of the Array\n");
	scanf("%d",&n);
	printf("Enter the Elements of the Array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}
	  
	  
	printf("\n\n");
	printf("ENTER THE ELEMENT TO BE SEARCHED\n");
	scanf("%d", &srch);
	
	 for(i=0;i<n;i++)
	 {
	 	if(a[i]==srch)
	 	{
	 		target=1;
	 		pos=i+1;
		}
	}
	printf("\n");
	
	if(target==1)
	{
		printf("The Element found at Postion: %d\n", pos);		
	}
	else
	{
		printf("ELEMENT Not found\n");
	}
 	
 	
 	
 	return 0;
 }
