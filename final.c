#include <stdio.h>
#include <string.h>

struct Student {
    char id[100];
    char name[100];
    int birthdate_day;
    int birthdate_month;
    int birthdate_year;
    float grade_algebra;
    float grade_calculus;
    float grade_basic_programming;
};
int main() {
    int num_students;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);
    struct Student students[num_students];

    for (int i = 0; i < num_students; i++) {
        printf("\nEnter information for student %d:\n", i+1);
        printf("Student ID: ");
        scanf("%s", students[i].id);
        fflush(stdin);
        printf("Full name: ");
        gets(students[i].name);
        printf("Birthdate (DD MM YYYY): ");
        scanf("%d %d %d", &students[i].birthdate_day, &students[i].birthdate_month, &students[i].birthdate_year);
        printf("Overall grade in Algebra: ");
        scanf("%f", &students[i].grade_algebra);
        printf("Overall grade in Calculus: ");
        scanf("%f", &students[i].grade_calculus);
        printf("Overall grade in Basic Programming: ");
        scanf("%f", &students[i].grade_basic_programming);
    }

    printf("\nStudent Information:\n");
    printf("------------------------------------------------------------------------------------------------------\n");
    printf("| %-10s | %-20s | %-10s | %-10s | %-10s | %-20s |\n", "Student ID", "Full Name", "Date of birth", "Algebra", "Calculus", "Basic Programming");
    printf("------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < num_students; i++) {
        printf("| %-10s | %-20s | %d/%d/%d    | %-10.2f | %-10.2f | %-20.2f |\n", students[i].id, students[i].name, students[i].birthdate_day,students[i].birthdate_month,students[i].birthdate_year, students[i].grade_algebra, students[i].grade_calculus, students[i].grade_basic_programming);
    }

    printf("------------------------------------------------------------------------------------------------------\n");
    
    //huy
    char search[100];
    printf("Input a StudentID you want to check: ");
    scanf("%s", &search);
    char* sptr;
    for (int i=0; i<num_students; i++){
        sptr = strstr(search,students[i].id);
        if (sptr != NULL){
            printf("Information about that StudentID:\n| %-10s | %-20s | %d/%d/%d    | %-10.2f | %-10.2f | %-20.2f |\n", students[i].id, students[i].name, students[i].birthdate_day,students[i].birthdate_month,students[i].birthdate_year, students[i].grade_algebra, students[i].grade_calculus, students[i].grade_basic_programming);
            break;
        }
    }
    if (sptr == NULL){
        printf("There is NO INFORMATION about that StudentID");
    }
    return 0;
}