#include <stdio.h>
#include <stdlib.h>
struct student 
{

    char name[100];
    int roll;
    float sub1,sub2,sub3;
    float average;
};
int main()
{
int n;
printf("Enter the number of students\n");
scanf("%d",&n);
if(n<=0)
{
    printf("Invalid input\n");
    return 1;
}
struct student *s=(struct student *) calloc(n,sizeof(struct student));
if(s==NULL)
{
    printf("Failed to allocate memory dynamically\n");
    return 1;
}
struct student temp;
//Taking input of details of students//
for(int i=0;i<n;i++)
{
    printf("Enter details of student %d\n",i+1);
    printf("Name : ");
    scanf(" %[^\n]",s[i].name);
    printf("Roll No : ");
    scanf("%d",&s[i].roll);
    printf("Marks in subject 1 subject 2 and subject 3 respectively(out of 100) : ");
    scanf("%f %f %f",&s[i].sub1,&s[i].sub2,&s[i].sub3);
    s[i].average=(s[i].sub1+s[i].sub2+s[i].sub3)/3.0;

}
//Sorting in descending order using Bubble sort//

for(int i=0;i<n;i++)
{
    for(int j=0;j<n-i-1;j++)
    {
        if(s[j].average<s[j+1].average)
        {
             temp=s[j];
            s[j]=s[j+1];
            s[j+1]=temp;
        }
    }
}
printf("The list of students in descending order on the basis of their average of marks is :\n");
for(int i=0;i<n;i++)

    printf("Name : %s\t Roll No : %d\t Subject 1 : %f\t Subject 2 : %f\t Subject 3 : %f\t Percentage : %f percent\t Rank : %d\n",s[i].name,s[i].roll,s[i].sub1,s[i].sub2,s[i].sub3,s[i].average,i+1);


// Topper details//

printf("The top ranker of the class is\n");
printf("Name : %s\t Roll No : %d\t Percentage : %f\n",s[0].name,s[0].roll,s[0].average);

return 0;
}