/*Program to create Structure with Structure members name, qualification, salary and age.
Accept details of n employees and find the average salary of employees. */
#include<stdio.h>
#include<stdlib.h>
typedef struct employee
{
	char name[20],qualification[20];
	int salary,age;
}employee;


int main()
{
 employee e[100];
 int n,i,sum=0;
 printf("Enter the Number of Employees:");
 scanf("%d",&n);
 
 printf("\nEnter the Respected DATA of the Employee\n");
 for(i=0;i<n;i++)
 {
 	printf("\nEnter the Name of the %d Employee:",i+1);
 	scanf("%s",&e[i].name);
 	printf("Enter the QUALIFICATION of %d Employee:",i+1);
 	scanf("%s",&e[i].qualification);
 	printf("Enter the Age of the %d Employee:",i+1);
 	scanf("%d",&e[i].age);
 	printf("Enter the SALARY of %d Employee:",i+1);
 	scanf("%d",&e[i].salary);
 }
 
 for(i=0;i<n;i++)
{
	sum=sum+e[i].salary;
}
 
printf("\n\nTHE AVG SUM OF SALARY:%d",sum/n);
 

	return 0;
}
