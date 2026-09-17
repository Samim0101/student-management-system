#include <stdio.h>
typedef struct
{
  int rollnumber;
  char name[50];
  float marks;
} student;

int get_valid_roll()
{
  int roll;
  while (1)
  {
    printf("Enter student roll number: ");
    // 1. Check if scanf faild to read an integer.
    if (scanf("%d", &roll) != 1)
    {
      printf("Invalid roll number. Please enter a valid number! \n");
      // 2. Clear the invalid characters from the input buffer.
      while (getchar() != '\n')
        ;
      // 3. Optional: make sure roll number is positive (>0)
    }
    else if (roll <= 0)
    {
      printf("Roll number must be greater than 0! \n");
    }
    else
    {
      // valid integer entered! Return it.
      return roll;
    }
  }
}

int is_roll_duplicate(student students[], int count, int roll)
{
  for (int i = 0; i < count; i++)
  {
    if (students[i].rollnumber == roll)
    {
      return 1; // 1 = Yes it is a duplicate!
    }
  }
  return 0; // 0 = No duplicate it is unique!
}

void add_student(student students[], int *student_count)
{
  printf(" --- Add Student --- \n");

  if (*student_count >= 100)
  {
    printf("Cannot add student Database is full! \n");
    return;
  }

  int roll;
  while (1)
  {
    roll = get_valid_roll();
    if (is_roll_duplicate(students, *student_count, roll))
    {
      printf("Roll number %d already exists! Please try another.\n", roll);
    }
    else
    {
      break; // Unique! Break out of the loop
    }
  }

  students[*student_count].rollnumber = roll;
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

void save_students(student students[], int student_count)
{
  printf("--- Exite ---\n");

  FILE *file = fopen("students.txt", "w");
  if (file == NULL)
  {
    printf("Error openig file for saving! \n");
    return;
  }
  for (int i = 0; i < student_count; i++)
  {
    fprintf(file, "%d %s %.2f\n", students[i].rollnumber, students[i].name, students[i].marks);
  }
  fclose(file);
  printf("Data saved succesfully to student.txt! \n");
}

void load_students(student students[], int *student_count)
{
  FILE *file = fopen("students.txt", "r");
  if (file == NULL)
  {
    printf("Firts time runnig, no file exists yet. That's totally okay! \n");
    return;
  }
  while (fscanf(file, "%d %s %f", &students[*student_count].rollnumber, students[*student_count].name, &students[*student_count].marks) == 3)
  {
    (*student_count)++;
    if (*student_count >= 100)
    {
      break; // prevent array overflow.
    }
  }
  fclose(file);
  printf("Loaded %d students(s) from database. \n", *student_count);
}

int main()
{
  student students[100];
  int student_count = 0;
  int choice;

  load_students(students, &student_count);

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
      save_students(students, student_count);
      printf("Exiting program. Good bye! \n");
      return 0;
    default:
      printf("Invalid choice. Please try again \n");

      break;
    }
  }

  return 0;
}