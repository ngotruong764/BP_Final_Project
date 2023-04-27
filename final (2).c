#include <stdio.h>
#include <string.h>
//Struct of students
struct Student {
    char id[100];
    char name[100];
    int birthdate_day;
    int birthdate_month;
    int birthdate_year;
    float grade_algebra;
    float grade_calculus;
    float grade_basic_programming;
    float GPA;
};
//Input information (Task 3)
void input_information(int num_students, struct Student *students) {
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
        students[i].GPA = (students[i].grade_algebra + students[i].grade_calculus + students[i].grade_basic_programming) / 3;
    }
    
    printf("\nStudent Information:\n");
    printf("------------------------------------------------------------------------------------------------------\n");
    printf("| %-10s | %-20s | %-10s | %-10s | %-10s | %-20s | %-10s |\n", "Student ID", "Full Name", "Date of birth", "Algebra", "Calculus", "Basic Programming","GPA");
    printf("------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < num_students; i++) {
        printf("| %-10s | %-20s |  %02d/%02d/%02d   | %-10.2f | %-10.2f | %-20.2f | %-10.2f |\n", students[i].id, students[i].name, students[i].birthdate_day, students[i].birthdate_month, students[i].birthdate_year, students[i].grade_algebra, students[i].grade_calculus, students[i].grade_basic_programming, students[i].GPA);
    }

    printf("------------------------------------------------------------------------------------------------------\n");

}
//Search info(Task 9)
void search_info(int num_students,struct Student *students){
    char search[100];
    printf("Input a StudentID you want to check: ");
    scanf("%s", search);
    char* sptr;
    for (int i=0; i<num_students; i++){
        sptr = strstr(search,students[i].id);
        if (sptr != NULL){
            printf("\nStudent Information:\n");
            printf("------------------------------------------------------------------------------------------------------\n");
            printf("| %-10s | %-20s | %-10s | %-10s | %-10s | %-20s |\n", "Student ID", "Full Name", "Date of birth", "Algebra", "Calculus", "Basic Programming");
            printf("------------------------------------------------------------------------------------------------------\n");
            printf("| %-10s | %-20s | %d/%d/%d    | %-10.2f | %-10.2f | %-20.2f |\n", students[i].id, students[i].name, students[i].birthdate_day,students[i].birthdate_month,students[i].birthdate_year, students[i].grade_algebra, students[i].grade_calculus, students[i].grade_basic_programming);
            printf("------------------------------------------------------------------------------------------------------\n");
            break;
        }
    }
    if (sptr == NULL){
        printf("There is NO INFORMATION about that StudentID");
    }
}

int main() {
    int num_students;
    printf("Enter the number of students: ");
    scanf("%d", &num_students);
    struct Student students[num_students];
    input_information(num_students, students);
    search_info(num_students, students);
    return 0;
}
