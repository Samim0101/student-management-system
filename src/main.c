#include <stdio.h>
typedef struct
{
  int rollnumber;
  char name[50];
  float marks;
} student;

void add_student(student students[], int *student_count)
{
  printf(" --- Add Student --- \n");

  if (*student_count >= 100)
  {
    printf("Cannot add student Database is full! \n");
    return;
  }

  printf("Enter student roll number:  ");
  scanf("%d", &students[*student_count].rollnumber);
  printf("Enter student name: ");
  scanf("%s", students[*student_count].name);
  printf("Enter student marks: ");
  scanf("%f", &students[*student_count].marks);
  printf("Student added succesfully! \n");
  (*student_count)++;
}

void view_students(student students[], int student_count)
{
  if (student_count == 0)
  {
    printf("No student found!\n");
    return;
  }

  for (int i = 0; i < student_count; i++)
  {
    printf("Roll number: %d | Name: %s | Marks: %.2f\n", students[i].rollnumber, students[i].name, students[i].marks);
  }
}

int main()
{
  student students[100];
  int student_count = 0;
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
      add_student(students, &student_count);
      break;
    case 2:
      printf("--- All Students --- \n");

      view_students(students, student_count);
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