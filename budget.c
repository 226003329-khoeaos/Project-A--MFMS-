#include <stdio.h>
#include "budget.h"

#define NUM_DEPARTMENTS 5

char departments[NUM_DEPARTMENTS][30] = {
    "IT",
    "Human Resources",
    "Marketing",
    "Finance",
    "Maintenance"
};

float budgets[NUM_DEPARTMENTS] = {0};
float expenditures[NUM_DEPARTMENTS] = {0};

void enterFinances(void)
{
    int choice;
    int index;
    float remainingBudget;

    printf("\n--- SELECT DEPARTMENT ---\n");
    printf("1. IT\n");
    printf("2. Human Resources\n");
    printf("3. Marketing\n");
    printf("4. Finance\n");
    printf("5. Maintenance\n");

    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 5)
    {
        printf("Invalid department.\n");
        return;
    }

    index = choice - 1;

    printf("\nDepartment: %s\n", departments[index]);

    printf("Enter Allocated Budget: N$");
    scanf("%f", &budgets[index]);

    while (budgets[index] < 1000)
    {
        printf("Budget must be at least N$1000.\n");
        printf("Enter Allocated Budget: N$");
        scanf("%f", &budgets[index]);
    }

    printf("Enter Expenditure: N$");
    scanf("%f", &expenditures[index]);

    while (expenditures[index] < 0)
    {
        printf("Expenditure cannot be negative.\n");
        printf("Enter Expenditure: N$");
        scanf("%f", &expenditures[index]);
    }

    remainingBudget = budgets[index] - expenditures[index];

    printf("\n--- BUDGET INFORMATION ---\n");
    printf("Department: %s\n", departments[index]);
    printf("Allocated Budget: N$%.2f\n", budgets[index]);
    printf("Expenditure: N$%.2f\n", expenditures[index]);
    printf("Remaining Budget: N$%.2f\n", remainingBudget);

    if (remainingBudget >= 0)
    {
        printf("Status: WITHIN BUDGET\n");
    }
    else
    {
        printf("Status: BUDGET EXCEEDED\n");
    }

    printf("Department finances saved.\n");
}

void displayDepartments(void)
{
    float remainingBudget;
    int i;

    printf("\n--- ALL DEPARTMENT BUDGETS ---\n");

    for (i = 0; i < NUM_DEPARTMENTS; i++)
    {
        printf("\nDepartment: %s\n", departments[i]);

        if (budgets[i] == 0)
        {
            printf("Budget information not entered yet.\n");
        }
        else
        {
            remainingBudget = budgets[i] - expenditures[i];

            printf("Allocated Budget: N$%.2f\n", budgets[i]);
            printf("Expenditure: N$%.2f\n", expenditures[i]);
            printf("Remaining Budget: N$%.2f\n", remainingBudget);

            if (remainingBudget >= 0)
            {
                printf("Status: WITHIN BUDGET\n");
            }
            else
            {
                printf("Status: BUDGET EXCEEDED\n");
            }
        }
    }
}

void displayExceededDepartments(void)
{
    int i;
    int found = 0;
    float amountExceeded;

    printf("\n--- DEPARTMENTS OVER BUDGET ---\n");

    for (i = 0; i < NUM_DEPARTMENTS; i++)
    {
        if (budgets[i] > 0 && expenditures[i] > budgets[i])
        {
            amountExceeded = expenditures[i] - budgets[i];

            printf("\nDepartment: %s\n", departments[i]);
            printf("Allocated Budget: N$%.2f\n", budgets[i]);
            printf("Expenditure: N$%.2f\n", expenditures[i]);
            printf("Amount Exceeded: N$%.2f\n", amountExceeded);

            found = 1;
        }
    }

    if (found == 0)
    {
        printf("No departments have exceeded their budget.\n");
    }
}

void budgetManagement(void)
{
    int choice;

    do
    {
        printf("\n============================\n");
        printf("     BUDGET MANAGEMENT\n");
        printf("============================\n");
        printf("1. Enter Department Finances\n");
        printf("2. Display All Departments\n");
        printf("3. Display Departments Over Budget\n");
        printf("4. Return to Main Menu\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enterFinances();
                break;

            case 2:
                displayDepartments();
                break;

            case 3:
                displayExceededDepartments();
                break;

            case 4:
                printf("Returning to Main Menu...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 4);
}
