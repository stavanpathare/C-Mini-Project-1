#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[20];
    float marks;
};

int main() {
    struct Student s[50];
    int n = 0, choice, i, roll, found;
    float total, avg;

    do {
        printf("\n----- STUDENT MANAGEMENT SYSTEM -----\n");
        printf("1. Add Student Records\n");
        printf("2. Display All Records\n");
        printf("3. Search Student by Roll No\n");
        printf("4. Update Student Record\n");
        printf("5. Delete Student Record\n");
        printf("6. Calculate Average Marks\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

        case 1:   // Add records
            printf("Enter number of students: ");
            scanf("%d", &n);
            for (i = 0; i < n; i++) {
                printf("\nStudent %d\n", i + 1);
                printf("Roll No: ");
                scanf("%d", &s[i].roll);
                printf("Name: ");
                scanf("%s", s[i].name);
                printf("Marks: ");
                scanf("%f", &s[i].marks);
            }
            break;

        case 2:   // Display records
            printf("\nRoll\tName\tMarks\n");
            for (i = 0; i < n; i++) {
                printf("%d\t%s\t%.2f\n", s[i].roll, s[i].name, s[i].marks);
            }
            break;

        case 3:   // Search
            printf("Enter roll number to search: ");
            scanf("%d", &roll);
            found = 0;
            for (i = 0; i < n; i++) {
                if (s[i].roll == roll) {
                    printf("Record Found: %d %s %.2f\n",
                           s[i].roll, s[i].name, s[i].marks);
                    found = 1;
                    break;
                }
            }
            if (!found)
                printf("Record not found!\n");
            break;

        case 4:   // Update
            printf("Enter roll number to update: ");
            scanf("%d", &roll);
            for (i = 0; i < n; i++) {
                if (s[i].roll == roll) {
                    printf("Enter new name: ");
                    scanf("%s", s[i].name);
                    printf("Enter new marks: ");
                    scanf("%f", &s[i].marks);
                    printf("Record updated successfully.\n");
                    break;
                }
            }
            break;

        case 5:   // Delete
            printf("Enter roll number to delete: ");
            scanf("%d", &roll);
            for (i = 0; i < n; i++) {
                if (s[i].roll == roll) {
                    for (int j = i; j < n - 1; j++) {
                        s[j] = s[j + 1];
                    }
                    n--;
                    printf("Record deleted successfully.\n");
                    break;
                }
            }
            break;

        case 6:   // Analytical operation
            total = 0;
            for (i = 0; i < n; i++) {
                total += s[i].marks;
            }
            avg = total / n;
            printf("Average Marks = %.2f\n", avg);
            break;

        case 0:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice!\n");
        }

    } while (choice != 0);

    return 0;
}
