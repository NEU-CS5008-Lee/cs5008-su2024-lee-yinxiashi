/**
 * C Program to read and print the n employee details
 * using structure and dynamic memory allocation
 * 
 * Name:  Yinxia Shi
 * Email: shi.yinx@northeastern.edu
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * structure to hold the details of an employee
 */
typedef struct employee {
    int empId;
    char Name[100];
    char Designation[100];
    char Dept[10];

}employee_t;

/* Read the employee details using scanf*/
void readData(int n, employee_t* s) {
    // Add your code here
    int i;
    for (i = 0; i < n; i++) {
        printf("\nEnter the employeeID, Name, Designation and Department of Employee %d:\n", i + 1);
        scanf("%d", &(s->empId));
        scanf("%s", s->Name);
        scanf("%s", s->Designation);
        scanf("%s", s->Dept);
        s++;
    }
}

/* Function to print the employee details*/
void display(int n, employee_t* s) {
    // Add your code here
    int i;
    for (i = 0; i < n; i++) {
        printf("\nThe details of the Employee %d:\n", i + 1);
        printf("empId: %d\n", s->empId);
        printf("Name: %s\n", s->Name);
        printf("Designation: %s\n", s->Designation);
        printf("Dept: %s\n", s->Dept);
        s++;
    }
}

/*----------Main Program--------*/
int main() {
    // Main Function to print the employee details
    // Add your code here
    int n;
    printf("\nEnter the number of employees: ");
    scanf("%d", &n);
    employee_t* s = (employee_t*)malloc(n * sizeof(employee_t));
    readData(n, s);
    display(n, s);
}
