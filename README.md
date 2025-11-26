📚 College Management System (C Language)

A simple and beginner-friendly College Management System developed in C using file handling.
This program allows you to add, view, search, and delete student records stored in a binary file.

🚀 Features

➕ Add new student record

📜 Display all student records

🔍 Search a student by Roll Number

❌ Delete a student record

💾 Uses binary file (students.dat) for permanent storage

🧱 Fully menu-driven program

🛠️ Technologies Used

C Programming Language

File Handling (Binary Files)

📂 How It Works

The program stores each student's data as a structure and saves it in a binary file.
When running, the user interacts with a menu to perform operations such as adding, searching, or deleting records.

📌 File Structure
├── students.dat     # Binary file storing student records
├── college.c        # Main program file
└── README.md        # Project documentation

🧑‍🎓 Student Structure
struct Student {
    int roll;
    char name[50];
    char course[50];
    int year;
};

▶️ How to Run

Compile the program

gcc college.c -o college


Run the executable

./college

📸 Output (Sample)
==== College Management System ====
1. Add Student
2. Display All Students
3. Search Student
4. Delete Student
5. Exit
Enter choice:

✅ What’s Unique in This Project

Proper use of binary files for efficient data storage

Clean and modular code using separate functions

Handles newline issues with fgets() and getchar() correctly

Beginner-friendly and easy to extend
