/*Program using structures to accept the details of n students with fields 
such as student id, name, branch and age.
Print the details of the students having age greater than 20.*/


 #include<stdio.h>
 
 typedef struct student
 {
 	int stdID,age;
 	char branch[20],name[20];
 }std;
 
 int main()
 {
 	std a[100];
 	int n,i,sum=0;
 	printf("Enter the Number of Students:");
 	scanf("%d", &n);
 	
 	for(i=0;i<n;i++)
 	{
 		printf("Enter the name of the student:");
 		scanf("%s",&a[i].name);
 		printf("Enter the STUDENT-ID:");
 		scanf("%d",&a[i].stdID);
 		printf("Enter the Branch:");
 		scanf("%s",&a[i].branch);
 		printf("Enter the AGE:");
 		scanf("%d",&a[i].age);
	 }
	 
	for(i=0;i<n;i++)
	{
		if(a[i].age>=20)
			sum=sum+1;
	}
	 
	printf("\n\nThere are %d students above AGE 20\n\n",sum);
	if(sum>0)
	{
	printf("NAME\t\tSTUDENTID\t\tBRANCH\t\tAGE\n");
	for(i=0;i<n;i++)
	{
		if(a[i].age>=20)
		{
				printf("%s\t\t%d\t\t%s\t\t%d\n",a[i].name,a[i].stdID,a[i].branch,a[i].age);
		}
	 } 
	
	}
	else
	{
		printf("There r No students below the age Group 20\n");
	}
	
	return 0;
 }
 
 
 
 
