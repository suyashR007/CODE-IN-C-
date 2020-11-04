//Program to Find the Smallest and largest Number in an Array...


 #include<stdio.h>
 
 int main()
 {
 	int a[100],i,n,large,small;
 	
 	printf("Enter the Size of the Array\n");
 	scanf("%d",&n);
 	printf("Enter the Elements of the Array\n");
 	for(i=0;i<n;i++)
 	{
 		scanf("%d",&a[i]);
	 }
 	large=a[0];
 	small=a[0];
 	for(i=0;i<n;i++)
  	{
  		if(a[i]>=large)
  		{
  			large=a[i];
		  }
		
		if(a[i]<=small)
		{
			small=a[i];
		}
	  }
	  
	printf("THE LARGEST ELEMENT:%d\nTHE SMALLEST ELEMET:%d\n",large,small);
	return 0;
 }
