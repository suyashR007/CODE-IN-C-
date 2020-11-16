//Program to Accept the details of N students and Print the details of Low Percentage Student


 #include<stdio.h>
 
 typedef struct student
 {
 	int std_id,age;
 	float percentage;
 }std;
 
 int main()
 {
 	std a[100];
 	int i,n,m,x;
 	printf("Enter the Total Number of students:");
 	scanf("%d",&n);
 	
 	for(i=0;i<n;i++)
 	{
 		printf("\nEnter the Student-ID:");
 		scanf("%d",&a[i].std_id);
 		printf("\nEnter Age of the Student:");
 		scanf("%d",&a[i].age);
 		printf("\nEnter the percentage of the Student:");
 		scanf("%f",&a[i].percentage);
	 }
	 
	for(i=0;i<n;i++)
	{
		if(a[i].percentage<m)
		{
			m=a[i].percentage;
			x=i;
		}	
	}
	
	printf("STUDENT WITH LOWEST PERCENTAGE\nRoll No:%d\t AGE:%d",a[x].std_id,a[x].age);
	
	 
	return 0; 
	
 }
