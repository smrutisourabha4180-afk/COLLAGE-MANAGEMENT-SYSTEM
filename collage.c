#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int roll;
    char name[50];
    char course[50];
    int year;
};

void addStudent() {
    FILE *fp = fopen("students.dat", "ab");
    struct Student s;

    printf("\nEnter Roll No: ");
    scanf("%d", &s.roll);
    getchar();

    printf("Enter Name: ");
    fgets(s.name, 50, stdin);
    s.name[strcspn(s.name, "\n")] = 0;

    printf("Enter Course: ");
    fgets(s.course, 50, stdin);
    s.course[strcspn(s.course, "\n")] = 0;

    printf("Enter Year: ");
    scanf("%d", &s.year);

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);

    printf("\nStudent added successfully!\n");
}

void displayStudents() {
    FILE *fp = fopen("students.dat", "rb");
    struct Student s;

    if (!fp) {
        printf("\nNo records found!\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    while (fread(&s, sizeof(s), 1, fp)) {
        printf("\nRoll No: %d", s.roll);
        printf("\nName   : %s", s.name);
        printf("\nCourse : %s", s.course);
        printf("\nYear   : %d\n", s.year);
        printf("---------------------------\n");
    }

    fclose(fp);
}

void searchStudent() {
    FILE *fp = fopen("students.dat", "rb");
    struct Student s;
    int roll, found = 0;

    if (!fp) {
        printf("\nNo records found!\n");
        return;
    }

    printf("\nEnter Roll No to Search: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll == roll) {
            printf("\nRecord Found!\n");
            printf("Roll No: %d\nName: %s\nCourse: %s\nYear: %d\n",
                   s.roll, s.name, s.course, s.year);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("\nNo student found with Roll No %d\n", roll);

    fclose(fp);
}

void deleteStudent() {
    FILE *fp = fopen("students.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");
    struct Student s;
    int roll, found = 0;

    if (!fp) {
        printf("\nNo records found!\n");
        return;
    }

    printf("\nEnter Roll No to Delete: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(s), 1, fp)) {
        if (s.roll == roll) {
            found = 1;
            continue;
        }
        fwrite(&s, sizeof(s), 1, temp);
    }

    fclose(fp);
    fclose(temp);

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found)
        printf("\nRecord deleted successfully!\n");
    else
        printf("\nNo student found with Roll No %d\n", roll);
}

int main() {
    int choice;

    while (1) {
        printf("\n==== College Management System ====\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: exit(0);
            default: printf("Invalid Choice!\n");
        }
    }
}
