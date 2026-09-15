#include <stdio.h>
typedef struct  
{
  int rollnumber;
  char name[50];
  float marks;
}student;

int main(){
  printf(" STUDENT MANAGEMENT SYSTEM \n");
  student student1;
  printf("Enter student rollnumber:  ");
  scanf("%d",&student1.rollnumber);
  printf("Enter student name: ");
  scanf("%s",student1.name);
  printf("Enter student marks: ");
  scanf("%f",&student1.marks);
  printf("\n--- Student information --- \n");
  printf("Roll number: %d \n",student1.rollnumber);
  printf("Name: %s \n",student1.name);
  printf("Marks: %.2f \n",student1.marks);
  
  
  return 0;
}