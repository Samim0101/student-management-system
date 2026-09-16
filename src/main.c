#include <stdio.h>
typedef struct
{
  int rollnumber;
  char name[50];
  float marks;
} student;


void add_student(student *s)
{
  printf(" --- Add Student --- \n");

  printf("Enter student roll number:  ");
  scanf("%d", &s->rollnumber);
  printf("Enter student name: ");
  scanf("%s", s->name);
  printf("Enter student marks: ");
  scanf("%f", &s->marks);
  printf("Student added succesfully! \n");
} 
int main()
{
  student student1;
  int choice;

  while (1)
  {
    printf("\n========================================\n");
    printf("       STUDENT MANAGEMENT SYSTEM\n");
    printf("========================================\n");
    printf("1. Add Student \n");
    printf("2. View All Student \n");
    printf("3. Search Student \n");
    printf("4. Update Student \n");
    printf("5. Delete Student \n");
    printf("6. Exit \n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      add_student(&student1);
      break;
    case 2:
      printf("View All Student \n");
      break;
    case 3:
      printf("Search Student \n");

      break;
    case 4:
      printf(" Update Student \n");

      break;
    case 5:
      printf("Delete Student \n");

      break;
    case 6:
      printf("Exit \n");

      return 0;
    default:
      printf("Invalid choice. Please try again \n");

      break;
    }
  }

  return 0;
}