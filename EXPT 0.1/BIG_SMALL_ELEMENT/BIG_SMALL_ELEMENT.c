 //Program to Find the Smallest and Biggest Element in a Array
 
 #include<stdio.h>
 
 void main()
 {
 	int a[50],n,i,big,small;
 	printf("Enter the Size of the array\n");
 	scanf("%d",&n);
 	printf("Enter the Elements of the Array\n");
 
 	for(i=0;i<n;i++)
 	{
 		scanf("%d",&a[i]);
	 }
	small=big=a[1];
	for(i=0;i<n;i++)
	{
		if(a[i]>big)
			big=a[i];
	else if(a[i]<small)
			small=a[i];
	 }
	printf("THE BIGGEST ELEMENT=%d\n",big);
	printf("THE SMALLEST ELEMENT=%d\n",small); 
	 
	 
}
	  
