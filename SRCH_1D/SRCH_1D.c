  //Program to search an Element in a 1D Array
 
 #include<stdio.h>
 
 void main()
 {
 	int a[30],i,m,found=0,srch;
 	printf("Enter the Size of the array\n");
 	scanf("%d",&m);
 	printf("Enter the Elements of the Array\n");
 	for(i=0;i<m;i++)
 	{
 		scanf("%d",&a[i]);
	 }
	printf("Enter the Element to be searched\n");
	scanf("%d",&srch);
	for(i=0;i<m;i++)
	 {
	 	if(a[i]==srch){
	 		found=1;
	 		break;
		 }
	 }
	 if(found==0)
	 	printf("Element Doesn't Exist in the Array");
	 else
	 	printf("Elemnt found at position=%d",i+1);
	 
	 
	 
 }
