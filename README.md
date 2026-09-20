# student-management-system
A C-based Student Management System for managing student records using file handling and structured programming.


## Features

- Add new student records
- View all students
- Search students by roll number
- Update student information
- Delete student records
- Prevent duplicate roll numbers
- Validate roll numbers and marks
- Store student data in a file
- Load saved student data when the program starts

## Technologies Used

- C — Core programming language
- File Handling — Data persistence using students.- txt
- Structures — Store student information
- Arrays — Manage multiple student records
- Functions — Organize program logic
- Git & GitHub — Version control and project hosting

## How to Run

1. Clone the repository
git clone https://github.com/YOUR-USERNAME/student-management-system.git
cd student-management-system
2. Compile the program
gcc main.c -o student_management
3. Run the program

Linux / macOS:

./student_management

Windows:

student_management.exe

Make sure GCC is installed and available in your system PATH.

## Project Structure

```text
student-management-system/
│
├── main.c
├── students.txt
└── README.md
```

* `main.c` — Main source code of the Student Management System
* `students.txt` — Stores student records for data persistence
* `README.md` — Project documentation

## Example Output

```text
========================================
       STUDENT MANAGEMENT SYSTEM
========================================
1. Add Student
2. View All Student
3. Search Student
4. Update Student
5. Delete Student
6. Exit

--- Add Student ---
Enter student roll number: 101
Enter student name: Samim Raza
Enter student marks (0 - 100): 85
Student added successfully!
```

## Future Improvements

* Add sorting students by roll number, name, or marks
* Add student grades and percentage calculation
* Improve the user interface
* Add stronger file validation and error handling
* Add support for larger student databases
* Add more advanced search and filtering options
