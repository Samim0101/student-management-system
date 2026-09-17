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
  printf("--- All Students --- \n");
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

void search_student(student students[], int student_count)
{
  printf("--- Search Student --- \n");

  if (student_count == 0)
  {
    printf("No students in Database to search! \n");
    return;
  }

  int search_roll;
  printf("Enter roll number to search: ");
  scanf("%d", &search_roll);
  int found = 0;
  for (int i = 0; i < student_count; i++)
  {
    if (students[i].rollnumber == search_roll)
    {
      printf("--- Student Found --- \n");
      printf("Roll number: %d | Name: %s | Marks: %.2f\n", students[i].rollnumber, students[i].name, students[i].marks);
      found = 1;
      break;
    }
  }
  if (!found)
  {
    printf("Student with roll number %d not found! \n", search_roll);
  }
}

void update_student(student students[], int student_count)
{
  printf("--- Update Student ---\n");

  if (student_count == 0)
  {
    printf("No students in Database to search! \n");
    return;
  }
  int roll_to_update;
  int found = 0;
  printf("Enter your roll to update: ");
  scanf("%d", &roll_to_update);

  for (int i = 0; i < student_count; i++)
  {
    if (students[i].rollnumber == roll_to_update)
    {
      printf("Enter new Name: ");
      scanf("%s", students[i].name);

      printf("Enter new Marks: ");
      scanf("%f", &students[i].marks);

      printf("Student details updated successfully! \n");
      found = 1;
      break;
    }
  }
  if (!found)
  {
    printf("No student with that roll number was found. \n");
  }
}

void delete_student(student students[], int *student_count)
{
  printf("--- Delete Student ---\n");

  if (*student_count == 0)
  {
    printf("No student in Database! \n");
    return;
  }
  int roll_to_delete;
  int found_index = -1;
  printf("Enter roll number to delete: ");
  scanf("%d", &roll_to_delete);

  for (int i = 0; i < *student_count; i++)
  {
    if (students[i].rollnumber == roll_to_delete)
    {
      found_index = i;
      break;
    }
  }
  if (found_index == -1)
  {
    printf("student not found! \n");
    return;
  }
  for (int j = found_index; j < *student_count - 1; j++)
  {
    students[j] = students[j + 1];
  }
  (*student_count)--;
  printf("Student deleted successfully! \n");
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

      view_students(students, student_count);
      break;
    case 3:
      search_student(students, student_count);
      break;

    case 4:
      update_student(students, student_count);
      break;
    case 5:
      delete_student(students, &student_count);
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