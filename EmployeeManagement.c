#include <stdio.h>
#include <string.h>
#include "EmployeeManagement"

int main(){
    struct Employee employees [MAX_EMPLOYEES];
    int count = 0;
    int choice;

    do {
        printf("\n--- EMPLOYEE MANAGEMENT SYSTEM ----\n");
        printf("1. Add an employee\n");
        printf("2. Display all employees\n");
        printf("3. Search up an Employee\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d" , &choice);

        getchar();

        switch (choice){
            case 1:  
             addEmployee(employees, &count);
             break;
            case 2:
             displayEmployee(employees, count);
             break;
            case 3:
             searchEmployee(employees, count);
             break;
            case 4:
            printf("Exiting the program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");

        }

    } while (choice != 4);

    return 0;
}

void addEmployee(struct Employee emp[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("Cannot add more employees. Maximum limit reached.\n");
        return;
    }


    printf("Enter Employee ID: ");
    scanf("%d", &emp[*count].id);
    getchar(); // Consume newline character

    printf("Enter First Name: ");
    fgets(emp[*count].firstName, sizeof(emp[*count].firstName), stdin);
    emp[*count].firstName[strcspn(emp[*count].firstName, "\n")] = 0; 

    printf("Enter Last Name: ");
    fgets(emp[*count].lastName, sizeof(emp[*count].lastName), stdin);
    emp[*count].lastName[strcspn(emp[*count].lastName, "\n")] = 0; 

    printf("Enter House Phone: ");
    fgets(emp[*count].housePhone, sizeof(emp[*count].housePhone), stdin);
    emp[*count].housePhone[strcspn(emp[*count].housePhone, "\n")] = 0; 

    printf("Enter Department: ");
    fgets(emp[*count].department, sizeof(emp[*count].department), stdin);
    emp[*count].department[strcspn(emp[*count].department, "\n")] = 0; 

    printf("Enter House Address: ");
    fgets(emp[*count].houseAddress, sizeof(emp[*count].houseAddress), stdin);
    emp[*count].houseAddress[strcspn(emp[*count].houseAddress, "\n")] = 0; 

    printf("Enter Email Address: ");
    fgets(emp[*count].emailAddress, sizeof(emp[*count].emailAddress), stdin);
    emp[*count].emailAddress[strcspn(emp[*count].emailAddress, "\n")] = 0; 

    printf("Enter Age: ");
    scanf("%d", &emp[*count].age);
    getchar(); 

    printf("Enter Date of Birth (DD/MM/YYYY): ");
    fgets(emp[*count].dob, sizeof(emp[*count].dob), stdin);
    emp[*count].dob[strcspn(emp[*count].dob, "\n")] = 0; 

    printf("Enter Basic Salary: ");
    scanf("%f", &emp[*count].basicSalary);

    printf("Enter Housing Allowance: ");
    scanf("%f", &emp[*count].housingAllowance);

    printf("Enter Transport Allowance: ");
    scanf("%f", &emp[*count].transportAllowance);

    calculateSalary(&emp[*count]);

    (*count)++;
    printf("Employee added successfully.\n");
}

void calculateSalary(struct Employee *emp) {
    emp->grossSalary = emp->basicSalary + emp->housingAllowance + emp->transportAllowance;
}

void printEmployeeDetails(struct Employee emp) {
    printf("ID: %d\n", emp.id);
    printf("Full Name: %s %s\n", emp.firstName, emp.lastName);
    printf("Date Of Birth: %s (Age: %d)\n", emp.dob, emp.age);
    printf("Telephone: %s\n", emp.emailAddress);
    printf("Address: %s\n", emp.houseAddress);
    printf("Department: %s\n", emp.department);
    printf("Basic Salary: %.2f\n", emp.basicSalary);
    printf("Housing Allowance: %.2f\n", emp.housingAllowance);
    printf("Transport Allowance: %.2f\n", emp.transportAllowance);
    printf("Gross Salary: %.2f\n", emp.grossSalary);
    printf("------------------------------\n");

}

void displayEmployee(struct Employee emp[], int count) {
    if (count == 0) {
        printf("No  records found.\n");
        return;
    }
    printf("\n---- Employee List ----\n");
    for (int i = 0; i < count; i++){
        printEmployeeDetails(emp[i]);
    }
}

void searchEmployee(struct Employee emp[], int count) {
    int searchid, found = 0;
    printf("Enter Employee ID to search: ");
    scanf("%d", &searchid);

    for (int i = 0; i < count; i++) {
        if (emp[i].id == searchid) {
            printf("\n--- Employee Found ---\n");
            printEmployeeDetails(emp[i]);
            printEmployeeDetails(emp[i]);
            found =  1;
            break;
        }
    }
    if (!found){
    printf("Employee with ID %d not found.\n", searchid);
   }
}
