#include <stdio.h>
#include <string.h>
#include "suppliers.h"
#include "utils.h"

Supplier supplierList[MAX_SUPPLIERS];
int supplierCount = 0;

int getSupplierCount(void) {
    return supplierCount;
}

void addSupplier(void) {
    if (supplierCount >= MAX_SUPPLIERS) {
        printf("System is full. Cannot add more suppliers.\n");
        return;
    }

    printf("\n--- Add New Supplier ---\n");
    
    supplierList[supplierCount].supplierID = readInt("Enter Supplier ID (1-9999): ", 1, 9999);
    
    readString("Enter Name: ", supplierList[supplierCount].name, 100);
    readString("Enter Email: ", supplierList[supplierCount].email, 100);
    readString("Enter Telephone: ", supplierList[supplierCount].telephone, 20);
    readString("Enter Town: ", supplierList[supplierCount].town, 50);

    supplierCount++;
    printf("Supplier added successfully!\n");
}

void displaySuppliers(void) {
    int i;
    if (supplierCount == 0) {
        printf("\nNo suppliers registered yet.\n");
        return;
    }
    
    printf("\n--- Registered Suppliers ---\n");
    for (i = 0; i < supplierCount; i++) {
        printf("ID: %d | Name: %s | Email: %s | Phone: %s | Town: %s\n",
               supplierList[i].supplierID,
               supplierList[i].name,
               supplierList[i].email,
               supplierList[i].telephone,
               supplierList[i].town);
    }
}

void searchSupplier(void) {
    int choice, searchID, i, found = 0;
    char searchName[100];

    printf("\n--- Search Supplier ---\n");
    printf("1. Search by ID\n2. Search by Name\n");
    choice = readInt("Choice: ", 1, 2);

    if (choice == 1) {
        searchID = readInt("Enter Supplier ID: ", 1, 9999);
        for (i = 0; i < supplierCount; i++) {
            if (supplierList[i].supplierID == searchID) {
                printf("\nFound: %s | %s | %s | %s\n", 
                       supplierList[i].name, supplierList[i].email, 
                       supplierList[i].telephone, supplierList[i].town);
                found = 1;
                break;
            }
        }
    } else if (choice == 2) {
        readString("Enter Supplier Name: ", searchName, 100);
        for (i = 0; i < supplierCount; i++) {
            if (strcmp(supplierList[i].name, searchName) == 0) {
                printf("\nFound: ID %d | %s | %s | %s\n", 
                       supplierList[i].supplierID, supplierList[i].email, 
                       supplierList[i].telephone, supplierList[i].town);
                found = 1;
            }
        }
    }

    if (!found) {
        printf("Supplier not found.\n");
    }
}

void supplierMenu(void) {
    int choice;
    do {
        printf("\n--- SUPPLIER MANAGEMENT ---\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Back to Main Menu\n");
        choice = readInt("Enter your choice: ", 1, 4);

        switch (choice) {
            case 1: addSupplier(); break;
            case 2: displaySuppliers(); break;
            case 3: searchSupplier(); break;
            case 4: break;
        }
    } while (choice != 4);
}
