//Program to Add two Matrix

 #include<stdio.h>
 
 int main()
 {
 	int a[10][10],b[10][10],sum[10][10],i,j,m,n,p,q;
 	
 	printf("Enter the Number of Rows and Coloum of First matrix\n");
 	scanf("%d%d",&m,&n);
 	printf("Enter the Elemnets of the MAtrix\n");
 	for(i=0;i<m;i++)
 	{
 		for(j=0;j<n;j++)
 		{
 			scanf("%d",&a[i][j]);
		 }
	 }
 	
 	
 	printf("Enter the Number of Rows and Coloum of Second Matrix\n");
 	scanf("%d%d",&p,&q);
 	printf("Enter the Elemnets of the Matrix\n");
 	for(i=0;i<p;i++)
 	{
 		for(j=0;j<q;j++)
 		{
 			scanf("%d",&b[i][j]);
		 }
	 }
	 
	 
	 
	if((m==p)&&(n==q))
	{
		for(i=0;i<m;i++)
		{
			for(j=0;j<n;j++)
			{
				sum[i][j] = a[i][j] + b[i][j];
			}
		}
		
		printf("The Final Matrix after Addition:\n");
		for(i=0;i<p;i++)
    	{
 			for(j=0;j<q;j++)
 			{
 				printf("%d ", sum[i][j]);
			 }
			printf("\n");
	 	}	
	}
	else
	{
		printf("THE ROWS AND COLUMNS ARE NOT SAME:: THEREFORE CANT BE ADDED\n");
	}
 	
 	
 	return 0;
 }
