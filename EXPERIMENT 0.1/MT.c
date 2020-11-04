//Program to Transpose a Given Matrix


 #include<stdio.h>
 
 int main()
 {
 	int a[10][10],m,n,i,j,Trams[10][10];
 	
 	printf("Enter the Number of Rows and Coloums of the Matrix\n");
 	scanf("%d%d",&m,&n);
 	
 	printf("Enter the ELEMENTS of the Matrix\n");
 	for(i=0;i<n;i++)
 	{
 		for(j=0;j<n;j++)
 		{
 			scanf("%d",&a[i][j]);
		 }
	 }
	 
	 
	 
	 for(i=0;i<n;i++)
 	{
 		for(j=0;j<n;j++)
 		{
 			Trams[j][i]=a[i][j];
		 }
	 }
	 
	 
	printf("\n\nMatrix Before Transpose:\n");
	for(i=0;i<n;i++)
 	{
 		for(j=0;j<n;j++)
 		{
 			printf("%d ",a[i][j]);
		 }
		printf("\n");
	 }
 	
	
	printf("\n\nMatrix after Transpose:\n");
	for(i=0;i<n;i++)
 	{
 		for(j=0;j<n;j++)
 		{
 			printf("%d ",Trams[i][j]);
		 }
		printf("\n");
	 }
 	
 	
 	
 	return 0;
 }
